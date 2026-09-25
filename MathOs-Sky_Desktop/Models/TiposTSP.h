#pragma once

#include <cstddef>
#include <limits>
#include <vector>

namespace MathOsSky
{
    struct RutaEvaluada
    {
        std::vector<int> ruta;
        bool valida = false;
        double valorTotal = 0.0;
    };

    struct ResultadoTSP
    {
        std::vector<RutaEvaluada> rutas;
        std::vector<int> mejorRuta;
        double mejorValor = std::numeric_limits<double>::infinity();
        std::size_t cantidadCandidatos = 0;
        std::size_t cantidadCiclosValidos = 0;
    };
}
