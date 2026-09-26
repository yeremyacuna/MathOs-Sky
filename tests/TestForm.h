#pragma once
#include <stdexcept>

namespace MathOsSky
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class TestForm : public System::Windows::Forms::Form
    {
    public:
        TestForm(void)
        {
            InitializeComponent();
            inicializarSelecciones();
        }

    protected:
        ~TestForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TableLayoutPanel^ layoutPrincipal;
        System::Windows::Forms::Panel^ panelEncabezado;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblDescripcion;
        System::Windows::Forms::Button^ btnEjecutarTodas;
        System::Windows::Forms::Button^ btnLimpiar;
        System::Windows::Forms::Label^ lblAprobadas;
        System::Windows::Forms::Label^ lblFallidas;
        System::Windows::Forms::TabControl^ tabsPruebas;
        System::Windows::Forms::TabPage^ tabGrafo;
        System::Windows::Forms::TabPage^ tabRutas;
        System::Windows::Forms::TabPage^ tabSolucionador;
        System::Windows::Forms::TabPage^ tabDiagnostico;
        System::Windows::Forms::TabPage^ tabTraza;
        System::Windows::Forms::TableLayoutPanel^ layoutGrafo;
        System::Windows::Forms::FlowLayoutPanel^ accionesGrafo;
        System::Windows::Forms::Button^ btnProbarGrafo;
        System::Windows::Forms::Button^ btnValidacionesGrafo;
        System::Windows::Forms::Label^ lblMetricaGrafo;
        System::Windows::Forms::ComboBox^ cmbMetricaGrafo;
        System::Windows::Forms::SplitContainer^ splitMatrices;
        System::Windows::Forms::DataGridView^ dgvAdyacencia;
        System::Windows::Forms::DataGridView^ dgvPesos;
        System::Windows::Forms::RichTextBox^ txtResultadoGrafo;
        System::Windows::Forms::TableLayoutPanel^ layoutRutas;
        System::Windows::Forms::FlowLayoutPanel^ accionesRutas;
        System::Windows::Forms::Label^ lblNodosRutas;
        System::Windows::Forms::NumericUpDown^ nudNodosRutas;
        System::Windows::Forms::Label^ lblOrigenRutas;
        System::Windows::Forms::NumericUpDown^ nudOrigenRutas;
        System::Windows::Forms::Button^ btnGenerarRutas;
        System::Windows::Forms::Label^ lblConteoRutas;
        System::Windows::Forms::DataGridView^ dgvRutas;
        System::Windows::Forms::RichTextBox^ txtResultadoRutas;
        System::Windows::Forms::TableLayoutPanel^ layoutSolucionador;
        System::Windows::Forms::FlowLayoutPanel^ accionesSolucionador;
        System::Windows::Forms::ComboBox^ cmbEscenarioTSP;
        System::Windows::Forms::NumericUpDown^ nudOrigenTSP;
        System::Windows::Forms::ComboBox^ cmbMetricaTSP;
        System::Windows::Forms::Button^ btnEjecutarTSP;
        System::Windows::Forms::TableLayoutPanel^ resumenSolucionador;
        System::Windows::Forms::Label^ lblCandidatosTSP;
        System::Windows::Forms::Label^ lblValidosTSP;
        System::Windows::Forms::Label^ lblMejorRutaTSP;
        System::Windows::Forms::Label^ lblMejorValorTSP;
        System::Windows::Forms::DataGridView^ dgvTSP;
        System::Windows::Forms::RichTextBox^ txtResultadoTSP;
        System::Windows::Forms::TableLayoutPanel^ layoutDiagnostico;
        System::Windows::Forms::FlowLayoutPanel^ accionesDiagnostico;
        System::Windows::Forms::ComboBox^ cmbEscenarioDiagnostico;
        System::Windows::Forms::NumericUpDown^ nudOrigenDiagnostico;
        System::Windows::Forms::Button^ btnEjecutarDiagnostico;
        System::Windows::Forms::Label^ lblExisteCiclo;
        System::Windows::Forms::Label^ lblRutaSugerida;
        System::Windows::Forms::Label^ lblCantidadFaltantes;
        System::Windows::Forms::DataGridView^ dgvFaltantes;
        System::Windows::Forms::RichTextBox^ txtResultadoDiagnostico;
        System::Windows::Forms::TableLayoutPanel^ layoutTraza;
        System::Windows::Forms::FlowLayoutPanel^ accionesTraza;
        System::Windows::Forms::ComboBox^ cmbEscenarioTraza;
        System::Windows::Forms::ComboBox^ cmbMetricaTraza;
        System::Windows::Forms::Button^ btnEjecutarTraza;
        System::Windows::Forms::Label^ lblRutaTraza;
        System::Windows::Forms::Label^ lblValidezTraza;
        System::Windows::Forms::Label^ lblValorTraza;
        System::Windows::Forms::DataGridView^ dgvTraza;
        System::Windows::Forms::RichTextBox^ txtResultadoTraza;
        int cantidadAprobadas = 0;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn11;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn12;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn13;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn14;
           int cantidadFallidas = 0;
        bool ejecutandoTodas = false;

        void inicializarSelecciones();
        void registrarResultado(System::Windows::Forms::RichTextBox^ area, bool aprobado, System::String^ mensaje);
        void registrarExcepcion(System::Windows::Forms::RichTextBox^ area, System::String^ contexto, const std::exception& error);
        void actualizarContadores();
        void limpiarResultados();
        System::Void btnProbarGrafo_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnValidacionesGrafo_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void nudNodosRutas_ValueChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void btnGenerarRutas_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnEjecutarTSP_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnEjecutarDiagnostico_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnEjecutarTraza_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnEjecutarTodas_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e);

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->layoutPrincipal = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panelEncabezado = (gcnew System::Windows::Forms::Panel());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblDescripcion = (gcnew System::Windows::Forms::Label());
            this->btnEjecutarTodas = (gcnew System::Windows::Forms::Button());
            this->btnLimpiar = (gcnew System::Windows::Forms::Button());
            this->lblAprobadas = (gcnew System::Windows::Forms::Label());
            this->lblFallidas = (gcnew System::Windows::Forms::Label());
            this->tabsPruebas = (gcnew System::Windows::Forms::TabControl());
            this->tabGrafo = (gcnew System::Windows::Forms::TabPage());
            this->layoutGrafo = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->accionesGrafo = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->btnProbarGrafo = (gcnew System::Windows::Forms::Button());
            this->btnValidacionesGrafo = (gcnew System::Windows::Forms::Button());
            this->lblMetricaGrafo = (gcnew System::Windows::Forms::Label());
            this->cmbMetricaGrafo = (gcnew System::Windows::Forms::ComboBox());
            this->splitMatrices = (gcnew System::Windows::Forms::SplitContainer());
            this->dgvAdyacencia = (gcnew System::Windows::Forms::DataGridView());
            this->dgvPesos = (gcnew System::Windows::Forms::DataGridView());
            this->txtResultadoGrafo = (gcnew System::Windows::Forms::RichTextBox());
            this->tabRutas = (gcnew System::Windows::Forms::TabPage());
            this->layoutRutas = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->accionesRutas = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->lblNodosRutas = (gcnew System::Windows::Forms::Label());
            this->nudNodosRutas = (gcnew System::Windows::Forms::NumericUpDown());
            this->lblOrigenRutas = (gcnew System::Windows::Forms::Label());
            this->nudOrigenRutas = (gcnew System::Windows::Forms::NumericUpDown());
            this->btnGenerarRutas = (gcnew System::Windows::Forms::Button());
            this->lblConteoRutas = (gcnew System::Windows::Forms::Label());
            this->dgvRutas = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->txtResultadoRutas = (gcnew System::Windows::Forms::RichTextBox());
            this->tabSolucionador = (gcnew System::Windows::Forms::TabPage());
            this->layoutSolucionador = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->accionesSolucionador = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->cmbEscenarioTSP = (gcnew System::Windows::Forms::ComboBox());
            this->nudOrigenTSP = (gcnew System::Windows::Forms::NumericUpDown());
            this->cmbMetricaTSP = (gcnew System::Windows::Forms::ComboBox());
            this->btnEjecutarTSP = (gcnew System::Windows::Forms::Button());
            this->resumenSolucionador = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->lblCandidatosTSP = (gcnew System::Windows::Forms::Label());
            this->lblValidosTSP = (gcnew System::Windows::Forms::Label());
            this->lblMejorRutaTSP = (gcnew System::Windows::Forms::Label());
            this->lblMejorValorTSP = (gcnew System::Windows::Forms::Label());
            this->dgvTSP = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->txtResultadoTSP = (gcnew System::Windows::Forms::RichTextBox());
            this->tabDiagnostico = (gcnew System::Windows::Forms::TabPage());
            this->layoutDiagnostico = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->accionesDiagnostico = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->cmbEscenarioDiagnostico = (gcnew System::Windows::Forms::ComboBox());
            this->nudOrigenDiagnostico = (gcnew System::Windows::Forms::NumericUpDown());
            this->btnEjecutarDiagnostico = (gcnew System::Windows::Forms::Button());
            this->lblExisteCiclo = (gcnew System::Windows::Forms::Label());
            this->lblRutaSugerida = (gcnew System::Windows::Forms::Label());
            this->lblCantidadFaltantes = (gcnew System::Windows::Forms::Label());
            this->dgvFaltantes = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->txtResultadoDiagnostico = (gcnew System::Windows::Forms::RichTextBox());
            this->tabTraza = (gcnew System::Windows::Forms::TabPage());
            this->layoutTraza = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->accionesTraza = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->cmbEscenarioTraza = (gcnew System::Windows::Forms::ComboBox());
            this->cmbMetricaTraza = (gcnew System::Windows::Forms::ComboBox());
            this->btnEjecutarTraza = (gcnew System::Windows::Forms::Button());
            this->lblRutaTraza = (gcnew System::Windows::Forms::Label());
            this->lblValidezTraza = (gcnew System::Windows::Forms::Label());
            this->lblValorTraza = (gcnew System::Windows::Forms::Label());
            this->dgvTraza = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->txtResultadoTraza = (gcnew System::Windows::Forms::RichTextBox());
            this->layoutPrincipal->SuspendLayout();
            this->panelEncabezado->SuspendLayout();
            this->tabsPruebas->SuspendLayout();
            this->tabGrafo->SuspendLayout();
            this->layoutGrafo->SuspendLayout();
            this->accionesGrafo->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitMatrices))->BeginInit();
            this->splitMatrices->Panel1->SuspendLayout();
            this->splitMatrices->Panel2->SuspendLayout();
            this->splitMatrices->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAdyacencia))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPesos))->BeginInit();
            this->tabRutas->SuspendLayout();
            this->layoutRutas->SuspendLayout();
            this->accionesRutas->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNodosRutas))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenRutas))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRutas))->BeginInit();
            this->tabSolucionador->SuspendLayout();
            this->layoutSolucionador->SuspendLayout();
            this->accionesSolucionador->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenTSP))->BeginInit();
            this->resumenSolucionador->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTSP))->BeginInit();
            this->tabDiagnostico->SuspendLayout();
            this->layoutDiagnostico->SuspendLayout();
            this->accionesDiagnostico->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenDiagnostico))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaltantes))->BeginInit();
            this->tabTraza->SuspendLayout();
            this->layoutTraza->SuspendLayout();
            this->accionesTraza->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTraza))->BeginInit();
            this->SuspendLayout();
            // 
            // layoutPrincipal
            // 
            this->layoutPrincipal->ColumnCount = 1;
            this->layoutPrincipal->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->layoutPrincipal->Controls->Add(this->panelEncabezado, 0, 0);
            this->layoutPrincipal->Controls->Add(this->tabsPruebas, 0, 1);
            this->layoutPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutPrincipal->Location = System::Drawing::Point(0, 0);
            this->layoutPrincipal->Name = L"layoutPrincipal";
            this->layoutPrincipal->RowCount = 2;
            this->layoutPrincipal->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 112)));
            this->layoutPrincipal->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutPrincipal->Size = System::Drawing::Size(1384, 761);
            this->layoutPrincipal->TabIndex = 0;
            // 
            // panelEncabezado
            // 
            this->panelEncabezado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(78)));
            this->panelEncabezado->Controls->Add(this->lblTitulo);
            this->panelEncabezado->Controls->Add(this->lblDescripcion);
            this->panelEncabezado->Controls->Add(this->btnEjecutarTodas);
            this->panelEncabezado->Controls->Add(this->btnLimpiar);
            this->panelEncabezado->Controls->Add(this->lblAprobadas);
            this->panelEncabezado->Controls->Add(this->lblFallidas);
            this->panelEncabezado->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelEncabezado->Location = System::Drawing::Point(0, 0);
            this->panelEncabezado->Margin = System::Windows::Forms::Padding(0);
            this->panelEncabezado->Name = L"panelEncabezado";
            this->panelEncabezado->Size = System::Drawing::Size(1384, 112);
            this->panelEncabezado->TabIndex = 0;
            // 
            // lblTitulo
            // 
            this->lblTitulo->AutoSize = true;
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::White;
            this->lblTitulo->Location = System::Drawing::Point(28, 18);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(549, 37);
            this->lblTitulo->TabIndex = 0;
            this->lblTitulo->Text = L"MathOs-Sky - Core & Algorithms Test Form";
            this->lblTitulo->Click += gcnew System::EventHandler(this, &TestForm::lblTitulo_Click);
            // 
            // lblDescripcion
            // 
            this->lblDescripcion->AutoSize = true;
            this->lblDescripcion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblDescripcion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->lblDescripcion->Location = System::Drawing::Point(31, 65);
            this->lblDescripcion->Name = L"lblDescripcion";
            this->lblDescripcion->Size = System::Drawing::Size(376, 19);
            this->lblDescripcion->TabIndex = 1;
            this->lblDescripcion->Text = L"Consola visual interna para comprobar Models y Algorithms";
            // 
            // btnEjecutarTodas
            // 
            this->btnEjecutarTodas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnEjecutarTodas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnEjecutarTodas->FlatAppearance->BorderSize = 0;
            this->btnEjecutarTodas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEjecutarTodas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnEjecutarTodas->ForeColor = System::Drawing::Color::White;
            this->btnEjecutarTodas->Location = System::Drawing::Point(1026, 24);
            this->btnEjecutarTodas->Name = L"btnEjecutarTodas";
            this->btnEjecutarTodas->Size = System::Drawing::Size(154, 40);
            this->btnEjecutarTodas->TabIndex = 2;
            this->btnEjecutarTodas->Text = L"Ejecutar todas";
            this->btnEjecutarTodas->UseVisualStyleBackColor = false;
            this->btnEjecutarTodas->Click += gcnew System::EventHandler(this, &TestForm::btnEjecutarTodas_Click);
            // 
            // btnLimpiar
            // 
            this->btnLimpiar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnLimpiar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
                static_cast<System::Int32>(static_cast<System::Byte>(106)));
            this->btnLimpiar->FlatAppearance->BorderSize = 0;
            this->btnLimpiar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->btnLimpiar->ForeColor = System::Drawing::Color::White;
            this->btnLimpiar->Location = System::Drawing::Point(1190, 24);
            this->btnLimpiar->Name = L"btnLimpiar";
            this->btnLimpiar->Size = System::Drawing::Size(160, 40);
            this->btnLimpiar->TabIndex = 3;
            this->btnLimpiar->Text = L"Limpiar resultados";
            this->btnLimpiar->UseVisualStyleBackColor = false;
            this->btnLimpiar->Click += gcnew System::EventHandler(this, &TestForm::btnLimpiar_Click);
            // 
            // lblAprobadas
            // 
            this->lblAprobadas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->lblAprobadas->AutoSize = true;
            this->lblAprobadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblAprobadas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(158)));
            this->lblAprobadas->Location = System::Drawing::Point(1023, 78);
            this->lblAprobadas->Name = L"lblAprobadas";
            this->lblAprobadas->Size = System::Drawing::Size(78, 15);
            this->lblAprobadas->TabIndex = 4;
            this->lblAprobadas->Text = L"Aprobadas: 0";
            // 
            // lblFallidas
            // 
            this->lblFallidas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->lblFallidas->AutoSize = true;
            this->lblFallidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblFallidas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
                static_cast<System::Int32>(static_cast<System::Byte>(139)));
            this->lblFallidas->Location = System::Drawing::Point(1187, 78);
            this->lblFallidas->Name = L"lblFallidas";
            this->lblFallidas->Size = System::Drawing::Size(59, 15);
            this->lblFallidas->TabIndex = 5;
            this->lblFallidas->Text = L"Fallidas: 0";
            // 
            // tabsPruebas
            // 
            this->tabsPruebas->Controls->Add(this->tabGrafo);
            this->tabsPruebas->Controls->Add(this->tabRutas);
            this->tabsPruebas->Controls->Add(this->tabSolucionador);
            this->tabsPruebas->Controls->Add(this->tabDiagnostico);
            this->tabsPruebas->Controls->Add(this->tabTraza);
            this->tabsPruebas->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabsPruebas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->tabsPruebas->Location = System::Drawing::Point(18, 130);
            this->tabsPruebas->Margin = System::Windows::Forms::Padding(18);
            this->tabsPruebas->Name = L"tabsPruebas";
            this->tabsPruebas->SelectedIndex = 0;
            this->tabsPruebas->Size = System::Drawing::Size(1348, 613);
            this->tabsPruebas->TabIndex = 1;
            // 
            // tabGrafo
            // 
            this->tabGrafo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->tabGrafo->Controls->Add(this->layoutGrafo);
            this->tabGrafo->Location = System::Drawing::Point(4, 26);
            this->tabGrafo->Name = L"tabGrafo";
            this->tabGrafo->Padding = System::Windows::Forms::Padding(14);
            this->tabGrafo->Size = System::Drawing::Size(1340, 583);
            this->tabGrafo->TabIndex = 0;
            this->tabGrafo->Text = L"1. Grafo";
            // 
            // layoutGrafo
            // 
            this->layoutGrafo->ColumnCount = 1;
            this->layoutGrafo->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutGrafo->Controls->Add(this->accionesGrafo, 0, 0);
            this->layoutGrafo->Controls->Add(this->splitMatrices, 0, 1);
            this->layoutGrafo->Controls->Add(this->txtResultadoGrafo, 0, 2);
            this->layoutGrafo->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutGrafo->Location = System::Drawing::Point(14, 14);
            this->layoutGrafo->Name = L"layoutGrafo";
            this->layoutGrafo->RowCount = 3;
            this->layoutGrafo->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
            this->layoutGrafo->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutGrafo->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
            this->layoutGrafo->Size = System::Drawing::Size(1312, 555);
            this->layoutGrafo->TabIndex = 0;
            // 
            // accionesGrafo
            // 
            this->accionesGrafo->Controls->Add(this->btnProbarGrafo);
            this->accionesGrafo->Controls->Add(this->btnValidacionesGrafo);
            this->accionesGrafo->Controls->Add(this->lblMetricaGrafo);
            this->accionesGrafo->Controls->Add(this->cmbMetricaGrafo);
            this->accionesGrafo->Dock = System::Windows::Forms::DockStyle::Fill;
            this->accionesGrafo->Location = System::Drawing::Point(3, 3);
            this->accionesGrafo->Name = L"accionesGrafo";
            this->accionesGrafo->Padding = System::Windows::Forms::Padding(4, 7, 4, 4);
            this->accionesGrafo->Size = System::Drawing::Size(1306, 48);
            this->accionesGrafo->TabIndex = 0;
            // 
            // btnProbarGrafo
            // 
            this->btnProbarGrafo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnProbarGrafo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnProbarGrafo->ForeColor = System::Drawing::Color::White;
            this->btnProbarGrafo->Location = System::Drawing::Point(7, 10);
            this->btnProbarGrafo->Name = L"btnProbarGrafo";
            this->btnProbarGrafo->Size = System::Drawing::Size(174, 36);
            this->btnProbarGrafo->TabIndex = 0;
            this->btnProbarGrafo->Text = L"Probar grafo base";
            this->btnProbarGrafo->UseVisualStyleBackColor = false;
            this->btnProbarGrafo->Click += gcnew System::EventHandler(this, &TestForm::btnProbarGrafo_Click);
            // 
            // btnValidacionesGrafo
            // 
            this->btnValidacionesGrafo->Location = System::Drawing::Point(187, 10);
            this->btnValidacionesGrafo->Name = L"btnValidacionesGrafo";
            this->btnValidacionesGrafo->Size = System::Drawing::Size(190, 36);
            this->btnValidacionesGrafo->TabIndex = 1;
            this->btnValidacionesGrafo->Text = L"Ejecutar validaciones";
            this->btnValidacionesGrafo->Click += gcnew System::EventHandler(this, &TestForm::btnValidacionesGrafo_Click);
            // 
            // lblMetricaGrafo
            // 
            this->lblMetricaGrafo->AutoSize = true;
            this->lblMetricaGrafo->Location = System::Drawing::Point(400, 17);
            this->lblMetricaGrafo->Margin = System::Windows::Forms::Padding(20, 10, 5, 0);
            this->lblMetricaGrafo->Name = L"lblMetricaGrafo";
            this->lblMetricaGrafo->Size = System::Drawing::Size(58, 19);
            this->lblMetricaGrafo->TabIndex = 2;
            this->lblMetricaGrafo->Text = L"Metrica:";
            // 
            // cmbMetricaGrafo
            // 
            this->cmbMetricaGrafo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbMetricaGrafo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Distancia", L"Tiempo", L"Costo" });
            this->cmbMetricaGrafo->Location = System::Drawing::Point(466, 10);
            this->cmbMetricaGrafo->Name = L"cmbMetricaGrafo";
            this->cmbMetricaGrafo->Size = System::Drawing::Size(150, 25);
            this->cmbMetricaGrafo->TabIndex = 3;
            // 
            // splitMatrices
            // 
            this->splitMatrices->Dock = System::Windows::Forms::DockStyle::Fill;
            this->splitMatrices->Location = System::Drawing::Point(3, 57);
            this->splitMatrices->Name = L"splitMatrices";
            // 
            // splitMatrices.Panel1
            // 
            this->splitMatrices->Panel1->Controls->Add(this->dgvAdyacencia);
            // 
            // splitMatrices.Panel2
            // 
            this->splitMatrices->Panel2->Controls->Add(this->dgvPesos);
            this->splitMatrices->Size = System::Drawing::Size(1306, 345);
            this->splitMatrices->SplitterDistance = 1053;
            this->splitMatrices->TabIndex = 1;
            // 
            // dgvAdyacencia
            // 
            this->dgvAdyacencia->AllowUserToAddRows = false;
            this->dgvAdyacencia->AllowUserToDeleteRows = false;
            this->dgvAdyacencia->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvAdyacencia->BackgroundColor = System::Drawing::Color::White;
            this->dgvAdyacencia->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvAdyacencia->Location = System::Drawing::Point(0, 0);
            this->dgvAdyacencia->Name = L"dgvAdyacencia";
            this->dgvAdyacencia->ReadOnly = true;
            this->dgvAdyacencia->Size = System::Drawing::Size(1053, 345);
            this->dgvAdyacencia->TabIndex = 0;
            // 
            // dgvPesos
            // 
            this->dgvPesos->AllowUserToAddRows = false;
            this->dgvPesos->AllowUserToDeleteRows = false;
            this->dgvPesos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvPesos->BackgroundColor = System::Drawing::Color::White;
            this->dgvPesos->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvPesos->Location = System::Drawing::Point(0, 0);
            this->dgvPesos->Name = L"dgvPesos";
            this->dgvPesos->ReadOnly = true;
            this->dgvPesos->Size = System::Drawing::Size(249, 345);
            this->dgvPesos->TabIndex = 0;
            // 
            // txtResultadoGrafo
            // 
            this->txtResultadoGrafo->BackColor = System::Drawing::Color::White;
            this->txtResultadoGrafo->Dock = System::Windows::Forms::DockStyle::Fill;
            this->txtResultadoGrafo->Location = System::Drawing::Point(3, 408);
            this->txtResultadoGrafo->Name = L"txtResultadoGrafo";
            this->txtResultadoGrafo->ReadOnly = true;
            this->txtResultadoGrafo->Size = System::Drawing::Size(1306, 144);
            this->txtResultadoGrafo->TabIndex = 2;
            this->txtResultadoGrafo->Text = L"";
            // 
            // tabRutas
            // 
            this->tabRutas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->tabRutas->Controls->Add(this->layoutRutas);
            this->tabRutas->Location = System::Drawing::Point(4, 26);
            this->tabRutas->Name = L"tabRutas";
            this->tabRutas->Padding = System::Windows::Forms::Padding(14);
            this->tabRutas->Size = System::Drawing::Size(1340, 583);
            this->tabRutas->TabIndex = 1;
            this->tabRutas->Text = L"2. Rutas canonicas";
            // 
            // layoutRutas
            // 
            this->layoutRutas->ColumnCount = 1;
            this->layoutRutas->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutRutas->Controls->Add(this->accionesRutas, 0, 0);
            this->layoutRutas->Controls->Add(this->dgvRutas, 0, 1);
            this->layoutRutas->Controls->Add(this->txtResultadoRutas, 0, 2);
            this->layoutRutas->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutRutas->Location = System::Drawing::Point(14, 14);
            this->layoutRutas->Name = L"layoutRutas";
            this->layoutRutas->RowCount = 3;
            this->layoutRutas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
            this->layoutRutas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutRutas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 135)));
            this->layoutRutas->Size = System::Drawing::Size(1312, 555);
            this->layoutRutas->TabIndex = 0;
            // 
            // accionesRutas
            // 
            this->accionesRutas->Controls->Add(this->lblNodosRutas);
            this->accionesRutas->Controls->Add(this->nudNodosRutas);
            this->accionesRutas->Controls->Add(this->lblOrigenRutas);
            this->accionesRutas->Controls->Add(this->nudOrigenRutas);
            this->accionesRutas->Controls->Add(this->btnGenerarRutas);
            this->accionesRutas->Controls->Add(this->lblConteoRutas);
            this->accionesRutas->Dock = System::Windows::Forms::DockStyle::Fill;
            this->accionesRutas->Location = System::Drawing::Point(3, 3);
            this->accionesRutas->Name = L"accionesRutas";
            this->accionesRutas->Padding = System::Windows::Forms::Padding(4, 8, 4, 4);
            this->accionesRutas->Size = System::Drawing::Size(1306, 48);
            this->accionesRutas->TabIndex = 0;
            // 
            // lblNodosRutas
            // 
            this->lblNodosRutas->AutoSize = true;
            this->lblNodosRutas->Location = System::Drawing::Point(7, 17);
            this->lblNodosRutas->Margin = System::Windows::Forms::Padding(3, 9, 5, 0);
            this->lblNodosRutas->Name = L"lblNodosRutas";
            this->lblNodosRutas->Size = System::Drawing::Size(52, 19);
            this->lblNodosRutas->TabIndex = 0;
            this->lblNodosRutas->Text = L"Nodos:";
            // 
            // nudNodosRutas
            // 
            this->nudNodosRutas->Location = System::Drawing::Point(67, 11);
            this->nudNodosRutas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->nudNodosRutas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->nudNodosRutas->Name = L"nudNodosRutas";
            this->nudNodosRutas->Size = System::Drawing::Size(65, 25);
            this->nudNodosRutas->TabIndex = 1;
            this->nudNodosRutas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->nudNodosRutas->ValueChanged += gcnew System::EventHandler(this, &TestForm::nudNodosRutas_ValueChanged);
            // 
            // lblOrigenRutas
            // 
            this->lblOrigenRutas->AutoSize = true;
            this->lblOrigenRutas->Location = System::Drawing::Point(151, 17);
            this->lblOrigenRutas->Margin = System::Windows::Forms::Padding(16, 9, 5, 0);
            this->lblOrigenRutas->Name = L"lblOrigenRutas";
            this->lblOrigenRutas->Size = System::Drawing::Size(54, 19);
            this->lblOrigenRutas->TabIndex = 2;
            this->lblOrigenRutas->Text = L"Origen:";
            // 
            // nudOrigenRutas
            // 
            this->nudOrigenRutas->Location = System::Drawing::Point(213, 11);
            this->nudOrigenRutas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
            this->nudOrigenRutas->Name = L"nudOrigenRutas";
            this->nudOrigenRutas->Size = System::Drawing::Size(65, 25);
            this->nudOrigenRutas->TabIndex = 3;
            // 
            // btnGenerarRutas
            // 
            this->btnGenerarRutas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnGenerarRutas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnGenerarRutas->ForeColor = System::Drawing::Color::White;
            this->btnGenerarRutas->Location = System::Drawing::Point(299, 8);
            this->btnGenerarRutas->Margin = System::Windows::Forms::Padding(18, 0, 3, 0);
            this->btnGenerarRutas->Name = L"btnGenerarRutas";
            this->btnGenerarRutas->Size = System::Drawing::Size(150, 36);
            this->btnGenerarRutas->TabIndex = 4;
            this->btnGenerarRutas->Text = L"Generar rutas";
            this->btnGenerarRutas->UseVisualStyleBackColor = false;
            this->btnGenerarRutas->Click += gcnew System::EventHandler(this, &TestForm::btnGenerarRutas_Click);
            // 
            // lblConteoRutas
            // 
            this->lblConteoRutas->AutoSize = true;
            this->lblConteoRutas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblConteoRutas->Location = System::Drawing::Point(472, 16);
            this->lblConteoRutas->Margin = System::Windows::Forms::Padding(20, 8, 0, 0);
            this->lblConteoRutas->Name = L"lblConteoRutas";
            this->lblConteoRutas->Size = System::Drawing::Size(54, 19);
            this->lblConteoRutas->TabIndex = 5;
            this->lblConteoRutas->Text = L"0 rutas";
            // 
            // dgvRutas
            // 
            this->dgvRutas->AllowUserToAddRows = false;
            this->dgvRutas->AllowUserToDeleteRows = false;
            this->dgvRutas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvRutas->BackgroundColor = System::Drawing::Color::White;
            this->dgvRutas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewTextBoxColumn2
            });
            this->dgvRutas->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvRutas->Location = System::Drawing::Point(3, 57);
            this->dgvRutas->Name = L"dgvRutas";
            this->dgvRutas->ReadOnly = true;
            this->dgvRutas->Size = System::Drawing::Size(1306, 360);
            this->dgvRutas->TabIndex = 1;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this->dataGridViewTextBoxColumn1->HeaderText = L"#";
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this->dataGridViewTextBoxColumn2->HeaderText = L"Ruta canonica";
            this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
            this->dataGridViewTextBoxColumn2->ReadOnly = true;
            // 
            // txtResultadoRutas
            // 
            this->txtResultadoRutas->BackColor = System::Drawing::Color::White;
            this->txtResultadoRutas->Dock = System::Windows::Forms::DockStyle::Fill;
            this->txtResultadoRutas->Location = System::Drawing::Point(3, 423);
            this->txtResultadoRutas->Name = L"txtResultadoRutas";
            this->txtResultadoRutas->ReadOnly = true;
            this->txtResultadoRutas->Size = System::Drawing::Size(1306, 129);
            this->txtResultadoRutas->TabIndex = 2;
            this->txtResultadoRutas->Text = L"";
            // 
            // tabSolucionador
            // 
            this->tabSolucionador->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->tabSolucionador->Controls->Add(this->layoutSolucionador);
            this->tabSolucionador->Location = System::Drawing::Point(4, 26);
            this->tabSolucionador->Name = L"tabSolucionador";
            this->tabSolucionador->Padding = System::Windows::Forms::Padding(14);
            this->tabSolucionador->Size = System::Drawing::Size(1340, 583);
            this->tabSolucionador->TabIndex = 2;
            this->tabSolucionador->Text = L"3. Solucionador TSP";
            // 
            // layoutSolucionador
            // 
            this->layoutSolucionador->ColumnCount = 1;
            this->layoutSolucionador->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->layoutSolucionador->Controls->Add(this->accionesSolucionador, 0, 0);
            this->layoutSolucionador->Controls->Add(this->resumenSolucionador, 0, 1);
            this->layoutSolucionador->Controls->Add(this->dgvTSP, 0, 2);
            this->layoutSolucionador->Controls->Add(this->txtResultadoTSP, 0, 3);
            this->layoutSolucionador->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutSolucionador->Location = System::Drawing::Point(14, 14);
            this->layoutSolucionador->Name = L"layoutSolucionador";
            this->layoutSolucionador->RowCount = 4;
            this->layoutSolucionador->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                54)));
            this->layoutSolucionador->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                72)));
            this->layoutSolucionador->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutSolucionador->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                115)));
            this->layoutSolucionador->Size = System::Drawing::Size(1312, 555);
            this->layoutSolucionador->TabIndex = 0;
            // 
            // accionesSolucionador
            // 
            this->accionesSolucionador->Controls->Add(this->cmbEscenarioTSP);
            this->accionesSolucionador->Controls->Add(this->nudOrigenTSP);
            this->accionesSolucionador->Controls->Add(this->cmbMetricaTSP);
            this->accionesSolucionador->Controls->Add(this->btnEjecutarTSP);
            this->accionesSolucionador->Dock = System::Windows::Forms::DockStyle::Fill;
            this->accionesSolucionador->Location = System::Drawing::Point(3, 3);
            this->accionesSolucionador->Name = L"accionesSolucionador";
            this->accionesSolucionador->Padding = System::Windows::Forms::Padding(4, 8, 4, 4);
            this->accionesSolucionador->Size = System::Drawing::Size(1306, 48);
            this->accionesSolucionador->TabIndex = 0;
            // 
            // cmbEscenarioTSP
            // 
            this->cmbEscenarioTSP->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbEscenarioTSP->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
                L"Grafo completo", L"Parcialmente conectado",
                    L"Sin conexiones", L"Empate entre rutas", L"Pesos diferentes por metrica"
            });
            this->cmbEscenarioTSP->Location = System::Drawing::Point(7, 11);
            this->cmbEscenarioTSP->Name = L"cmbEscenarioTSP";
            this->cmbEscenarioTSP->Size = System::Drawing::Size(230, 25);
            this->cmbEscenarioTSP->TabIndex = 0;
            // 
            // nudOrigenTSP
            // 
            this->nudOrigenTSP->Location = System::Drawing::Point(256, 8);
            this->nudOrigenTSP->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->nudOrigenTSP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
            this->nudOrigenTSP->Name = L"nudOrigenTSP";
            this->nudOrigenTSP->Size = System::Drawing::Size(65, 25);
            this->nudOrigenTSP->TabIndex = 1;
            // 
            // cmbMetricaTSP
            // 
            this->cmbMetricaTSP->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbMetricaTSP->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Distancia", L"Tiempo", L"Costo" });
            this->cmbMetricaTSP->Location = System::Drawing::Point(340, 8);
            this->cmbMetricaTSP->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->cmbMetricaTSP->Name = L"cmbMetricaTSP";
            this->cmbMetricaTSP->Size = System::Drawing::Size(150, 25);
            this->cmbMetricaTSP->TabIndex = 2;
            // 
            // btnEjecutarTSP
            // 
            this->btnEjecutarTSP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnEjecutarTSP->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEjecutarTSP->ForeColor = System::Drawing::Color::White;
            this->btnEjecutarTSP->Location = System::Drawing::Point(509, 8);
            this->btnEjecutarTSP->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->btnEjecutarTSP->Name = L"btnEjecutarTSP";
            this->btnEjecutarTSP->Size = System::Drawing::Size(155, 36);
            this->btnEjecutarTSP->TabIndex = 3;
            this->btnEjecutarTSP->Text = L"Resolver escenario";
            this->btnEjecutarTSP->UseVisualStyleBackColor = false;
            this->btnEjecutarTSP->Click += gcnew System::EventHandler(this, &TestForm::btnEjecutarTSP_Click);
            // 
            // resumenSolucionador
            // 
            this->resumenSolucionador->ColumnCount = 4;
            this->resumenSolucionador->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20)));
            this->resumenSolucionador->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20)));
            this->resumenSolucionador->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                40)));
            this->resumenSolucionador->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20)));
            this->resumenSolucionador->Controls->Add(this->lblCandidatosTSP, 0, 0);
            this->resumenSolucionador->Controls->Add(this->lblValidosTSP, 1, 0);
            this->resumenSolucionador->Controls->Add(this->lblMejorRutaTSP, 2, 0);
            this->resumenSolucionador->Controls->Add(this->lblMejorValorTSP, 3, 0);
            this->resumenSolucionador->Dock = System::Windows::Forms::DockStyle::Fill;
            this->resumenSolucionador->Location = System::Drawing::Point(3, 57);
            this->resumenSolucionador->Name = L"resumenSolucionador";
            this->resumenSolucionador->Padding = System::Windows::Forms::Padding(8);
            this->resumenSolucionador->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->resumenSolucionador->Size = System::Drawing::Size(1306, 66);
            this->resumenSolucionador->TabIndex = 1;
            // 
            // lblCandidatosTSP
            // 
            this->lblCandidatosTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblCandidatosTSP->Location = System::Drawing::Point(11, 8);
            this->lblCandidatosTSP->Name = L"lblCandidatosTSP";
            this->lblCandidatosTSP->Size = System::Drawing::Size(252, 50);
            this->lblCandidatosTSP->TabIndex = 0;
            this->lblCandidatosTSP->Text = L"Candidatos: 0";
            // 
            // lblValidosTSP
            // 
            this->lblValidosTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblValidosTSP->Location = System::Drawing::Point(269, 8);
            this->lblValidosTSP->Name = L"lblValidosTSP";
            this->lblValidosTSP->Size = System::Drawing::Size(252, 50);
            this->lblValidosTSP->TabIndex = 1;
            this->lblValidosTSP->Text = L"Ciclos validos: 0";
            // 
            // lblMejorRutaTSP
            // 
            this->lblMejorRutaTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblMejorRutaTSP->Location = System::Drawing::Point(527, 8);
            this->lblMejorRutaTSP->Name = L"lblMejorRutaTSP";
            this->lblMejorRutaTSP->Size = System::Drawing::Size(510, 50);
            this->lblMejorRutaTSP->TabIndex = 2;
            this->lblMejorRutaTSP->Text = L"Mejor ruta: -";
            // 
            // lblMejorValorTSP
            // 
            this->lblMejorValorTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblMejorValorTSP->Location = System::Drawing::Point(1043, 8);
            this->lblMejorValorTSP->Name = L"lblMejorValorTSP";
            this->lblMejorValorTSP->Size = System::Drawing::Size(252, 50);
            this->lblMejorValorTSP->TabIndex = 3;
            this->lblMejorValorTSP->Text = L"Mejor valor: -";
            // 
            // dgvTSP
            // 
            this->dgvTSP->AllowUserToAddRows = false;
            this->dgvTSP->AllowUserToDeleteRows = false;
            this->dgvTSP->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvTSP->BackgroundColor = System::Drawing::Color::White;
            this->dgvTSP->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->dataGridViewTextBoxColumn3,
                    this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
            });
            this->dgvTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvTSP->Location = System::Drawing::Point(3, 129);
            this->dgvTSP->Name = L"dgvTSP";
            this->dgvTSP->ReadOnly = true;
            this->dgvTSP->Size = System::Drawing::Size(1306, 308);
            this->dgvTSP->TabIndex = 2;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this->dataGridViewTextBoxColumn3->HeaderText = L"#";
            this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
            this->dataGridViewTextBoxColumn3->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this->dataGridViewTextBoxColumn4->HeaderText = L"Ruta";
            this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
            this->dataGridViewTextBoxColumn4->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this->dataGridViewTextBoxColumn5->HeaderText = L"Estado";
            this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
            this->dataGridViewTextBoxColumn5->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this->dataGridViewTextBoxColumn6->HeaderText = L"Valor total";
            this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
            this->dataGridViewTextBoxColumn6->ReadOnly = true;
            // 
            // txtResultadoTSP
            // 
            this->txtResultadoTSP->BackColor = System::Drawing::Color::White;
            this->txtResultadoTSP->Dock = System::Windows::Forms::DockStyle::Fill;
            this->txtResultadoTSP->Location = System::Drawing::Point(3, 443);
            this->txtResultadoTSP->Name = L"txtResultadoTSP";
            this->txtResultadoTSP->ReadOnly = true;
            this->txtResultadoTSP->Size = System::Drawing::Size(1306, 109);
            this->txtResultadoTSP->TabIndex = 3;
            this->txtResultadoTSP->Text = L"";
            // 
            // tabDiagnostico
            // 
            this->tabDiagnostico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->tabDiagnostico->Controls->Add(this->layoutDiagnostico);
            this->tabDiagnostico->Location = System::Drawing::Point(4, 26);
            this->tabDiagnostico->Name = L"tabDiagnostico";
            this->tabDiagnostico->Padding = System::Windows::Forms::Padding(14);
            this->tabDiagnostico->Size = System::Drawing::Size(1340, 583);
            this->tabDiagnostico->TabIndex = 3;
            this->tabDiagnostico->Text = L"4. Diagnostico";
            // 
            // layoutDiagnostico
            // 
            this->layoutDiagnostico->ColumnCount = 1;
            this->layoutDiagnostico->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                100)));
            this->layoutDiagnostico->Controls->Add(this->accionesDiagnostico, 0, 0);
            this->layoutDiagnostico->Controls->Add(this->lblExisteCiclo, 0, 1);
            this->layoutDiagnostico->Controls->Add(this->lblRutaSugerida, 0, 2);
            this->layoutDiagnostico->Controls->Add(this->lblCantidadFaltantes, 0, 3);
            this->layoutDiagnostico->Controls->Add(this->dgvFaltantes, 0, 4);
            this->layoutDiagnostico->Controls->Add(this->txtResultadoDiagnostico, 0, 5);
            this->layoutDiagnostico->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutDiagnostico->Location = System::Drawing::Point(14, 14);
            this->layoutDiagnostico->Name = L"layoutDiagnostico";
            this->layoutDiagnostico->RowCount = 6;
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutDiagnostico->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 125)));
            this->layoutDiagnostico->Size = System::Drawing::Size(1312, 555);
            this->layoutDiagnostico->TabIndex = 0;
            // 
            // accionesDiagnostico
            // 
            this->accionesDiagnostico->Controls->Add(this->cmbEscenarioDiagnostico);
            this->accionesDiagnostico->Controls->Add(this->nudOrigenDiagnostico);
            this->accionesDiagnostico->Controls->Add(this->btnEjecutarDiagnostico);
            this->accionesDiagnostico->Dock = System::Windows::Forms::DockStyle::Fill;
            this->accionesDiagnostico->Location = System::Drawing::Point(3, 3);
            this->accionesDiagnostico->Name = L"accionesDiagnostico";
            this->accionesDiagnostico->Padding = System::Windows::Forms::Padding(4, 8, 4, 4);
            this->accionesDiagnostico->Size = System::Drawing::Size(1306, 48);
            this->accionesDiagnostico->TabIndex = 0;
            // 
            // cmbEscenarioDiagnostico
            // 
            this->cmbEscenarioDiagnostico->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbEscenarioDiagnostico->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                L"Grafo completo", L"Grafo vacio",
                    L"Falta una conexion", L"Empate entre recomendaciones"
            });
            this->cmbEscenarioDiagnostico->Location = System::Drawing::Point(7, 11);
            this->cmbEscenarioDiagnostico->Name = L"cmbEscenarioDiagnostico";
            this->cmbEscenarioDiagnostico->Size = System::Drawing::Size(250, 25);
            this->cmbEscenarioDiagnostico->TabIndex = 0;
            // 
            // nudOrigenDiagnostico
            // 
            this->nudOrigenDiagnostico->Location = System::Drawing::Point(276, 8);
            this->nudOrigenDiagnostico->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->nudOrigenDiagnostico->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
            this->nudOrigenDiagnostico->Name = L"nudOrigenDiagnostico";
            this->nudOrigenDiagnostico->Size = System::Drawing::Size(65, 25);
            this->nudOrigenDiagnostico->TabIndex = 1;
            // 
            // btnEjecutarDiagnostico
            // 
            this->btnEjecutarDiagnostico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
                static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnEjecutarDiagnostico->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEjecutarDiagnostico->ForeColor = System::Drawing::Color::White;
            this->btnEjecutarDiagnostico->Location = System::Drawing::Point(360, 8);
            this->btnEjecutarDiagnostico->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->btnEjecutarDiagnostico->Name = L"btnEjecutarDiagnostico";
            this->btnEjecutarDiagnostico->Size = System::Drawing::Size(180, 36);
            this->btnEjecutarDiagnostico->TabIndex = 2;
            this->btnEjecutarDiagnostico->Text = L"Ejecutar diagnostico";
            this->btnEjecutarDiagnostico->UseVisualStyleBackColor = false;
            this->btnEjecutarDiagnostico->Click += gcnew System::EventHandler(this, &TestForm::btnEjecutarDiagnostico_Click);
            // 
            // lblExisteCiclo
            // 
            this->lblExisteCiclo->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblExisteCiclo->Location = System::Drawing::Point(3, 54);
            this->lblExisteCiclo->Name = L"lblExisteCiclo";
            this->lblExisteCiclo->Size = System::Drawing::Size(1306, 32);
            this->lblExisteCiclo->TabIndex = 1;
            this->lblExisteCiclo->Text = L"Existe ciclo hamiltoniano: -";
            // 
            // lblRutaSugerida
            // 
            this->lblRutaSugerida->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblRutaSugerida->Location = System::Drawing::Point(3, 86);
            this->lblRutaSugerida->Name = L"lblRutaSugerida";
            this->lblRutaSugerida->Size = System::Drawing::Size(1306, 32);
            this->lblRutaSugerida->TabIndex = 2;
            this->lblRutaSugerida->Text = L"Ruta sugerida: -";
            // 
            // lblCantidadFaltantes
            // 
            this->lblCantidadFaltantes->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblCantidadFaltantes->Location = System::Drawing::Point(3, 118);
            this->lblCantidadFaltantes->Name = L"lblCantidadFaltantes";
            this->lblCantidadFaltantes->Size = System::Drawing::Size(1306, 32);
            this->lblCantidadFaltantes->TabIndex = 3;
            this->lblCantidadFaltantes->Text = L"Conexiones faltantes: -";
            // 
            // dgvFaltantes
            // 
            this->dgvFaltantes->AllowUserToAddRows = false;
            this->dgvFaltantes->AllowUserToDeleteRows = false;
            this->dgvFaltantes->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvFaltantes->BackgroundColor = System::Drawing::Color::White;
            this->dgvFaltantes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn7,
                    this->dataGridViewTextBoxColumn8
            });
            this->dgvFaltantes->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvFaltantes->Location = System::Drawing::Point(3, 153);
            this->dgvFaltantes->Name = L"dgvFaltantes";
            this->dgvFaltantes->ReadOnly = true;
            this->dgvFaltantes->Size = System::Drawing::Size(1306, 274);
            this->dgvFaltantes->TabIndex = 4;
            // 
            // dataGridViewTextBoxColumn7
            // 
            this->dataGridViewTextBoxColumn7->HeaderText = L"Origen";
            this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
            this->dataGridViewTextBoxColumn7->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn8
            // 
            this->dataGridViewTextBoxColumn8->HeaderText = L"Destino";
            this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
            this->dataGridViewTextBoxColumn8->ReadOnly = true;
            // 
            // txtResultadoDiagnostico
            // 
            this->txtResultadoDiagnostico->BackColor = System::Drawing::Color::White;
            this->txtResultadoDiagnostico->Dock = System::Windows::Forms::DockStyle::Fill;
            this->txtResultadoDiagnostico->Location = System::Drawing::Point(3, 433);
            this->txtResultadoDiagnostico->Name = L"txtResultadoDiagnostico";
            this->txtResultadoDiagnostico->ReadOnly = true;
            this->txtResultadoDiagnostico->Size = System::Drawing::Size(1306, 119);
            this->txtResultadoDiagnostico->TabIndex = 5;
            this->txtResultadoDiagnostico->Text = L"";
            // 
            // tabTraza
            // 
            this->tabTraza->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->tabTraza->Controls->Add(this->layoutTraza);
            this->tabTraza->Location = System::Drawing::Point(4, 26);
            this->tabTraza->Name = L"tabTraza";
            this->tabTraza->Padding = System::Windows::Forms::Padding(14);
            this->tabTraza->Size = System::Drawing::Size(1340, 583);
            this->tabTraza->TabIndex = 4;
            this->tabTraza->Text = L"5. Traza paso a paso";
            // 
            // layoutTraza
            // 
            this->layoutTraza->ColumnCount = 1;
            this->layoutTraza->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutTraza->Controls->Add(this->accionesTraza, 0, 0);
            this->layoutTraza->Controls->Add(this->lblRutaTraza, 0, 1);
            this->layoutTraza->Controls->Add(this->lblValidezTraza, 0, 2);
            this->layoutTraza->Controls->Add(this->lblValorTraza, 0, 3);
            this->layoutTraza->Controls->Add(this->dgvTraza, 0, 4);
            this->layoutTraza->Controls->Add(this->txtResultadoTraza, 0, 5);
            this->layoutTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->layoutTraza->Location = System::Drawing::Point(14, 14);
            this->layoutTraza->Name = L"layoutTraza";
            this->layoutTraza->RowCount = 6;
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->layoutTraza->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 120)));
            this->layoutTraza->Size = System::Drawing::Size(1312, 555);
            this->layoutTraza->TabIndex = 0;
            // 
            // accionesTraza
            // 
            this->accionesTraza->Controls->Add(this->cmbEscenarioTraza);
            this->accionesTraza->Controls->Add(this->cmbMetricaTraza);
            this->accionesTraza->Controls->Add(this->btnEjecutarTraza);
            this->accionesTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->accionesTraza->Location = System::Drawing::Point(3, 3);
            this->accionesTraza->Name = L"accionesTraza";
            this->accionesTraza->Padding = System::Windows::Forms::Padding(4, 8, 4, 4);
            this->accionesTraza->Size = System::Drawing::Size(1306, 48);
            this->accionesTraza->TabIndex = 0;
            // 
            // cmbEscenarioTraza
            // 
            this->cmbEscenarioTraza->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbEscenarioTraza->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"Ruta completa", L"Falta al inicio", L"Falta en el medio",
                    L"Falta al regresar", L"Ruta estructural incorrecta", L"Desbordamiento"
            });
            this->cmbEscenarioTraza->Location = System::Drawing::Point(7, 11);
            this->cmbEscenarioTraza->Name = L"cmbEscenarioTraza";
            this->cmbEscenarioTraza->Size = System::Drawing::Size(250, 25);
            this->cmbEscenarioTraza->TabIndex = 0;
            // 
            // cmbMetricaTraza
            // 
            this->cmbMetricaTraza->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbMetricaTraza->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Distancia", L"Tiempo", L"Costo" });
            this->cmbMetricaTraza->Location = System::Drawing::Point(276, 8);
            this->cmbMetricaTraza->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->cmbMetricaTraza->Name = L"cmbMetricaTraza";
            this->cmbMetricaTraza->Size = System::Drawing::Size(150, 25);
            this->cmbMetricaTraza->TabIndex = 1;
            // 
            // btnEjecutarTraza
            // 
            this->btnEjecutarTraza->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->btnEjecutarTraza->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEjecutarTraza->ForeColor = System::Drawing::Color::White;
            this->btnEjecutarTraza->Location = System::Drawing::Point(445, 8);
            this->btnEjecutarTraza->Margin = System::Windows::Forms::Padding(16, 0, 3, 0);
            this->btnEjecutarTraza->Name = L"btnEjecutarTraza";
            this->btnEjecutarTraza->Size = System::Drawing::Size(160, 36);
            this->btnEjecutarTraza->TabIndex = 2;
            this->btnEjecutarTraza->Text = L"Generar traza";
            this->btnEjecutarTraza->UseVisualStyleBackColor = false;
            this->btnEjecutarTraza->Click += gcnew System::EventHandler(this, &TestForm::btnEjecutarTraza_Click);
            // 
            // lblRutaTraza
            // 
            this->lblRutaTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblRutaTraza->Location = System::Drawing::Point(3, 54);
            this->lblRutaTraza->Name = L"lblRutaTraza";
            this->lblRutaTraza->Size = System::Drawing::Size(1306, 32);
            this->lblRutaTraza->TabIndex = 1;
            this->lblRutaTraza->Text = L"Ruta: -";
            // 
            // lblValidezTraza
            // 
            this->lblValidezTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblValidezTraza->Location = System::Drawing::Point(3, 86);
            this->lblValidezTraza->Name = L"lblValidezTraza";
            this->lblValidezTraza->Size = System::Drawing::Size(1306, 32);
            this->lblValidezTraza->TabIndex = 2;
            this->lblValidezTraza->Text = L"Validez: -";
            // 
            // lblValorTraza
            // 
            this->lblValorTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lblValorTraza->Location = System::Drawing::Point(3, 118);
            this->lblValorTraza->Name = L"lblValorTraza";
            this->lblValorTraza->Size = System::Drawing::Size(1306, 32);
            this->lblValorTraza->TabIndex = 3;
            this->lblValorTraza->Text = L"Valor total: -";
            // 
            // dgvTraza
            // 
            this->dgvTraza->AllowUserToAddRows = false;
            this->dgvTraza->AllowUserToDeleteRows = false;
            this->dgvTraza->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvTraza->BackgroundColor = System::Drawing::Color::White;
            this->dgvTraza->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->dataGridViewTextBoxColumn9,
                    this->dataGridViewTextBoxColumn10, this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, this->dataGridViewTextBoxColumn13,
                    this->dataGridViewTextBoxColumn14
            });
            this->dgvTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dgvTraza->Location = System::Drawing::Point(3, 153);
            this->dgvTraza->Name = L"dgvTraza";
            this->dgvTraza->ReadOnly = true;
            this->dgvTraza->Size = System::Drawing::Size(1306, 279);
            this->dgvTraza->TabIndex = 4;
            // 
            // dataGridViewTextBoxColumn9
            // 
            this->dataGridViewTextBoxColumn9->HeaderText = L"Paso";
            this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
            this->dataGridViewTextBoxColumn9->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn10
            // 
            this->dataGridViewTextBoxColumn10->HeaderText = L"Origen";
            this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
            this->dataGridViewTextBoxColumn10->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn11
            // 
            this->dataGridViewTextBoxColumn11->HeaderText = L"Destino";
            this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
            this->dataGridViewTextBoxColumn11->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn12
            // 
            this->dataGridViewTextBoxColumn12->HeaderText = L"Existe";
            this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
            this->dataGridViewTextBoxColumn12->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn13
            // 
            this->dataGridViewTextBoxColumn13->HeaderText = L"Peso";
            this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
            this->dataGridViewTextBoxColumn13->ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn14
            // 
            this->dataGridViewTextBoxColumn14->HeaderText = L"Acumulado";
            this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
            this->dataGridViewTextBoxColumn14->ReadOnly = true;
            // 
            // txtResultadoTraza
            // 
            this->txtResultadoTraza->BackColor = System::Drawing::Color::White;
            this->txtResultadoTraza->Dock = System::Windows::Forms::DockStyle::Fill;
            this->txtResultadoTraza->Location = System::Drawing::Point(3, 438);
            this->txtResultadoTraza->Name = L"txtResultadoTraza";
            this->txtResultadoTraza->ReadOnly = true;
            this->txtResultadoTraza->Size = System::Drawing::Size(1306, 114);
            this->txtResultadoTraza->TabIndex = 5;
            this->txtResultadoTraza->Text = L"";
            // 
            // TestForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
                static_cast<System::Int32>(static_cast<System::Byte>(251)));
            this->ClientSize = System::Drawing::Size(1384, 761);
            this->Controls->Add(this->layoutPrincipal);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->MinimumSize = System::Drawing::Size(1200, 700);
            this->Name = L"TestForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MathOs-Sky - Core & Algorithms Test Form";
            this->Load += gcnew System::EventHandler(this, &TestForm::TestForm_Load);
            this->layoutPrincipal->ResumeLayout(false);
            this->panelEncabezado->ResumeLayout(false);
            this->panelEncabezado->PerformLayout();
            this->tabsPruebas->ResumeLayout(false);
            this->tabGrafo->ResumeLayout(false);
            this->layoutGrafo->ResumeLayout(false);
            this->accionesGrafo->ResumeLayout(false);
            this->accionesGrafo->PerformLayout();
            this->splitMatrices->Panel1->ResumeLayout(false);
            this->splitMatrices->Panel2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitMatrices))->EndInit();
            this->splitMatrices->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAdyacencia))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPesos))->EndInit();
            this->tabRutas->ResumeLayout(false);
            this->layoutRutas->ResumeLayout(false);
            this->accionesRutas->ResumeLayout(false);
            this->accionesRutas->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudNodosRutas))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenRutas))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRutas))->EndInit();
            this->tabSolucionador->ResumeLayout(false);
            this->layoutSolucionador->ResumeLayout(false);
            this->accionesSolucionador->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenTSP))->EndInit();
            this->resumenSolucionador->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTSP))->EndInit();
            this->tabDiagnostico->ResumeLayout(false);
            this->layoutDiagnostico->ResumeLayout(false);
            this->accionesDiagnostico->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudOrigenDiagnostico))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaltantes))->EndInit();
            this->tabTraza->ResumeLayout(false);
            this->layoutTraza->ResumeLayout(false);
            this->accionesTraza->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTraza))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void TestForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void lblTitulo_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
