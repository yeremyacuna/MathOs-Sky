#pragma once

#include "TiposGrafo.h"

#include <vector>

namespace MathOsSky
{
    class Grafo
    {
    private:
        std::vector<std::vector<Conexion>> conexiones;

        void validarNodos(int origen, int destino) const;
        static double seleccionarPeso(const Conexion& conexion, Metrica metrica);

    public:
        using MatrizAdyacencia = std::vector<std::vector<int>>;
        using MatrizPesos = std::vector<std::vector<double>>;

        static constexpr int MINIMO_NODOS = 5;
        static constexpr int MAXIMO_NODOS = 10;

        explicit Grafo(int cantidadNodos);

        int obtenerCantidadNodos() const;

        void agregarConexion(int origen, int destino,
            double distancia, double tiempo, double costo);
        void eliminarConexion(int origen, int destino);

        bool existeConexion(int origen, int destino) const;
        Conexion obtenerConexion(int origen, int destino) const;
        double obtenerPeso(int origen, int destino, Metrica metrica) const;

        MatrizAdyacencia obtenerMatrizAdyacencia() const;
        MatrizPesos obtenerMatrizPesos(Metrica metrica) const;
    };
}
