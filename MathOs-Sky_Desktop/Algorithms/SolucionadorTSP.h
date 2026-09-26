#pragma once

#include "../Models/Grafo.h"
#include "../Models/TiposGrafo.h"
#include "../Models/TiposTSP.h"

#include <vector>

namespace MathOsSky
{
    // Resuelve el problema del agente viajero mediante fuerza bruta
    class SolucionadorTSP
    {
    private:
        static RutaEvaluada evaluateRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica); // Evalua una ruta canonica con la metrica seleccionada

    public:
        static ResultadoTSP solve(const Grafo& grafo, int origen, Metrica metrica); // Resuelve el TSP desde un origen fijo y devuelve todas las rutas evaluadas y la mejor solucion

    };
}
