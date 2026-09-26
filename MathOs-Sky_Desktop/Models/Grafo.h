#pragma once

#include "TiposGrafo.h"

#include <vector>

namespace MathOsSky
{
    // Representa un grafo no dirigido con pesos de distancia tiempo y costo
    class Grafo
    {
    private:
        // Almacena las conexiones del grafo mediante una matriz cuadrada
        std::vector<std::vector<Conexion>> conexiones;

        // Verifica que los nodos indicados pertenezcan al rango del grafo
        void validateNodos(int origen, int destino) const;

        // Selecciona un peso mientras static evita depender de un objeto y const Conexion& evita copiar o modificar la conexion
        static double selectPeso(const Conexion& conexion, Metrica metrica);

    public:
        // using crea nombres cortos para representar los tipos de matrices utilizados
        using MatrizAdyacencia = std::vector<std::vector<int>>;
        using MatrizPesos = std::vector<std::vector<double>>;

        // static comparte los limites entre todos los objetos y constexpr los mantiene constantes desde la compilacion
        static constexpr int MINIMO_NODOS = 5;
        static constexpr int MAXIMO_NODOS = 10;

        // Construye un grafo de 5 a 10 nodos mientras explicit evita conversiones automaticas desde un entero
        explicit Grafo(int cantidadNodos);

        // Agrega una conexion no dirigida o reemplaza sus pesos y genera una excepcion si los datos son invalidos
        void addConexion(int origen, int destino, double distancia, double tiempo, double costo);

        // Elimina la conexion existente entre dos nodos
        void removeConexion(int origen, int destino);

        // Devuelve la cantidad de nodos mientras const indica que la consulta no modifica el grafo
        int getCantidadNodos() const;

        // Devuelve true cuando existe una conexion entre los nodos indicados
        bool hasConexion(int origen, int destino) const;

        // Devuelve todos los datos almacenados en una conexion
        Conexion getConexion(int origen, int destino) const;

        // Devuelve el peso correspondiente a la metrica seleccionada
        double getPeso(int origen, int destino, Metrica metrica) const;

        // Construye una matriz que representa con 1 o 0 la existencia de conexiones
        MatrizAdyacencia getMatrizAdyacencia() const;

        // Construye una matriz con los pesos de la metrica seleccionada
        MatrizPesos getMatrizPesos(Metrica metrica) const;
    };
}