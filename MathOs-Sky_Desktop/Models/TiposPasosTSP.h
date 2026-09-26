#pragma once
#include <cstddef>
#include <vector>

namespace MathOsSky
{
    // struct agrupa el resultado de inspeccionar una conexion durante la evaluacion de una ruta
    struct PasoConexionTSP
    {
        std::size_t indiceConexion = 0;
        int origen = -1;
        int destino = -1;
        bool conexionExiste = false;
        double peso = 0.0;
        double valorAcumulado = 0.0;
    };

    // struct agrupa la evaluacion detallada y bajo demanda de una sola ruta
    struct TrazaRutaTSP
    {
        std::vector<int> ruta;
        std::vector<PasoConexionTSP> pasos;
        bool valida = false;
        double valorTotal = 0.0;
    };
}
