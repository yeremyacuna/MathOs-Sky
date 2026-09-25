#pragma once

namespace MathOsSky
{
    enum class Metrica
    {
        Distancia,
        Tiempo,
        Costo
    };

    struct Conexion
    {
        bool existe = false;
        double distancia = 0.0;
        double tiempo = 0.0;
        double costo = 0.0;
    };
}
