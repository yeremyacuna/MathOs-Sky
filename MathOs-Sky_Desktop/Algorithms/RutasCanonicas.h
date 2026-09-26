#pragma once

#include <vector>

namespace MathOsSky
{
    // Genera las rutas canonicas de un grafo no dirigido desde un origen fijo
    std::vector<std::vector<int>> generarRutasCanonicas(int cantidadNodos, int origen);
}
