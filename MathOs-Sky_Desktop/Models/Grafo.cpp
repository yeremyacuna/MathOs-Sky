#include "Grafo.h"

#include <cmath>
#include <stdexcept>

namespace MathOsSky
{
    Grafo::Grafo(int cantidadNodos)
    {
        if (cantidadNodos < MINIMO_NODOS || cantidadNodos > MAXIMO_NODOS)
        {
            throw std::invalid_argument("El grafo debe tener entre 5 y 10 nodos.");
        }

        conexiones.assign(cantidadNodos, std::vector<Conexion>(cantidadNodos));
    }

    int Grafo::obtenerCantidadNodos() const
    {
        return static_cast<int>(conexiones.size());
    }

    void Grafo::validarNodos(int origen, int destino) const
    {
        int cantidadNodos = obtenerCantidadNodos();

        if (origen < 0 || destino < 0 ||
            origen >= cantidadNodos || destino >= cantidadNodos)
        {
            throw std::out_of_range("Identificador de nodo fuera de rango.");
        }
    }

    void Grafo::agregarConexion(int origen, int destino,
        double distancia, double tiempo, double costo)
    {
        validarNodos(origen, destino);

        if (origen == destino)
        {
            throw std::invalid_argument("No se permiten lazos.");
        }

        if (!std::isfinite(distancia) || distancia <= 0.0 ||
            !std::isfinite(tiempo) || tiempo <= 0.0 ||
            !std::isfinite(costo) || costo <= 0.0)
        {
            throw std::invalid_argument(
                "Los tres pesos deben ser finitos y mayores que cero.");
        }

        Conexion conexion{true, distancia, tiempo, costo};
        conexiones[origen][destino] = conexion;
        conexiones[destino][origen] = conexion;
    }

    void Grafo::eliminarConexion(int origen, int destino)
    {
        validarNodos(origen, destino);
        conexiones[origen][destino] = Conexion{};
        conexiones[destino][origen] = Conexion{};
    }

    bool Grafo::existeConexion(int origen, int destino) const
    {
        validarNodos(origen, destino);
        return conexiones[origen][destino].existe;
    }

    Conexion Grafo::obtenerConexion(int origen, int destino) const
    {
        validarNodos(origen, destino);
        return conexiones[origen][destino];
    }

    double Grafo::seleccionarPeso(const Conexion& conexion, Metrica metrica)
    {
        switch (metrica)
        {
        case Metrica::Distancia:
            return conexion.distancia;
        case Metrica::Tiempo:
            return conexion.tiempo;
        case Metrica::Costo:
            return conexion.costo;
        default:
            throw std::invalid_argument("Metrica no reconocida.");
        }
    }

    double Grafo::obtenerPeso(int origen, int destino, Metrica metrica) const
    {
        validarNodos(origen, destino);
        const Conexion& conexion = conexiones[origen][destino];

        if (!conexion.existe)
        {
            throw std::logic_error(
                "No se puede consultar el peso de una conexion inexistente.");
        }

        return seleccionarPeso(conexion, metrica);
    }

    Grafo::MatrizAdyacencia Grafo::obtenerMatrizAdyacencia() const
    {
        int cantidadNodos = obtenerCantidadNodos();
        MatrizAdyacencia matriz(cantidadNodos, std::vector<int>(cantidadNodos, 0));

        for (int origen = 0; origen < cantidadNodos; ++origen)
        {
            for (int destino = 0; destino < cantidadNodos; ++destino)
            {
                matriz[origen][destino] = conexiones[origen][destino].existe ? 1 : 0;
            }
        }

        return matriz;
    }

    Grafo::MatrizPesos Grafo::obtenerMatrizPesos(Metrica metrica) const
    {
        int cantidadNodos = obtenerCantidadNodos();
        MatrizPesos matriz(cantidadNodos, std::vector<double>(cantidadNodos, 0.0));

        for (int origen = 0; origen < cantidadNodos; ++origen)
        {
            for (int destino = 0; destino < cantidadNodos; ++destino)
            {
                matriz[origen][destino] =
                    seleccionarPeso(conexiones[origen][destino], metrica);
            }
        }

        return matriz;
    }
}
