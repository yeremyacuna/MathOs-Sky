#pragma once
#include <vector>

namespace MathOsSky
{
    // struct agrupa los extremos normalizados de una conexion no dirigida faltante
    struct ConexionFaltante
    {
        int origen;
        int destino;
    };

    // struct agrupa el resultado del diagnostico hamiltoniano y la ruta sugerida
    struct ResultadoDiagnosticoHamiltoniano
    {
        bool existeCicloHamiltoniano = false;
        std::vector<int> rutaSugerida;
        std::vector<ConexionFaltante> conexionesFaltantes;
    };
}
