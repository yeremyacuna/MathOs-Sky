<div align="center">

# MathOs-Sky

### Planificador interactivo de rutas académicas mediante el Problema del Agente Viajero

[![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Windows Forms](https://img.shields.io/badge/Windows_Forms-0078D4?logo=windows&logoColor=white)](https://learn.microsoft.com/dotnet/desktop/winforms/)
[![Visual Studio](https://img.shields.io/badge/Visual_Studio-5C2D91?logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com/)

**Matemática Computacional** • Universidad Peruana de Ciencias Aplicadas (UPC) • Ciclo 4

[Descripción](#descripción) • [Funcionalidades](#funcionalidades-principales) • [Tecnologías](#tecnologías) • [Instalación](#instalación)

</div>

---

## Descripción

**MathOs-Sky** es una aplicación académica desarrollada en C++ con Windows Forms para resolver de manera interactiva el **Problema del Agente Viajero** (*Traveling Salesman Problem*, TSP) mediante el algoritmo de fuerza bruta.

El programa modela la gira académica de un profesor por diferentes departamentos del Perú. Cada departamento se representa como un nodo y cada conexión disponible como una arista no dirigida con un peso asociado a la distancia, el tiempo o el costo del recorrido.

El sistema evalúa los ciclos hamiltonianos disponibles, compara sus valores totales y determina la ruta óptima que visita cada destino una sola vez antes de regresar al punto de partida.

### Funcionalidades principales

- Creación de grafos no dirigidos y ponderados de 5 a 10 nodos
- Generación manual o aleatoria del grafo
- Ingreso de pesos asociados a distancia, tiempo o costo
- Representación gráfica y etiquetada de nodos y aristas
- Construcción y visualización de la matriz de costos
- Verificación de la existencia de ciclos hamiltonianos
- Identificación de aristas faltantes cuando no existe un ciclo válido
- Generación y evaluación paso a paso de rutas mediante fuerza bruta
- Cálculo del costo total de cada ciclo hamiltoniano
- Identificación y resaltado visual del recorrido óptimo

---

## Modelo matemático

El problema se representa mediante un grafo ponderado no dirigido:

```text
G = (V, E)
```

donde:

- `V` es el conjunto de departamentos o nodos
- `E` es el conjunto de conexiones o aristas
- `w(u, v)` representa la distancia, el tiempo o el costo entre dos nodos

Para una ruta `R = (v₁, v₂, ..., vₙ, v₁)`, su costo total se obtiene sumando los pesos de todas las aristas recorridas. La solución óptima es el ciclo hamiltoniano válido con el menor costo total.

Al fijar un nodo inicial y considerar equivalentes una ruta y su recorrido inverso, un grafo completo no dirigido de `n` nodos posee:

```text
(n - 1)! / 2
```

ciclos distintos.

---

## Tecnologías

<div align="center">

| Componente | Tecnología |
|:--|:--|
| Lenguaje principal | C++ |
| Interfaz gráfica | Windows Forms |
| Entorno de desarrollo | Microsoft Visual Studio |
| Control de versiones | Git y GitHub |
| Algoritmo principal | Fuerza bruta |
| Estructura matemática | Grafos no dirigidos y ponderados |

</div>

> Una versión web podrá considerarse posteriormente como ampliación del proyecto. La primera versión evaluada será desarrollada en C++ con Windows Forms.

---

## Equipo de desarrollo

Proyecto académico desarrollado por el **Grupo 05** del curso Matemática Computacional.

---

## Estructura prevista del proyecto

```text
MathOs-Sky/
├── MathOsSky/
│   ├── Forms/                  # Formularios e interfaz gráfica
│   ├── Models/                 # Nodos, aristas, rutas y grafo
│   ├── Algorithms/             # Fuerza bruta y validación hamiltoniana
│   ├── Services/               # Generación, validación y cálculo de datos
│   ├── Resources/              # Imágenes y recursos visuales
│   └── MathOsSky.cpp           # Punto de entrada
├── docs/                       # Diagramas y documentación
├── tests/                      # Casos de prueba
├── README.md
└── .gitignore
```

La estructura podrá ajustarse conforme avance la implementación.

---

## Instalación

### Requisitos

- Windows 10 o superior
- Microsoft Visual Studio con las herramientas de desarrollo para C++
- Soporte para C++/CLI y Windows Forms

### Clonar el repositorio

```bash
git clone https://github.com/yeremyacuna/MathOs-Sky.git
cd MathOs-Sky
```

Cuando la solución de Visual Studio esté disponible, podrá abrirse desde su archivo de solución y compilarse en modo `Debug` o `Release`.

---

## Estado del proyecto

El proyecto se encuentra en desarrollo como parte del curso **1AMA0726 – Matemática Computacional**. La primera entrega incluye el planteamiento, la metodología, el avance funcional del programa y la implementación parcial del algoritmo.

---

## Contribuciones

Este es un proyecto académico del Grupo 05. Las modificaciones del equipo deben realizarse mediante ramas de trabajo y revisarse antes de integrarse en la rama `main`.

---

<div align="center">

**Desarrollado por el equipo MathOs-Sky**

</div>
