#pragma once
#include "TiposGrafo.h"
#include <vector>

namespace MathOsSky
{
    // Representa un grafo no dirigido con pesos de distancia, tiempo y costo
    class Grafo
    {
    private:
        
        std::vector<std::vector<Conexion>> conexiones; // Almacena las conexiones del grafo mediante una matriz cuadrada

        void validateNodos(int origen, int destino) const; // Verifica que los nodos indicados pertenezcan al rango del grafo
        static double selectPeso(const Conexion& conexion, Metrica metrica); // Selecciona un peso mientras static evita depender de un objeto y const Conexion& evita copiar o modificar la conexion

    public:
        explicit Grafo(int cantidadNodos); // Construye un grafo de 5 a 10 nodos mientras explicit evita conversiones automaticas desde un entero

        // using crea nombres cortos para representar los tipos de matrices utilizados, for example, si uso matrizPesos quiere decir que es un vector<vector> de tipo double
        using MatrizAdyacencia = std::vector<std::vector<int>>;
        using MatrizPesos = std::vector<std::vector<double>>;

        // static comparte los limites entre todos los objetos y constexpr los mantiene constantes desde la compilacion
        static constexpr int MINIMO_NODOS = 5;
        static constexpr int MAXIMO_NODOS = 10;

        void addConexion(int origen, int destino, double distancia, double tiempo, double costo); // Agrega una conexion no dirigida o reemplaza sus pesos y genera una excepcion si los datos son invalidos
        void removeConexion(int origen, int destino); // Elimina la conexion existente entre dos nodos
        bool hasConexion(int origen, int destino) const; // Devuelve true cuando existe una conexion entre los nodos indicados

        int getCantidadNodos() const; // Devuelve la cantidad de nodos
        Conexion getConexion(int origen, int destino) const; // Devuelve todos los datos almacenados en una conexion
        double getPeso(int origen, int destino, Metrica metrica) const; // Devuelve el peso correspondiente a la metrica seleccionada

        // Devuelve una matriz que representa con 1 o 0 las conexiones del grafo
        MatrizAdyacencia getMatrizAdyacencia() const;
        // Devuelve una matriz con los pesos de la metrica seleccionada
        MatrizPesos getMatrizPesos(Metrica metrica) const;
    };
}