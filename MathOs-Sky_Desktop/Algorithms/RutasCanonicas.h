#pragma once

#include <vector>

namespace MathOsSky
{
    // Genera rutas cerradas unicas desde un origen fijo y elimina equivalencias por rotacion e inversion
    std::vector<std::vector<int>> generarRutasCanonicas(int cantidadNodos, int origen);
}
