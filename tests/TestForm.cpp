#include "TestForm.h"
#include "../MathOs-Sky_Desktop/Algorithms/DiagnosticoHamiltoniano.h"
#include "../MathOs-Sky_Desktop/Algorithms/RutasCanonicas.h"
#include "../MathOs-Sky_Desktop/Algorithms/SolucionadorTSP.h"
#include "../MathOs-Sky_Desktop/Models/Grafo.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{
    constexpr int CANTIDAD_NODOS_PRUEBA = 5;
    constexpr std::size_t LIMITE_VISTA_PREVIA = 100;

    bool esArista(int origen, int destino, int extremoA, int extremoB)
    {
        return (origen == extremoA && destino == extremoB)
            || (origen == extremoB && destino == extremoA);
    }

    bool perteneceCicloA(int origen, int destino)
    {
        return esArista(origen, destino, 0, 1)
            || esArista(origen, destino, 1, 2)
            || esArista(origen, destino, 2, 3)
            || esArista(origen, destino, 3, 4)
            || esArista(origen, destino, 4, 0);
    }

    bool perteneceCicloB(int origen, int destino)
    {
        return esArista(origen, destino, 0, 2)
            || esArista(origen, destino, 2, 4)
            || esArista(origen, destino, 4, 1)
            || esArista(origen, destino, 1, 3)
            || esArista(origen, destino, 3, 0);
    }

    MathOsSky::Grafo crearGrafoCompleto(bool empate = false, bool metricasDiferentes = false, bool desbordamiento = false)
    {
        MathOsSky::Grafo grafo(CANTIDAD_NODOS_PRUEBA);
        double pesoGrande = std::numeric_limits<double>::max() / 2.0;

        for (int origen = 0; origen < CANTIDAD_NODOS_PRUEBA; ++origen)
        {
            for (int destino = origen + 1; destino < CANTIDAD_NODOS_PRUEBA; ++destino)
            {
                double distancia = 10.0 + origen + destino;
                double tiempo = 20.0 + (destino - origen);
                double costo = 30.0 + (origen * 3) + destino;

                if (empate)
                {
                    distancia = tiempo = costo = 1.0;
                }
                else if (metricasDiferentes)
                {
                    distancia = perteneceCicloA(origen, destino) ? 1.0 : 9.0;
                    tiempo = perteneceCicloB(origen, destino) ? 1.0 : 9.0;
                    costo = 5.0;
                }
                else if (desbordamiento)
                {
                    distancia = tiempo = costo = pesoGrande;
                }

                grafo.addConexion(origen, destino, distancia, tiempo, costo);
            }
        }

        return grafo;
    }

    MathOsSky::Grafo crearGrafoCiclo(bool omitirPrimera = false, bool omitirMedio = false, bool omitirRegreso = false)
    {
        MathOsSky::Grafo grafo(CANTIDAD_NODOS_PRUEBA);
        const int origenes[] = {0, 1, 2, 3, 4};
        const int destinos[] = {1, 2, 3, 4, 0};

        for (int indice = 0; indice < CANTIDAD_NODOS_PRUEBA; ++indice)
        {
            bool omitir = (omitirPrimera && indice == 0)
                || (omitirMedio && indice == 2)
                || (omitirRegreso && indice == 4);
            if (!omitir)
            {
                grafo.addConexion(origenes[indice], destinos[indice], 2.0 + indice, 3.0 + indice, 4.0 + indice);
            }
        }

        return grafo;
    }

    MathOsSky::Metrica seleccionarMetrica(int indice)
    {
        switch (indice)
        {
        case 0:
            return MathOsSky::Metrica::Distancia;
        case 1:
            return MathOsSky::Metrica::Tiempo;
        case 2:
            return MathOsSky::Metrica::Costo;
        default:
            throw std::invalid_argument("Indice de metrica no reconocido por TestForm.");
        }
    }

    System::String^ textoRuta(const std::vector<int>& ruta)
    {
        System::Text::StringBuilder^ texto = gcnew System::Text::StringBuilder();
        for (std::size_t indice = 0; indice < ruta.size(); ++indice)
        {
            if (indice > 0)
            {
                texto->Append(L" -> ");
            }
            texto->Append(ruta[indice]);
        }
        return texto->ToString();
    }

    void cargarMatriz(System::Windows::Forms::DataGridView^ grid, const std::vector<std::vector<int>>& matriz)
    {
        grid->Columns->Clear();
        grid->Rows->Clear();
        for (std::size_t columna = 0; columna < matriz.size(); ++columna)
        {
            grid->Columns->Add(L"N" + columna.ToString(), columna.ToString());
        }
        for (std::size_t fila = 0; fila < matriz.size(); ++fila)
        {
            int indiceFila = grid->Rows->Add();
            grid->Rows[indiceFila]->HeaderCell->Value = fila.ToString();
            for (std::size_t columna = 0; columna < matriz[fila].size(); ++columna)
            {
                grid->Rows[indiceFila]->Cells[static_cast<int>(columna)]->Value = matriz[fila][columna];
            }
        }
        grid->RowHeadersWidth = 55;
    }

    void cargarMatriz(System::Windows::Forms::DataGridView^ grid, const std::vector<std::vector<double>>& matriz)
    {
        grid->Columns->Clear();
        grid->Rows->Clear();
        for (std::size_t columna = 0; columna < matriz.size(); ++columna)
        {
            grid->Columns->Add(L"N" + columna.ToString(), columna.ToString());
        }
        for (std::size_t fila = 0; fila < matriz.size(); ++fila)
        {
            int indiceFila = grid->Rows->Add();
            grid->Rows[indiceFila]->HeaderCell->Value = fila.ToString();
            for (std::size_t columna = 0; columna < matriz[fila].size(); ++columna)
            {
                grid->Rows[indiceFila]->Cells[static_cast<int>(columna)]->Value = matriz[fila][columna].ToString(L"0.##");
            }
        }
        grid->RowHeadersWidth = 55;
    }

    std::size_t cantidadCanonicaEsperada(int cantidadNodos)
    {
        std::size_t cantidad = 1;
        for (int factor = 2; factor < cantidadNodos; ++factor)
        {
            cantidad *= static_cast<std::size_t>(factor);
        }
        return cantidad / 2;
    }

    bool rechazaCantidadNodos(int cantidad)
    {
        try
        {
            MathOsSky::Grafo grafo(cantidad);
            return false;
        }
        catch (const std::invalid_argument&)
        {
            return true;
        }
    }

    bool rechazaPeso(double peso)
    {
        try
        {
            MathOsSky::Grafo grafo(CANTIDAD_NODOS_PRUEBA);
            grafo.addConexion(0, 1, peso, 1.0, 1.0);
            return false;
        }
        catch (const std::invalid_argument&)
        {
            return true;
        }
    }
}

namespace MathOsSky
{
    void TestForm::inicializarSelecciones()
    {
        cmbMetricaGrafo->SelectedIndex = 0;
        cmbEscenarioTSP->SelectedIndex = 0;
        cmbMetricaTSP->SelectedIndex = 0;
        cmbEscenarioDiagnostico->SelectedIndex = 0;
        cmbEscenarioTraza->SelectedIndex = 0;
        cmbMetricaTraza->SelectedIndex = 0;
    }

    void TestForm::actualizarContadores()
    {
        lblAprobadas->Text = String::Format(L"Aprobadas: {0}", cantidadAprobadas);
        lblFallidas->Text = String::Format(L"Fallidas: {0}", cantidadFallidas);
    }

    void TestForm::registrarResultado(RichTextBox^ area, bool aprobado, String^ mensaje)
    {
        area->SelectionStart = area->TextLength;
        area->SelectionColor = aprobado ? Color::FromArgb(24, 132, 78) : Color::FromArgb(196, 55, 55);
        area->AppendText((aprobado ? L"PASS - " : L"FAIL - ") + mensaje + Environment::NewLine);
        if (aprobado)
        {
            ++cantidadAprobadas;
        }
        else
        {
            ++cantidadFallidas;
        }
        actualizarContadores();
    }

    void TestForm::registrarExcepcion(RichTextBox^ area, String^ contexto, const std::exception& error)
    {
        registrarResultado(area, false, contexto + L": " + gcnew String(error.what()));
    }

    void TestForm::limpiarResultados()
    {
        cantidadAprobadas = 0;
        cantidadFallidas = 0;
        lblDescripcion->Text = L"Consola visual interna para comprobar Models y Algorithms";
        txtResultadoGrafo->Clear();
        txtResultadoRutas->Clear();
        txtResultadoTSP->Clear();
        txtResultadoDiagnostico->Clear();
        txtResultadoTraza->Clear();
        dgvAdyacencia->Columns->Clear();
        dgvPesos->Columns->Clear();
        dgvRutas->Rows->Clear();
        dgvTSP->Rows->Clear();
        dgvFaltantes->Rows->Clear();
        dgvTraza->Rows->Clear();
        actualizarContadores();
    }

    System::Void TestForm::btnLimpiar_Click(System::Object^, System::EventArgs^)
    {
        limpiarResultados();
    }

    System::Void TestForm::btnProbarGrafo_Click(System::Object^, System::EventArgs^)
    {
        try
        {
            if (!ejecutandoTodas)
            {
                txtResultadoGrafo->Clear();
            }
            Grafo grafo = crearGrafoCompleto();
            grafo.addConexion(0, 1, 7.0, 8.0, 9.0);

            registrarResultado(txtResultadoGrafo, grafo.getCantidadNodos() == 5, L"El grafo contiene cinco nodos");
            registrarResultado(txtResultadoGrafo, grafo.hasConexion(0, 1) && grafo.hasConexion(1, 0), L"La conexion 0-1 existe en ambos sentidos");
            Conexion conexion = grafo.getConexion(0, 1);
            registrarResultado(txtResultadoGrafo, conexion.distancia == 7.0 && conexion.tiempo == 8.0 && conexion.costo == 9.0, L"La conexion devuelve sus tres pesos");
            registrarResultado(txtResultadoGrafo, grafo.getPeso(0, 1, Metrica::Distancia) == 7.0, L"La distancia reemplazada coincide");
            registrarResultado(txtResultadoGrafo, grafo.getPeso(0, 1, Metrica::Tiempo) == 8.0, L"El tiempo reemplazado coincide");
            registrarResultado(txtResultadoGrafo, grafo.getPeso(0, 1, Metrica::Costo) == 9.0, L"El costo reemplazado coincide");

            grafo.removeConexion(0, 1);
            grafo.removeConexion(0, 1);
            registrarResultado(txtResultadoGrafo, !grafo.hasConexion(0, 1) && !grafo.hasConexion(1, 0), L"La eliminacion es simetrica e idempotente");

            Grafo grafoMatrices = crearGrafoCompleto();
            cargarMatriz(dgvAdyacencia, grafoMatrices.getMatrizAdyacencia());
            cargarMatriz(dgvPesos, grafoMatrices.getMatrizPesos(seleccionarMetrica(cmbMetricaGrafo->SelectedIndex)));
            registrarResultado(txtResultadoGrafo, grafoMatrices.getMatrizAdyacencia()[0][1] == grafoMatrices.getMatrizAdyacencia()[1][0], L"La matriz de adyacencia es simetrica");
        }
        catch (const std::invalid_argument& error)
        {
            registrarExcepcion(txtResultadoGrafo, L"Argumento inesperado", error);
        }
        catch (const std::out_of_range& error)
        {
            registrarExcepcion(txtResultadoGrafo, L"Indice inesperado", error);
        }
        catch (const std::logic_error& error)
        {
            registrarExcepcion(txtResultadoGrafo, L"Estado inesperado", error);
        }
        catch (const std::overflow_error& error)
        {
            registrarExcepcion(txtResultadoGrafo, L"Desbordamiento inesperado", error);
        }
        catch (const std::exception& error)
        {
            registrarExcepcion(txtResultadoGrafo, L"Error inesperado", error);
        }
    }

    System::Void TestForm::btnValidacionesGrafo_Click(System::Object^, System::EventArgs^)
    {
        if (!ejecutandoTodas)
        {
            txtResultadoGrafo->Clear();
        }
        registrarResultado(txtResultadoGrafo, rechazaCantidadNodos(4), L"Se rechazo un grafo de cuatro nodos");
        registrarResultado(txtResultadoGrafo, rechazaCantidadNodos(11), L"Se rechazo un grafo de once nodos");

        bool lazoRechazado = false;
        bool rangoRechazado = false;
        try
        {
            Grafo grafo(5);
            grafo.addConexion(0, 0, 1.0, 1.0, 1.0);
        }
        catch (const std::invalid_argument&)
        {
            lazoRechazado = true;
        }
        try
        {
            Grafo grafo(5);
            grafo.hasConexion(0, 5);
        }
        catch (const std::out_of_range&)
        {
            rangoRechazado = true;
        }

        registrarResultado(txtResultadoGrafo, lazoRechazado, L"El lazo fue rechazado");
        registrarResultado(txtResultadoGrafo, rangoRechazado, L"El nodo fuera de rango fue rechazado");
        registrarResultado(txtResultadoGrafo, rechazaPeso(0.0), L"El peso cero fue rechazado");
        registrarResultado(txtResultadoGrafo, rechazaPeso(-1.0), L"El peso negativo fue rechazado");
        registrarResultado(txtResultadoGrafo, rechazaPeso(std::numeric_limits<double>::infinity()), L"El infinito fue rechazado");
        registrarResultado(txtResultadoGrafo, rechazaPeso(std::numeric_limits<double>::quiet_NaN()), L"NaN fue rechazado");
    }

    System::Void TestForm::nudNodosRutas_ValueChanged(System::Object^, System::EventArgs^)
    {
        int cantidadNodos = Decimal::ToInt32(nudNodosRutas->Value);
        nudOrigenRutas->Maximum = System::Decimal(cantidadNodos - 1);
        if (nudOrigenRutas->Value > nudOrigenRutas->Maximum)
        {
            nudOrigenRutas->Value = nudOrigenRutas->Maximum;
        }
    }

    System::Void TestForm::btnGenerarRutas_Click(System::Object^, System::EventArgs^)
    {
        try
        {
            if (!ejecutandoTodas)
            {
                txtResultadoRutas->Clear();
            }
            dgvRutas->Rows->Clear();
            int cantidadNodos = Decimal::ToInt32(nudNodosRutas->Value);
            int origen = Decimal::ToInt32(nudOrigenRutas->Value);
            std::vector<std::vector<int>> rutas = generarRutasCanonicas(cantidadNodos, origen);
            std::vector<std::vector<int>> segundaGeneracion = generarRutasCanonicas(cantidadNodos, origen);
            std::size_t limite = std::min(LIMITE_VISTA_PREVIA, rutas.size());

            for (std::size_t indice = 0; indice < limite; ++indice)
            {
                dgvRutas->Rows->Add(static_cast<int>(indice + 1), textoRuta(rutas[indice]));
            }

            lblConteoRutas->Text = String::Format(L"Mostrando {0} de {1} rutas", static_cast<int>(limite), static_cast<unsigned long long>(rutas.size()));
            bool estructuraCorrecta = true;
            bool orientacionUnica = true;
            for (const std::vector<int>& ruta : rutas)
            {
                if (ruta.size() != static_cast<std::size_t>(cantidadNodos + 1)
                    || ruta.front() != origen || ruta.back() != origen)
                {
                    estructuraCorrecta = false;
                }
                if (ruta[1] >= ruta[ruta.size() - 2])
                {
                    orientacionUnica = false;
                }
            }

            registrarResultado(txtResultadoRutas, rutas.size() == cantidadCanonicaEsperada(cantidadNodos), L"El conteo coincide con (n - 1)! / 2");
            registrarResultado(txtResultadoRutas, estructuraCorrecta, L"Todas las rutas empiezan y terminan en el origen y tienen tamano n + 1");
            registrarResultado(txtResultadoRutas, orientacionUnica, L"Se conserva una sola orientacion de cada ciclo inverso");
            registrarResultado(txtResultadoRutas, rutas == segundaGeneracion, L"El orden de generacion es determinista");
            registrarResultado(txtResultadoRutas, rutas.size() <= LIMITE_VISTA_PREVIA || dgvRutas->Rows->Count == 100, L"La vista previa nunca supera cien rutas");
        }
        catch (const std::invalid_argument& error)
        {
            registrarExcepcion(txtResultadoRutas, L"Entrada invalida", error);
        }
        catch (const std::out_of_range& error)
        {
            registrarExcepcion(txtResultadoRutas, L"Indice invalido", error);
        }
        catch (const std::logic_error& error)
        {
            registrarExcepcion(txtResultadoRutas, L"Estado invalido", error);
        }
        catch (const std::overflow_error& error)
        {
            registrarExcepcion(txtResultadoRutas, L"Desbordamiento", error);
        }
        catch (const std::exception& error)
        {
            registrarExcepcion(txtResultadoRutas, L"Error inesperado", error);
        }
    }

    System::Void TestForm::btnEjecutarTSP_Click(System::Object^, System::EventArgs^)
    {
        try
        {
            if (!ejecutandoTodas)
            {
                txtResultadoTSP->Clear();
            }
            dgvTSP->Rows->Clear();
            int escenario = cmbEscenarioTSP->SelectedIndex;
            int origen = Decimal::ToInt32(nudOrigenTSP->Value);
            Metrica metrica = seleccionarMetrica(cmbMetricaTSP->SelectedIndex);
            Grafo grafo(5);

            switch (escenario)
            {
            case 0:
                grafo = crearGrafoCompleto();
                break;
            case 1:
                grafo = crearGrafoCiclo();
                break;
            case 2:
                break;
            case 3:
                grafo = crearGrafoCompleto(true);
                break;
            case 4:
                grafo = crearGrafoCompleto(false, true);
                break;
            default:
                throw std::invalid_argument("Escenario TSP no reconocido.");
            }

            ResultadoTSP resultado = SolucionadorTSP::solve(grafo, origen, metrica);
            lblCandidatosTSP->Text = String::Format(L"Candidatos: {0}", static_cast<unsigned long long>(resultado.cantidadCandidatos));
            lblValidosTSP->Text = String::Format(L"Ciclos validos: {0}", static_cast<unsigned long long>(resultado.cantidadCiclosValidos));
            lblMejorRutaTSP->Text = L"Mejor ruta: " + (resultado.mejorRuta.empty() ? L"-" : textoRuta(resultado.mejorRuta));
            lblMejorValorTSP->Text = resultado.mejorRuta.empty()
                ? L"Mejor valor: infinito"
                : L"Mejor valor: " + resultado.mejorValor.ToString(L"0.##");

            std::size_t limite = std::min(LIMITE_VISTA_PREVIA, resultado.rutas.size());
            for (std::size_t indice = 0; indice < limite; ++indice)
            {
                const RutaEvaluada& evaluacion = resultado.rutas[indice];
                dgvTSP->Rows->Add(
                    static_cast<int>(indice + 1),
                    textoRuta(evaluacion.ruta),
                    evaluacion.valida ? L"Valida" : L"Invalida",
                    evaluacion.valida ? evaluacion.valorTotal.ToString(L"0.##") : L"0");
            }

            registrarResultado(txtResultadoTSP, resultado.cantidadCandidatos == 12 && resultado.rutas.size() == 12, L"Se evaluaron los doce candidatos canonicos");
            bool cantidadValida = (escenario == 0 || escenario == 3 || escenario == 4)
                ? resultado.cantidadCiclosValidos == 12
                : (escenario == 1 ? resultado.cantidadCiclosValidos == 1 : resultado.cantidadCiclosValidos == 0);
            registrarResultado(txtResultadoTSP, cantidadValida, L"La cantidad de ciclos validos coincide con el escenario");
            registrarResultado(txtResultadoTSP, (resultado.cantidadCiclosValidos == 0) == resultado.mejorRuta.empty(), L"La mejor ruta existe solamente cuando hay ciclos validos");

            if (escenario == 3)
            {
                std::vector<std::vector<int>> canonicas = generarRutasCanonicas(5, origen);
                registrarResultado(txtResultadoTSP, resultado.mejorRuta == canonicas.front(), L"El empate conserva la primera ruta canonica");
            }
            if (escenario == 4)
            {
                ResultadoTSP distancia = SolucionadorTSP::solve(grafo, origen, Metrica::Distancia);
                ResultadoTSP tiempo = SolucionadorTSP::solve(grafo, origen, Metrica::Tiempo);
                ResultadoTSP costo = SolucionadorTSP::solve(grafo, origen, Metrica::Costo);
                registrarResultado(txtResultadoTSP, distancia.mejorValor == 5.0 && tiempo.mejorValor == 5.0, L"Distancia y tiempo encuentran sus ciclos de peso cinco");
                registrarResultado(txtResultadoTSP, distancia.mejorRuta != tiempo.mejorRuta, L"Diferentes metricas pueden seleccionar rutas distintas");
                registrarResultado(txtResultadoTSP, costo.mejorValor == 25.0, L"El costo acumula sus cinco conexiones independientes");
            }

            bool metricaInvalidaRechazada = false;
            try
            {
                Grafo vacio(5);
                SolucionadorTSP::solve(vacio, 0, static_cast<Metrica>(99));
            }
            catch (const std::invalid_argument&)
            {
                metricaInvalidaRechazada = true;
            }
            registrarResultado(txtResultadoTSP, metricaInvalidaRechazada, L"La metrica invalida fue rechazada aun con un grafo vacio");

            bool desbordamientoRechazado = false;
            try
            {
                Grafo enorme = crearGrafoCompleto(false, false, true);
                SolucionadorTSP::solve(enorme, 0, Metrica::Distancia);
            }
            catch (const std::overflow_error&)
            {
                desbordamientoRechazado = true;
            }
            registrarResultado(txtResultadoTSP, desbordamientoRechazado, L"El desbordamiento de double fue rechazado");
        }
        catch (const std::invalid_argument& error)
        {
            registrarExcepcion(txtResultadoTSP, L"Argumento inesperado", error);
        }
        catch (const std::out_of_range& error)
        {
            registrarExcepcion(txtResultadoTSP, L"Indice inesperado", error);
        }
        catch (const std::logic_error& error)
        {
            registrarExcepcion(txtResultadoTSP, L"Estado inesperado", error);
        }
        catch (const std::overflow_error& error)
        {
            registrarExcepcion(txtResultadoTSP, L"Desbordamiento inesperado", error);
        }
        catch (const std::exception& error)
        {
            registrarExcepcion(txtResultadoTSP, L"Error inesperado", error);
        }
    }

    System::Void TestForm::btnEjecutarDiagnostico_Click(System::Object^, System::EventArgs^)
    {
        try
        {
            if (!ejecutandoTodas)
            {
                txtResultadoDiagnostico->Clear();
            }
            dgvFaltantes->Rows->Clear();
            int escenario = cmbEscenarioDiagnostico->SelectedIndex;
            int origen = Decimal::ToInt32(nudOrigenDiagnostico->Value);
            Grafo grafo(5);

            switch (escenario)
            {
            case 0:
                grafo = crearGrafoCompleto();
                break;
            case 1:
                break;
            case 2:
                grafo = crearGrafoCiclo(false, false, true);
                break;
            case 3:
                break;
            default:
                throw std::invalid_argument("Escenario de diagnostico no reconocido.");
            }

            Grafo::MatrizAdyacencia adyacenciaAntes = grafo.getMatrizAdyacencia();
            Grafo::MatrizPesos distanciaAntes = grafo.getMatrizPesos(Metrica::Distancia);
            Grafo::MatrizPesos tiempoAntes = grafo.getMatrizPesos(Metrica::Tiempo);
            Grafo::MatrizPesos costoAntes = grafo.getMatrizPesos(Metrica::Costo);
            int nodosAntes = grafo.getCantidadNodos();

            ResultadoDiagnosticoHamiltoniano resultado = DiagnosticoHamiltoniano::analyze(grafo, origen);
            lblExisteCiclo->Text = L"Existe ciclo hamiltoniano: " + (resultado.existeCicloHamiltoniano ? L"Si" : L"No");
            lblRutaSugerida->Text = L"Ruta sugerida: " + textoRuta(resultado.rutaSugerida);
            lblCantidadFaltantes->Text = String::Format(L"Conexiones faltantes: {0}", static_cast<int>(resultado.conexionesFaltantes.size()));

            std::set<std::pair<int, int>> conexionesUnicas;
            bool normalizadas = true;
            for (const ConexionFaltante& conexion : resultado.conexionesFaltantes)
            {
                dgvFaltantes->Rows->Add(conexion.origen, conexion.destino);
                normalizadas = normalizadas && conexion.origen < conexion.destino;
                conexionesUnicas.insert({conexion.origen, conexion.destino});
            }

            if (escenario == 0)
            {
                registrarResultado(txtResultadoDiagnostico, resultado.existeCicloHamiltoniano && resultado.conexionesFaltantes.empty(), L"El grafo completo ya contiene un ciclo hamiltoniano");
            }
            else if (escenario == 1)
            {
                registrarResultado(txtResultadoDiagnostico, !resultado.existeCicloHamiltoniano && resultado.conexionesFaltantes.size() == 5, L"El grafo vacio necesita exactamente cinco conexiones");
            }
            else if (escenario == 2)
            {
                bool recomendacionCorrecta = resultado.conexionesFaltantes.size() == 1
                    && resultado.conexionesFaltantes.front().origen == 0
                    && resultado.conexionesFaltantes.front().destino == 4;
                registrarResultado(txtResultadoDiagnostico, recomendacionCorrecta, L"Se recomendo unicamente la conexion normalizada 0-4");
            }
            else
            {
                std::vector<std::vector<int>> canonicas = generarRutasCanonicas(5, origen);
                registrarResultado(txtResultadoDiagnostico, resultado.rutaSugerida == canonicas.front(), L"El empate conserva la primera ruta canonica");
            }

            registrarResultado(txtResultadoDiagnostico, normalizadas, L"Todos los extremos estan normalizados");
            registrarResultado(txtResultadoDiagnostico, conexionesUnicas.size() == resultado.conexionesFaltantes.size(), L"No existen conexiones faltantes duplicadas");
            bool grafoIntacto = grafo.getCantidadNodos() == nodosAntes
                && grafo.getMatrizAdyacencia() == adyacenciaAntes
                && grafo.getMatrizPesos(Metrica::Distancia) == distanciaAntes
                && grafo.getMatrizPesos(Metrica::Tiempo) == tiempoAntes
                && grafo.getMatrizPesos(Metrica::Costo) == costoAntes;
            registrarResultado(txtResultadoDiagnostico, grafoIntacto, L"El diagnostico no modifico el grafo");
        }
        catch (const std::invalid_argument& error)
        {
            registrarExcepcion(txtResultadoDiagnostico, L"Argumento inesperado", error);
        }
        catch (const std::out_of_range& error)
        {
            registrarExcepcion(txtResultadoDiagnostico, L"Indice inesperado", error);
        }
        catch (const std::logic_error& error)
        {
            registrarExcepcion(txtResultadoDiagnostico, L"Estado inesperado", error);
        }
        catch (const std::overflow_error& error)
        {
            registrarExcepcion(txtResultadoDiagnostico, L"Desbordamiento inesperado", error);
        }
        catch (const std::exception& error)
        {
            registrarExcepcion(txtResultadoDiagnostico, L"Error inesperado", error);
        }
    }

    System::Void TestForm::btnEjecutarTraza_Click(System::Object^, System::EventArgs^)
    {
        try
        {
            if (!ejecutandoTodas)
            {
                txtResultadoTraza->Clear();
            }
            dgvTraza->Rows->Clear();
            int escenario = cmbEscenarioTraza->SelectedIndex;
            Metrica metrica = seleccionarMetrica(cmbMetricaTraza->SelectedIndex);
            std::vector<int> ruta{0, 1, 2, 3, 4, 0};
            Grafo grafo(5);

            switch (escenario)
            {
            case 0:
                grafo = crearGrafoCiclo();
                break;
            case 1:
                grafo = crearGrafoCiclo(true, false, false);
                break;
            case 2:
                grafo = crearGrafoCiclo(false, true, false);
                break;
            case 3:
                grafo = crearGrafoCiclo(false, false, true);
                break;
            case 4:
            {
                bool estructuraRechazada = false;
                try
                {
                    SolucionadorTSP::traceRuta(grafo, std::vector<int>{0, 1, 2}, metrica);
                }
                catch (const std::invalid_argument&)
                {
                    estructuraRechazada = true;
                }
                lblRutaTraza->Text = L"Ruta: 0 -> 1 -> 2";
                lblValidezTraza->Text = L"Validez: excepcion estructural esperada";
                lblValorTraza->Text = L"Valor total: -";
                registrarResultado(txtResultadoTraza, estructuraRechazada, L"La ruta estructuralmente incorrecta fue rechazada");
                return;
            }
            case 5:
            {
                bool desbordamientoRechazado = false;
                try
                {
                    Grafo enorme = crearGrafoCompleto(false, false, true);
                    SolucionadorTSP::traceRuta(enorme, ruta, metrica);
                }
                catch (const std::overflow_error&)
                {
                    desbordamientoRechazado = true;
                }
                lblRutaTraza->Text = L"Ruta: " + textoRuta(ruta);
                lblValidezTraza->Text = L"Validez: excepcion de desbordamiento esperada";
                lblValorTraza->Text = L"Valor total: -";
                registrarResultado(txtResultadoTraza, desbordamientoRechazado, L"La traza rechazo el desbordamiento de double");
                return;
            }
            default:
                throw std::invalid_argument("Escenario de traza no reconocido.");
            }

            TrazaRutaTSP traza = SolucionadorTSP::traceRuta(grafo, ruta, metrica);
            lblRutaTraza->Text = L"Ruta: " + textoRuta(traza.ruta);
            lblValidezTraza->Text = L"Validez: " + (traza.valida ? L"Valida" : L"Invalida");
            lblValorTraza->Text = L"Valor total: " + traza.valorTotal.ToString(L"0.##");

            for (const PasoConexionTSP& paso : traza.pasos)
            {
                dgvTraza->Rows->Add(
                    static_cast<int>(paso.indiceConexion + 1),
                    paso.origen,
                    paso.destino,
                    paso.conexionExiste ? L"Si" : L"No",
                    paso.peso.ToString(L"0.##"),
                    paso.valorAcumulado.ToString(L"0.##"));
            }

            std::size_t pasosEsperados = escenario == 1 ? 1 : (escenario == 2 ? 3 : 5);
            registrarResultado(txtResultadoTraza, traza.pasos.size() == pasosEsperados, L"La traza se detuvo en el paso esperado");
            registrarResultado(txtResultadoTraza, traza.ruta == ruta, L"La secuencia original se conservo");
            registrarResultado(txtResultadoTraza, escenario == 0 ? traza.valida : !traza.valida, L"La validez coincide con las conexiones disponibles");
            registrarResultado(txtResultadoTraza, escenario == 0 ? traza.valorTotal > 0.0 : traza.valorTotal == 0.0, L"El valor total respeta la convencion de rutas validas e invalidas");
            if (escenario != 0)
            {
                registrarResultado(txtResultadoTraza, !traza.pasos.back().conexionExiste, L"El ultimo paso registrado identifica la conexion faltante");
            }
        }
        catch (const std::invalid_argument& error)
        {
            registrarExcepcion(txtResultadoTraza, L"Argumento inesperado", error);
        }
        catch (const std::out_of_range& error)
        {
            registrarExcepcion(txtResultadoTraza, L"Indice inesperado", error);
        }
        catch (const std::logic_error& error)
        {
            registrarExcepcion(txtResultadoTraza, L"Estado inesperado", error);
        }
        catch (const std::overflow_error& error)
        {
            registrarExcepcion(txtResultadoTraza, L"Desbordamiento inesperado", error);
        }
        catch (const std::exception& error)
        {
            registrarExcepcion(txtResultadoTraza, L"Error inesperado", error);
        }
    }

    System::Void TestForm::btnEjecutarTodas_Click(System::Object^, System::EventArgs^)
    {
        limpiarResultados();
        ejecutandoTodas = true;

        cmbMetricaGrafo->SelectedIndex = 0;
        cmbEscenarioTSP->SelectedIndex = 0;
        cmbMetricaTSP->SelectedIndex = 0;
        cmbEscenarioDiagnostico->SelectedIndex = 0;
        cmbEscenarioTraza->SelectedIndex = 0;
        cmbMetricaTraza->SelectedIndex = 0;

        txtResultadoGrafo->AppendText(L"[Grafo determinista]" + Environment::NewLine);
        btnProbarGrafo_Click(nullptr, nullptr);
        txtResultadoGrafo->AppendText(Environment::NewLine + L"[Validaciones del grafo]" + Environment::NewLine);
        btnValidacionesGrafo_Click(nullptr, nullptr);

        for (int cantidadNodos = Grafo::MINIMO_NODOS; cantidadNodos <= Grafo::MAXIMO_NODOS; ++cantidadNodos)
        {
            nudNodosRutas->Value = System::Decimal(cantidadNodos);
            nudOrigenRutas->Value = System::Decimal(0);
            txtResultadoRutas->AppendText(String::Format(L"[Rutas canonicas: {0} nodos]", cantidadNodos) + Environment::NewLine);
            btnGenerarRutas_Click(nullptr, nullptr);
            txtResultadoRutas->AppendText(Environment::NewLine);
        }

        for (int escenario = 0; escenario < cmbEscenarioTSP->Items->Count; ++escenario)
        {
            cmbEscenarioTSP->SelectedIndex = escenario;
            txtResultadoTSP->AppendText(L"[" + cmbEscenarioTSP->Text + L"]" + Environment::NewLine);
            btnEjecutarTSP_Click(nullptr, nullptr);
            txtResultadoTSP->AppendText(Environment::NewLine);
        }
        for (int escenario = 0; escenario < cmbEscenarioDiagnostico->Items->Count; ++escenario)
        {
            cmbEscenarioDiagnostico->SelectedIndex = escenario;
            txtResultadoDiagnostico->AppendText(L"[" + cmbEscenarioDiagnostico->Text + L"]" + Environment::NewLine);
            btnEjecutarDiagnostico_Click(nullptr, nullptr);
            txtResultadoDiagnostico->AppendText(Environment::NewLine);
        }
        for (int escenario = 0; escenario < cmbEscenarioTraza->Items->Count; ++escenario)
        {
            cmbEscenarioTraza->SelectedIndex = escenario;
            txtResultadoTraza->AppendText(L"[" + cmbEscenarioTraza->Text + L"]" + Environment::NewLine);
            btnEjecutarTraza_Click(nullptr, nullptr);
            txtResultadoTraza->AppendText(Environment::NewLine);
        }

        ejecutandoTodas = false;
        lblDescripcion->Text = String::Format(
            L"Pruebas ejecutadas: {0} | Aprobadas: {1} | Fallidas: {2}",
            cantidadAprobadas + cantidadFallidas,
            cantidadAprobadas,
            cantidadFallidas);
    }
}
