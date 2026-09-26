#pragma once

#include <cstddef>
#include <limits>
#include <vector>

namespace MathOsSky
{
    // struct agrupa una ruta candidata junto con su validez y valor total
    struct RutaEvaluada
    {
        std::vector<int> ruta;
        bool valida = false;
        double valorTotal = 0.0;
    };

    // struct agrupa las rutas evaluadas y el mejor resultado del solucionador TSP
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
