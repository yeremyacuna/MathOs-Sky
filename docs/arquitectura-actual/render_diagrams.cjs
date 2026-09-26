const fs = require("fs");
const path = require("path");
const { instance } = require("@viz-js/viz");
const sharp = require("sharp");

async function main() {
  const directory = path.join(__dirname, "diagramas");
  const viz = await instance();
  const sources = fs.readdirSync(directory).filter((name) => name.endsWith(".dot")).sort();

  for (const source of sources) {
    const input = path.join(directory, source);
    const base = path.join(directory, path.basename(source, ".dot"));
    const dot = fs.readFileSync(input, "utf8");
    const svg = viz.renderString(dot, { format: "svg", engine: "dot" });
    fs.writeFileSync(`${base}.svg`, svg, "utf8");
    await sharp(Buffer.from(svg)).resize({ width: 1800, withoutEnlargement: false }).png().toFile(`${base}.png`);
  }
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
