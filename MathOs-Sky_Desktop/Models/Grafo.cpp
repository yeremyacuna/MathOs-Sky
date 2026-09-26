#include "Grafo.h"
#include <cmath>
#include <stdexcept>

namespace MathOsSky
{
    // Construye un grafo con una cantidad de nodos dentro del rango permitido
    Grafo::Grafo(int cantidadNodos)
    {
        // Valida la cantidad permitida de nodos antes de construir el grafo
        if (cantidadNodos < MINIMO_NODOS || cantidadNodos > MAXIMO_NODOS)
        {
            // throw interrumpe la construccion cuando la cantidad no pertenece al rango permitido
            throw std::invalid_argument("El grafo debe tener entre 5 y 10 nodos.");
        }

        // Inicializa una matriz cuadrada con conexiones vacias
        conexiones.assign(cantidadNodos, std::vector<Conexion>(cantidadNodos));
    }

    // Devuelve la cantidad de nodos almacenados en el grafo
    int Grafo::getCantidadNodos() const
    {
        // static_cast<int> convierte el tamano del vector al tipo usado por la API
        return static_cast<int>(conexiones.size());
    }

    // Valida que origen y destino pertenezcan al rango del grafo
    void Grafo::validateNodos(int origen, int destino) const
    {
        int cantidadNodos = getCantidadNodos();

        // Verifica los limites inferior y superior de ambos nodos
        if (origen < 0 || destino < 0 ||
            origen >= cantidadNodos || destino >= cantidadNodos)
        {
            throw std::out_of_range("Identificador de nodo fuera de rango.");
        }
    }

    // Agrega una conexion no dirigida o reemplaza sus pesos
    void Grafo::addConexion(int origen, int destino, double distancia, double tiempo, double costo)
    {
        validateNodos(origen, destino);

        // Rechaza los lazos que conectan un nodo consigo mismo
        if (origen == destino)
        {
            throw std::invalid_argument("No se permiten lazos.");
        }

        // std::isfinite descarta infinitos y NaN mientras la comparacion exige pesos positivos
        if (!std::isfinite(distancia) || distancia <= 0.0 ||
            !std::isfinite(tiempo) || tiempo <= 0.0 ||
            !std::isfinite(costo) || costo <= 0.0)
        {
            throw std::invalid_argument(
                "Los tres pesos deben ser finitos y mayores que cero.");
        }

        Conexion conexion{true, distancia, tiempo, costo};
        // Almacena la conexion en ambos sentidos para representar un grafo no dirigido
        conexiones[origen][destino] = conexion;
        conexiones[destino][origen] = conexion;
    }

    // Elimina la conexion entre los nodos indicados
    void Grafo::removeConexion(int origen, int destino)
    {
        validateNodos(origen, destino);
        // Elimina ambos sentidos para conservar la simetria del grafo -> Conexion{} crea una conexion con valor default
        conexiones[origen][destino] = Conexion{};
        conexiones[destino][origen] = Conexion{};
    }

    // Verifica si existe una conexion entre los nodos indicados
    bool Grafo::hasConexion(int origen, int destino) const
    {
        validateNodos(origen, destino);
        return conexiones[origen][destino].existe;
    }

    // Selecciona el peso correspondiente a la metrica indicada
    double Grafo::selectPeso(const Conexion& conexion, Metrica metrica)
    {
        // switch relaciona cada metrica con su peso dentro de la conexion
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

    // Devuelve todos los datos almacenados en una conexion
    Conexion Grafo::getConexion(int origen, int destino) const
    {
        validateNodos(origen, destino);
        return conexiones[origen][destino];
    }

    // Devuelve el peso de una conexion segun la metrica indicada
    double Grafo::getPeso(int origen, int destino, Metrica metrica) const
    {
        validateNodos(origen, destino);
        // const Conexion& evita copiar la conexion y tambien impide modificarla
        const Conexion& conexion = conexiones[origen][destino];

        // Rechaza la consulta de pesos cuando la conexion no existe
        if (!conexion.existe)
        {
            throw std::logic_error(
                "No se puede consultar el peso de una conexion inexistente.");
        }

        return selectPeso(conexion, metrica);
    }

    // Construye la matriz de adyacencia a partir de las conexiones del grafo
    Grafo::MatrizAdyacencia Grafo::getMatrizAdyacencia() const
    {
        int cantidadNodos = getCantidadNodos();
        // Construye una matriz cuadrada inicializada con ceros
        MatrizAdyacencia matriz(cantidadNodos, std::vector<int>(cantidadNodos, 0));

        for (int origen = 0; origen < cantidadNodos; ++origen)
        {
            for (int destino = 0; destino < cantidadNodos; ++destino)
            {
                // El operador ternario representa cada conexion con 1 y cada ausencia con 0
                matriz[origen][destino] = conexiones[origen][destino].existe ? 1 : 0;
            }
        }

        return matriz;
    }

    // Construye la matriz de pesos correspondiente a la metrica indicada
    Grafo::MatrizPesos Grafo::getMatrizPesos(Metrica metrica) const
    {
        int cantidadNodos = getCantidadNodos();
        // Construye una matriz cuadrada inicializada con pesos iguales a cero
        MatrizPesos matriz(cantidadNodos, std::vector<double>(cantidadNodos, 0.0));

        for (int origen = 0; origen < cantidadNodos; ++origen)
        {
            for (int destino = 0; destino < cantidadNodos; ++destino)
            {
                matriz[origen][destino] =
                    selectPeso(conexiones[origen][destino], metrica);
            }
        }

        return matriz;
    }
}
