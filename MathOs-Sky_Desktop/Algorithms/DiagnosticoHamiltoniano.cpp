#include "DiagnosticoHamiltoniano.h"
#include "RutasCanonicas.h"
#include <algorithm>
#include <cstddef>

namespace MathOsSky
{
    // Identifica las conexiones inexistentes entre nodos consecutivos de una ruta cerrada
    std::vector<ConexionFaltante> DiagnosticoHamiltoniano::findConexionesFaltantes(const Grafo& grafo, const std::vector<int>& ruta)
    {
        std::vector<ConexionFaltante> conexionesFaltantes;

        for (std::size_t indice = 1; indice < ruta.size(); ++indice)
        {
            int origen = ruta[indice - 1];
            int destino = ruta[indice];

            if (!grafo.hasConexion(origen, destino))
            {
                // Normaliza los extremos para representar una conexion no dirigida de forma unica
                ConexionFaltante conexion{std::min(origen, destino), std::max(origen, destino)};
                bool estaRegistrada = false;

                // Evita registrar dos veces la misma conexion dentro del diagnostico de una ruta
                for (const ConexionFaltante& registrada : conexionesFaltantes)
                {
                    if (registrada.origen == conexion.origen && registrada.destino == conexion.destino)
                    {
                        estaRegistrada = true;
                        break;
                    }
                }

                if (!estaRegistrada)
                {
                    conexionesFaltantes.push_back(conexion);
                }
            }
        }

        return conexionesFaltantes;
    }

    // Analiza todas las rutas canonicas y conserva la primera con el menor numero de conexiones faltantes
    ResultadoDiagnosticoHamiltoniano DiagnosticoHamiltoniano::analyze(const Grafo& grafo, int origen)
    {
        ResultadoDiagnosticoHamiltoniano resultado;
        std::vector<std::vector<int>> rutasCanonicas = generarRutasCanonicas(grafo.getCantidadNodos(), origen);

        for (const std::vector<int>& ruta : rutasCanonicas)
        {
            std::vector<ConexionFaltante> conexionesFaltantes = findConexionesFaltantes(grafo, ruta);

            // La primera ruta sin conexiones faltantes es el primer ciclo hamiltoniano canonico
            if (conexionesFaltantes.empty())
            {
                resultado.existeCicloHamiltoniano = true;
                resultado.rutaSugerida = ruta;
                resultado.conexionesFaltantes.clear();
                return resultado;
            }

            // La comparacion estricta conserva la primera ruta canonica cuando existe un empate
            if (resultado.rutaSugerida.empty()
                || conexionesFaltantes.size() < resultado.conexionesFaltantes.size())
            {
                resultado.rutaSugerida = ruta;
                resultado.conexionesFaltantes = conexionesFaltantes;
            }
        }

        return resultado;
    }
}
