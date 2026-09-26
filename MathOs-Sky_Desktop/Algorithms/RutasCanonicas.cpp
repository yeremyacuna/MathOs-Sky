#include "RutasCanonicas.h"

#include "../Models/Grafo.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>

namespace MathOsSky
{
    // Genera rutas cerradas unicas en orden desde un origen fijo
    std::vector<std::vector<int>> generarRutasCanonicas(int cantidadNodos, int origen)
    {
        // Valida que la cantidad de nodos y el origen pertenezcan a los rangos permitidos
        if (cantidadNodos < Grafo::MINIMO_NODOS || cantidadNodos > Grafo::MAXIMO_NODOS
            || origen < 0 || origen >= cantidadNodos)
        {
            throw std::invalid_argument("La cantidad de nodos o el origen no son validos.");
        }

        // Calcula (n - 1)! / 2 con std::size_t para representar una cantidad no negativa de rutas
        std::size_t cantidadEsperada = 1;
        for (int factor = 2; factor < cantidadNodos; ++factor)
        {
            cantidadEsperada *= static_cast<std::size_t>(factor);
        }
        cantidadEsperada /= 2; // para evitar duplicados o recorrida de vuelta

        // Reserva anticipadamente memoria para almacenar la cantidad esperada de rutas
        std::vector<std::vector<int>> rutas;
        rutas.reserve(cantidadEsperada);

        // Construye una ruta inicial con capacidad para los nodos y el regreso al origen
        std::vector<int> ruta;
        ruta.reserve(static_cast<std::size_t>(cantidadNodos) + 1);
        ruta.push_back(origen); // Coloca el origen al inicio para fijarlo y eliminar rotaciones equivalentes

        for (int nodo = 0; nodo < cantidadNodos; ++nodo) // aqui por ejemplo hace esto: {0, 1, 2, 3, 4} crea el nodo de conexion
        {
            if (nodo != origen)
            {
                ruta.push_back(nodo);
            }
        }
        // Coloca el origen al final para cerrar cada ruta candidata
        ruta.push_back(origen); // por ultimo aca agrega devuelta el origen para cumplir con el TSP so: {0, 1, 2, 3, 4, 0}

        // Delimita mediante iteradores la parte interior que sera permutada, for example seria { 1, 2, 3, 4 }, eso quiere decir q solo esos 4 nodos sufriran permutaciones de conexion
        std::vector<int>::iterator inicioInterior = ruta.begin() + 1;
        std::vector<int>::iterator finInterior = ruta.end() - 1;

        // Genera las permutaciones interiores en orden con std::next_permutation
        do
        {
            // Conserva una sola orientacion entre cada ruta y su inversa
            if (*inicioInterior < *(finInterior - 1))
            {
                rutas.push_back(ruta);
            }
        } while (std::next_permutation(inicioInterior, finInterior)); // libreria agregar: Reorganiza los nodos interiores en el siguiente orden lexicográfico.

        return rutas;
    }
}
