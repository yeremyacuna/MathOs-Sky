#pragma once
#include "../Models/Grafo.h"
#include "../Models/TiposPasosTSP.h"
#include "../Models/TiposGrafo.h"
#include "../Models/TiposTSP.h"
#include <vector>

namespace MathOsSky
{
    // Resuelve el problema del agente viajero mediante fuerza bruta
    class SolucionadorTSP
    {
    private:
        static void validateMetrica(Metrica metrica); // Valida que la metrica pertenezca a las opciones admitidas
        static void validateEstructuraRuta(const Grafo& grafo, const std::vector<int>& ruta); // Valida la estructura hamiltoniana de una ruta recibida
        static RutaEvaluada evaluateRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica, std::vector<PasoConexionTSP>* pasos); // Evalua una ruta y almacena pasos solamente cuando se solicitan

    public:
        static ResultadoTSP solve(const Grafo& grafo, int origen, Metrica metrica); // Resuelve el TSP desde un origen fijo y devuelve todas las rutas evaluadas y la mejor solucion
        static TrazaRutaTSP traceRuta(const Grafo& grafo, const std::vector<int>& ruta, Metrica metrica); // Devuelve la evaluacion detallada de una sola ruta

    };
}
