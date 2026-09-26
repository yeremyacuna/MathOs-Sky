#include "RutasCanonicas.h"

#include "../Models/Grafo.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>

namespace MathOsSky
{
    std::vector<std::vector<int>> generarRutasCanonicas(int cantidadNodos, int origen)
    {
        if (cantidadNodos < Grafo::MINIMO_NODOS || cantidadNodos > Grafo::MAXIMO_NODOS
            || origen < 0 || origen >= cantidadNodos)
        {
            throw std::invalid_argument("La cantidad de nodos o el origen no son validos.");
        }

        std::size_t cantidadEsperada = 1;
        for (int factor = 2; factor < cantidadNodos; ++factor)
        {
            cantidadEsperada *= static_cast<std::size_t>(factor);
        }
        cantidadEsperada /= 2;

        std::vector<std::vector<int>> rutas;
        rutas.reserve(cantidadEsperada);

        std::vector<int> ruta;
        ruta.reserve(static_cast<std::size_t>(cantidadNodos) + 1);
        ruta.push_back(origen);
        for (int nodo = 0; nodo < cantidadNodos; ++nodo)
        {
            if (nodo != origen)
            {
                ruta.push_back(nodo);
            }
        }
        ruta.push_back(origen);

        // Fija el origen para eliminar las rotaciones equivalentes del mismo ciclo
        std::vector<int>::iterator inicioInterior = ruta.begin() + 1;
        std::vector<int>::iterator finInterior = ruta.end() - 1;
        do
        {
            // Conserva una sola orientacion entre cada ruta y su inversa
            if (*inicioInterior < *(finInterior - 1))
            {
                rutas.push_back(ruta);
            }
        } while (std::next_permutation(inicioInterior, finInterior));

        return rutas;
    }
}
