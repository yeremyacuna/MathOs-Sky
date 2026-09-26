from __future__ import annotations

import html
import re
from pathlib import Path

from PIL import Image as PILImage
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER, TA_JUSTIFY, TA_LEFT
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle, getSampleStyleSheet
from reportlab.lib.units import cm
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import (
    CondPageBreak,
    HRFlowable,
    Image,
    PageBreak,
    Paragraph,
    SimpleDocTemplate,
    Spacer,
    Table,
    TableStyle,
)
from reportlab.platypus.tableofcontents import TableOfContents


BASE = Path(__file__).resolve().parent
MARKDOWN = BASE / "Arquitectura_Actual_MathOs_Sky.md"
OUTPUT = BASE / "Arquitectura_Actual_MathOs_Sky.pdf"


def register_fonts() -> tuple[str, str]:
    regular = Path("C:/Windows/Fonts/arial.ttf")
    bold = Path("C:/Windows/Fonts/arialbd.ttf")
    if regular.exists() and bold.exists():
        pdfmetrics.registerFont(TTFont("MathOsRegular", str(regular)))
        pdfmetrics.registerFont(TTFont("MathOsBold", str(bold)))
        return "MathOsRegular", "MathOsBold"
    return "Helvetica", "Helvetica-Bold"


FONT, FONT_BOLD = register_fonts()
BLUE = colors.HexColor("#17365D")
ACCENT = colors.HexColor("#2A6FDB")
LIGHT_BLUE = colors.HexColor("#EAF2FB")
LIGHT_GRAY = colors.HexColor("#F4F6F8")
TEXT = colors.HexColor("#25313C")


class ArchitectureDoc(SimpleDocTemplate):
    def afterFlowable(self, flowable):
        if isinstance(flowable, Paragraph):
            style = flowable.style.name
            if style in {"Section", "Subsection"}:
                level = 0 if style == "Section" else 1
                text = flowable.getPlainText()
                key = f"heading-{level}-{self.seq.nextf('heading')}"
                self.canv.bookmarkPage(key)
                self.canv.addOutlineEntry(text, key, level=level, closed=False)
                self.notify("TOCEntry", (level, text, self.page, key))


styles = getSampleStyleSheet()
styles.add(ParagraphStyle(
    name="CoverTitle", fontName=FONT_BOLD, fontSize=29, leading=34,
    textColor=BLUE, alignment=TA_CENTER, spaceAfter=18,
))
styles.add(ParagraphStyle(
    name="CoverSubtitle", fontName=FONT, fontSize=16, leading=21,
    textColor=ACCENT, alignment=TA_CENTER, spaceAfter=10,
))
styles.add(ParagraphStyle(
    name="CoverMeta", fontName=FONT, fontSize=10.5, leading=16,
    textColor=TEXT, alignment=TA_CENTER,
))
styles.add(ParagraphStyle(
    name="Section", fontName=FONT_BOLD, fontSize=17, leading=21,
    textColor=BLUE, spaceBefore=12, spaceAfter=9, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="Subsection", fontName=FONT_BOLD, fontSize=13, leading=16,
    textColor=ACCENT, spaceBefore=9, spaceAfter=6, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="MinorHeading", fontName=FONT_BOLD, fontSize=10.5, leading=14,
    textColor=BLUE, spaceBefore=7, spaceAfter=4, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="BodyMathOs", fontName=FONT, fontSize=9.2, leading=13.2,
    textColor=TEXT, alignment=TA_JUSTIFY, spaceAfter=6,
))
styles.add(ParagraphStyle(
    name="BulletMathOs", parent=styles["BodyMathOs"], leftIndent=14,
    firstLineIndent=-7, bulletIndent=5, spaceAfter=3,
))
styles.add(ParagraphStyle(
    name="CodeMathOs", fontName="Courier", fontSize=8.2, leading=11,
    leftIndent=12, rightIndent=12, backColor=LIGHT_GRAY,
    borderPadding=6, spaceBefore=4, spaceAfter=7,
))
styles.add(ParagraphStyle(
    name="TableCell", fontName=FONT, fontSize=6.5, leading=8.2,
    textColor=TEXT, alignment=TA_LEFT,
))
styles.add(ParagraphStyle(
    name="TableHeader", fontName=FONT_BOLD, fontSize=6.7, leading=8.4,
    textColor=colors.white, alignment=TA_CENTER,
))
styles.add(ParagraphStyle(
    name="Caption", fontName=FONT, fontSize=8, leading=10,
    textColor=colors.HexColor("#52677D"), alignment=TA_CENTER,
    spaceBefore=3, spaceAfter=8,
))


def inline_markup(text: str) -> str:
    safe = html.escape(text.strip())
    safe = re.sub(r"`([^`]+)`", r"<font name='Courier'>\1</font>", safe)
    safe = re.sub(r"\*\*([^*]+)\*\*", r"<b>\1</b>", safe)
    return safe


def make_table(rows: list[list[str]], available_width: float) -> Table:
    columns = len(rows[0])
    if columns == 6:
        ratios = [1.35, 0.75, 1.55, 1.65, 1.35, 1.35]
    elif columns == 2:
        ratios = [1.0, 3.2]
    else:
        ratios = [1.0] * columns
    unit = available_width / sum(ratios)
    widths = [unit * ratio for ratio in ratios]
    formatted = []
    for row_index, row in enumerate(rows):
        style = styles["TableHeader"] if row_index == 0 else styles["TableCell"]
        formatted.append([Paragraph(inline_markup(cell), style) for cell in row])
    table = Table(formatted, colWidths=widths, repeatRows=1, hAlign="LEFT", splitByRow=1)
    table.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, 0), BLUE),
        ("GRID", (0, 0), (-1, -1), 0.35, colors.HexColor("#AAB7C4")),
        ("VALIGN", (0, 0), (-1, -1), "TOP"),
        ("LEFTPADDING", (0, 0), (-1, -1), 4),
        ("RIGHTPADDING", (0, 0), (-1, -1), 4),
        ("TOPPADDING", (0, 0), (-1, -1), 4),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 4),
        ("ROWBACKGROUNDS", (0, 1), (-1, -1), [colors.white, LIGHT_GRAY]),
    ]))
    return table


def add_image(story: list, alt: str, relative: str, available_width: float):
    png = (BASE / relative).with_suffix(".png")
    with PILImage.open(png) as source:
        width, height = source.size
    max_width = available_width
    max_height = 18.5 * cm
    scale = min(max_width / width, max_height / height)
    story.append(CondPageBreak(height * scale + 1.2 * cm))
    story.append(Image(str(png), width=width * scale, height=height * scale, hAlign="CENTER"))
    story.append(Paragraph(html.escape(alt), styles["Caption"]))


def parse_markdown(text: str, available_width: float) -> list:
    lines = text.splitlines()
    start = next(index for index, line in enumerate(lines) if line.startswith("## 1. Alcance actual"))
    lines = lines[start:]
    story: list = []
    index = 0
    paragraph: list[str] = []

    def flush_paragraph():
        if paragraph:
            joined = " ".join(part.strip() for part in paragraph)
            story.append(Paragraph(inline_markup(joined), styles["BodyMathOs"]))
            paragraph.clear()

    while index < len(lines):
        line = lines[index]
        stripped = line.strip()
        if not stripped:
            flush_paragraph()
            index += 1
            continue
        if stripped == "---":
            flush_paragraph()
            story.append(Spacer(1, 4))
            story.append(HRFlowable(width="100%", thickness=0.5, color=colors.HexColor("#B9C5D1")))
            story.append(Spacer(1, 5))
            index += 1
            continue
        if stripped.startswith("## "):
            flush_paragraph()
            story.append(CondPageBreak(4.2 * cm))
            story.append(Paragraph(inline_markup(stripped[3:]), styles["Section"]))
            index += 1
            continue
        if stripped.startswith("### "):
            flush_paragraph()
            if stripped.startswith("### 6."):
                story.append(PageBreak())
            story.append(Paragraph(inline_markup(stripped[4:]), styles["Subsection"]))
            index += 1
            continue
        if stripped.startswith("#### "):
            flush_paragraph()
            story.append(Paragraph(inline_markup(stripped[5:]), styles["MinorHeading"]))
            index += 1
            continue
        image_match = re.match(r"!\[([^]]+)\]\(([^)]+)\)", stripped)
        if image_match:
            flush_paragraph()
            add_image(story, image_match.group(1), image_match.group(2), available_width)
            index += 1
            continue
        if stripped.startswith("| "):
            flush_paragraph()
            table_lines = []
            while index < len(lines) and lines[index].strip().startswith("|"):
                table_lines.append(lines[index].strip())
                index += 1
            rows = []
            for row_index, table_line in enumerate(table_lines):
                cells = [cell.strip() for cell in table_line.strip("|").split("|")]
                if row_index == 1 and all(re.fullmatch(r":?-+:?", cell.replace(" ", "")) for cell in cells):
                    continue
                rows.append(cells)
            story.append(make_table(rows, available_width))
            story.append(Spacer(1, 8))
            continue
        if stripped.startswith("- "):
            flush_paragraph()
            story.append(Paragraph(inline_markup(stripped[2:]), styles["BulletMathOs"], bulletText="•"))
            index += 1
            continue
        if re.match(r"\d+\. ", stripped):
            flush_paragraph()
            number, content = stripped.split(". ", 1)
            story.append(Paragraph(inline_markup(content), styles["BulletMathOs"], bulletText=f"{number}."))
            index += 1
            continue
        if stripped.startswith("```"):
            flush_paragraph()
            index += 1
            code_lines = []
            while index < len(lines) and not lines[index].strip().startswith("```"):
                code_lines.append(lines[index])
                index += 1
            index += 1
            story.append(Paragraph("<br/>".join(html.escape(item) for item in code_lines), styles["CodeMathOs"]))
            continue
        paragraph.append(stripped.rstrip("  "))
        index += 1

    flush_paragraph()
    return story


def decorate_page(canvas, doc):
    canvas.saveState()
    width, height = A4
    if doc.page > 1:
        canvas.setStrokeColor(colors.HexColor("#D6DEE6"))
        canvas.line(2 * cm, height - 1.45 * cm, width - 2 * cm, height - 1.45 * cm)
        canvas.setFont(FONT, 8)
        canvas.setFillColor(colors.HexColor("#5D6B78"))
        canvas.drawString(2 * cm, height - 1.15 * cm, "MathOs-Sky - Arquitectura actual")
        canvas.drawRightString(width - 2 * cm, 1.15 * cm, f"Página {doc.page}")
    canvas.restoreState()


def build_pdf():
    document = ArchitectureDoc(
        str(OUTPUT), pagesize=A4,
        leftMargin=1.8 * cm, rightMargin=1.8 * cm,
        topMargin=1.8 * cm, bottomMargin=1.7 * cm,
        title="MathOs-Sky - Arquitectura actual del núcleo matemático",
        author="Proyecto MathOs-Sky",
    )
    story = [Spacer(1, 4.2 * cm)]
    story.append(Paragraph("MathOs-Sky", styles["CoverTitle"]))
    story.append(HRFlowable(width="55%", thickness=2, color=ACCENT, hAlign="CENTER"))
    story.append(Spacer(1, 18))
    story.append(Paragraph("Arquitectura actual del núcleo matemático", styles["CoverSubtitle"]))
    story.append(Spacer(1, 1.2 * cm))
    story.append(Paragraph("Proyecto de Matemática Computacional", styles["CoverMeta"]))
    story.append(Spacer(1, 12))
    story.append(Paragraph("Estado auditado: commit f40cf0ab4fff9af42328d7255bbc292a1b2f0f33", styles["CoverMeta"]))
    story.append(Paragraph("Fecha de generación: 26 de septiembre de 2026", styles["CoverMeta"]))
    story.append(PageBreak())

    story.append(Paragraph("Índice", styles["Section"]))
    toc = TableOfContents()
    toc.levelStyles = [
        ParagraphStyle(name="TOC0", fontName=FONT_BOLD, fontSize=10, leading=14, leftIndent=0, textColor=BLUE, spaceAfter=4),
        ParagraphStyle(name="TOC1", fontName=FONT, fontSize=8.5, leading=12, leftIndent=14, textColor=TEXT, spaceAfter=2),
    ]
    story.append(toc)
    story.append(PageBreak())
    story.extend(parse_markdown(MARKDOWN.read_text(encoding="utf-8"), document.width))
    document.multiBuild(story, onFirstPage=decorate_page, onLaterPages=decorate_page)


if __name__ == "__main__":
    build_pdf()
