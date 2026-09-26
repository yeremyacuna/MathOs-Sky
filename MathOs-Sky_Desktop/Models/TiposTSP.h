#pragma once
#include <cstddef>
#include <limits>
#include <vector>

namespace MathOsSky
{
    // struct agrupa una ruta candidata junto con su validez y valor total; representa el resultado de evaluar una sola ruta.
    struct RutaEvaluada
    {
        std::vector<int> ruta;
        bool valida = false;
        double valorTotal = 0.0;
    };

    // struct agrupa las rutas evaluadas y el mejor resultado del solucionador TSP, mientras RutaEvaluada representa una sola ruta, ResultadoTSP representa todo el proceso.
    struct ResultadoTSP
    {
        std::vector<RutaEvaluada> rutas;
        std::vector<int> mejorRuta;
        // infinity representa la ausencia inicial de un mejor valor finito
        double mejorValor = std::numeric_limits<double>::infinity();
        // std::size_t representa cantidades no negativas compatibles con el tamano de los vectores
        std::size_t cantidadCandidatos = 0;
        std::size_t cantidadCiclosValidos = 0;
    };
}
