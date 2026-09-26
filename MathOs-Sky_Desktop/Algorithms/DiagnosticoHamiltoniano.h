#pragma once

#include "../Models/Grafo.h"
#include "../Models/TiposDiagnostico.h"

#include <vector>

namespace MathOsSky
{
    // Analiza las conexiones necesarias para completar un ciclo hamiltoniano
    class DiagnosticoHamiltoniano
    {
    private:
        // Devuelve las conexiones faltantes de una ruta sin duplicados y con extremos normalizados
        static std::vector<ConexionFaltante> findConexionesFaltantes(const Grafo& grafo, const std::vector<int>& ruta);

    public:
        // Devuelve el diagnostico hamiltoniano desde un origen fijo
        static ResultadoDiagnosticoHamiltoniano analyze(const Grafo& grafo, int origen);
    };
}
