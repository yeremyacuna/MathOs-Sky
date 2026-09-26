#pragma once

// namespace agrupa las clases y estructuras pertenecientes al proyecto MathOs-Sky
namespace MathOsSky
{
    // enum class define las metricas o variables de peso disponibles para evaluar el peso de una conexion
    enum class Metrica
    {
        Distancia,
        Tiempo,
        Costo
    };

    // struct agrupa los datos que representan una conexion entre dos nodos en el grafo, de A hacia B
    struct Conexion
    {
        bool existe = false;
        double distancia = 0.0;
        double tiempo = 0.0;
        double costo = 0.0;
    };
}