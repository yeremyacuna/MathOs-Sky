#include "SolucionadorTSP.h"

#include "RutasCanonicas.h"

#include <cstddef>

namespace MathOsSky
{
    // Evalua internamente una ruta canonica mediante las conexiones consecutivas
    RutaEvaluada SolucionadorTSP::evaluateRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica)
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
                evaluacion.valida = false;
                evaluacion.valorTotal = 0.0;
                break;
            }

            // Acumula el peso correspondiente a la metrica seleccionada
            evaluacion.valorTotal += grafo.getPeso(origen, destino, metrica);
        }

        return evaluacion;
    }

    // Resuelve internamente el TSP al evaluar todas las rutas canonicas
    ResultadoTSP SolucionadorTSP::solve(const Grafo& grafo, int origen, Metrica metrica)
    {
        ResultadoTSP resultado;
        int cantidadNodos = grafo.getCantidadNodos();

        // Genera todos los candidatos canonicos desde el origen fijo
        std::vector<std::vector<int>> rutasCanonicas = generarRutasCanonicas(cantidadNodos, origen);
        resultado.cantidadCandidatos = rutasCanonicas.size();

        // Reserva memoria para conservar todas las rutas evaluadas
        resultado.rutas.reserve(resultado.cantidadCandidatos);

        for (const std::vector<int>& ruta : rutasCanonicas)
        {
            RutaEvaluada evaluacion = evaluateRuta(grafo, ruta, metrica);

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
}
