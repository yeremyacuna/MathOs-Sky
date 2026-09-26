#include "SolucionadorTSP.h"
#include "RutasCanonicas.h"
#include <cmath>
#include <cstddef>
#include <limits>
#include <stdexcept>

namespace MathOsSky
{
    // Valida la metrica antes de generar o evaluar rutas
    void SolucionadorTSP::validateMetrica(Metrica metrica)
    {
        switch (metrica)
        {
        case Metrica::Distancia:
        case Metrica::Tiempo:
        case Metrica::Costo:
            return;
        default:
            throw std::invalid_argument("Metrica no reconocida.");
        }
    }

    // Valida que la secuencia represente una ruta hamiltoniana cerrada en el grafo
    void SolucionadorTSP::validateEstructuraRuta(const Grafo& grafo, const std::vector<int>& ruta)
    {
        int cantidadNodos = grafo.getCantidadNodos();
        if (ruta.size() != static_cast<std::size_t>(cantidadNodos + 1))
        {
            throw std::invalid_argument("La ruta debe contener todos los nodos y regresar al origen.");
        }

        if (ruta.front() != ruta.back())
        {
            throw std::invalid_argument("La ruta debe comenzar y terminar en el mismo origen.");
        }

        for (int nodo : ruta)
        {
            if (nodo < 0 || nodo >= cantidadNodos)
            {
                throw std::invalid_argument("La ruta contiene un nodo fuera del grafo.");
            }
        }

        std::vector<int> cantidadVisitas(static_cast<std::size_t>(cantidadNodos), 0);
        for (std::size_t indice = 0; indice + 1 < ruta.size(); ++indice)
        {
            ++cantidadVisitas[static_cast<std::size_t>(ruta[indice])];
        }

        for (int visitas : cantidadVisitas)
        {
            if (visitas != 1)
            {
                throw std::invalid_argument("La ruta debe visitar cada nodo exactamente una vez.");
            }
        }
    }

    // Evalua internamente una ruta canonica mediante las conexiones consecutivas
    RutaEvaluada SolucionadorTSP::evaluateRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica, std::vector<PasoConexionTSP>* pasos)
    {
        RutaEvaluada evaluacion;
        evaluacion.ruta = ruta;
        evaluacion.valida = true;
        evaluacion.valorTotal = 0.0;

        // Recorre cada par de nodos consecutivos incluida la conexion de regreso al origen
        for (std::size_t indice = 1; indice < ruta.size(); ++indice)
        {
            int origen = ruta[indice - 1];
            int destino = ruta[indice];

            // Invalida la ruta y detiene su evaluacion cuando falta una conexion
            if (!grafo.hasConexion(origen, destino))
            {
                if (pasos != nullptr)
                {
                    pasos->push_back(PasoConexionTSP{indice - 1, origen, destino, false, 0.0, evaluacion.valorTotal});
                }
                evaluacion.valida = false;
                evaluacion.valorTotal = 0.0;
                break;
            }

            // Acumula el peso correspondiente a la metrica seleccionada
            double peso = grafo.getPeso(origen, destino, metrica);
            if (evaluacion.valorTotal > std::numeric_limits<double>::max() - peso)
            {
                throw std::overflow_error("El valor acumulado de la ruta excede el rango de double.");
            }

            evaluacion.valorTotal += peso;
            if (!std::isfinite(evaluacion.valorTotal))
            {
                throw std::overflow_error("El valor acumulado de la ruta excede el rango de double.");
            }

            if (pasos != nullptr)
            {
                pasos->push_back(PasoConexionTSP{indice - 1, origen, destino, true, peso, evaluacion.valorTotal});
            }
        }

        return evaluacion;
    }

    // Resuelve internamente el TSP al evaluar todas las rutas canonicas
    ResultadoTSP SolucionadorTSP::solve(const Grafo& grafo, int origen, Metrica metrica)
    {
        validateMetrica(metrica);
        ResultadoTSP resultado;
        int cantidadNodos = grafo.getCantidadNodos();

        // Genera todos los candidatos canonicos desde el origen fijo
        std::vector<std::vector<int>> rutasCanonicas = generarRutasCanonicas(cantidadNodos, origen);
        resultado.cantidadCandidatos = rutasCanonicas.size();

        // Reserva memoria para conservar todas las rutas evaluadas
        resultado.rutas.reserve(resultado.cantidadCandidatos);

        for (const std::vector<int>& ruta : rutasCanonicas)
        {
            RutaEvaluada evaluacion = evaluateRuta(grafo, ruta, metrica, nullptr);

            // Cuenta y compara solamente los ciclos cuyas conexiones existen
            if (evaluacion.valida)
            {
                ++resultado.cantidadCiclosValidos;

                // La comparacion estricta conserva la primera ruta encontrada cuando existe un empate
                if (evaluacion.valorTotal < resultado.mejorValor)
                {
                    resultado.mejorRuta = evaluacion.ruta;
                    resultado.mejorValor = evaluacion.valorTotal;
                }
            }

            resultado.rutas.push_back(evaluacion);
        }

        return resultado;
    }

    // Genera bajo demanda los pasos detallados de una sola ruta
    TrazaRutaTSP SolucionadorTSP::traceRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica)
    {
        validateMetrica(metrica);
        validateEstructuraRuta(grafo, ruta);

        TrazaRutaTSP traza;
        traza.ruta = ruta;
        RutaEvaluada evaluacion = evaluateRuta(grafo, ruta, metrica, &traza.pasos);
        traza.valida = evaluacion.valida;
        traza.valorTotal = evaluacion.valorTotal;
        return traza;
    }
}
