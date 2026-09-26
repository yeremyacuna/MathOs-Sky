#pragma once
#include <vector>

namespace MathOsSky
{
    std::vector<std::vector<int>> generarRutasCanonicas(int cantidadNodos, int origen); // Genera rutas cerradas unicas desde un origen fijo y elimina equivalencias por rotacion e inversion
}
