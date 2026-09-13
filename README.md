<div align="center">
  
<img src="https://raw.githubusercontent.com/yeremyacuna/PlaNet/main/PlaNetProject/upc_icon.png" alt="UPC" width="80" height="100" />

# MathOs-Sky

### Planificación de Rutas Académicas mediante el Problema del Agente Viajero

[![Estado](https://img.shields.io/badge/estado-en_desarrollo-orange)](https://github.com/yeremyacuna/MathOs-Sky)
[![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)](https://github.com/yeremyacuna/MathOs-Sky)
[![Windows Forms](https://img.shields.io/badge/Windows_Forms-0078D4?logo=windows&logoColor=white)](https://github.com/yeremyacuna/MathOs-Sky)

**Matemática Computacional** • Universidad Peruana de Ciencias Aplicadas (UPC) • Ciclo 4

[Releases](https://github.com/yeremyacuna/MathOs-Sky/releases) • [Documentación](#descripción) • [Instalación](#instalación)

</div>

---

## Descripción

**MathOs-Sky** es una aplicación que planifica rutas académicas entre departamentos del Perú utilizando grafos no dirigidos y ponderados, ciclos hamiltonianos y el algoritmo de fuerza bruta. El sistema encuentra el recorrido óptimo que permite visitar cada destino una sola vez, regresar al punto de partida y minimizar la distancia, el tiempo o el costo total.

La aplicación representa cada departamento como un nodo y cada conexión disponible como una arista ponderada. El usuario puede crear el grafo manualmente o generarlo de forma aleatoria, consultar su matriz de costos y observar paso a paso cómo se construyen, validan y comparan las rutas posibles.

### Funcionalidades principales

- Creación de grafos no dirigidos y ponderados de 5 a 10 nodos
- Generación manual o aleatoria del grafo
- Selección de la métrica a optimizar:
  - Distancia estimada en kilómetros
  - Tiempo estimado de viaje
  - Costo estimado en soles
- Visualización del grafo y de su matriz de costos
- Identificación de ciclos hamiltonianos mediante fuerza bruta
- Evaluación detallada de cada recorrido posible
- Detección de rutas válidas e inválidas
- Identificación de aristas faltantes cuando no existe un ciclo hamiltoniano
- Cálculo del costo total de cada ciclo encontrado
- Resaltado visual del ciclo hamiltoniano óptimo

---

## Tecnologías

<div align="center">

| Versión Desktop | Versión Web Futura |
|:---------------:|:------------------:|
| ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) | ![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white) |
| ![Windows Forms](https://img.shields.io/badge/Windows_Forms-0078D4?style=for-the-badge&logo=windows&logoColor=white) | ![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white) |
| ![Visual Studio](https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white) | ![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black) |

</div>

> La primera versión evaluada será desarrollada en C++ con Windows Forms. La aplicación web se considera una ampliación posterior.

---

## Equipo de Desarrollo

<table align="center">
  <tr>
    <td align="center">
      <b>Yeremy</b><br>
      <sub><a href="https://github.com/yeremyacuna">@yeremyacuna</a></sub>
    </td>
    <td align="center">
      <b>Katia</b><br>
      <sub><a href="https://github.com/">@katia</a></sub>
    </td>
    <td align="center">
      <b>Melissa</b><br>
      <sub><a href="https://github.com/Melsy23">@Melsy23</a></sub>
    </td>
  </tr>
  <tr>
    <td align="center">
      <b>Salvador</b><br>
      <sub><a href="https://github.com/Salvarcc">@Salvarcc</a></sub>
    </td>
    <td align="center">
      <!-- Celda central -->
    </td>
    <td align="center">
      <b>Samuel</b><br>
      <sub><a href="https://github.com/SamuelR2107">@SamuelR2107</a></sub>
    </td>
  </tr>
</table>

---

## Estructura del Proyecto
MathOs-Sky/
<br>
├── MathOsSky/                  # Aplicación C++ con Windows Forms
<br>
│   ├── Forms/                  # Ventanas e interfaz gráfica
<br>
│   ├── Models/                 # Nodos, aristas, rutas y grafo
<br>
│   ├── Algorithms/             # Fuerza bruta y ciclos hamiltonianos
<br>
│   ├── Services/               # Validación, generación y cálculo
<br>
│   ├── Resources/              # Imágenes y recursos visuales
<br>
│   └── MathOsSky.cpp           # Punto de entrada
<br>
│
<br>
├── docs/                       # Diagramas y documentación
<br>
├── tests/                      # Casos de prueba
<br>
├── README.md                   # Información general del proyecto
<br>
└── .gitignore                  # Exclusiones de Visual Studio y C++

---

## Instalación

### Versión C++ (Windows)

El programa se encuentra actualmente en desarrollo. Cuando se publique la primera versión ejecutable:

1. Descarga el último archivo disponible desde [Releases](https://github.com/yeremyacuna/MathOs-Sky/releases)
2. Extrae el archivo ZIP
3. Ejecuta `MathOs-Sky.exe`

### Compilar desde el código fuente
```bash
# Clonar repositorio
git clone https://github.com/yeremyacuna/MathOs-Sky.git
cd MathOs-Sky

# Abrir la solución en Visual Studio
# Compilar en modo Debug o Release (x64)
```

---

## Contribuciones

Este es un proyecto académico. Los integrantes del Grupo 05 pueden colaborar mediante ramas de trabajo:

1. Crea una rama para la funcionalidad
2. Registra los cambios con commits descriptivos
3. Abre un Pull Request hacia `main`
4. Solicita la revisión de otro integrante antes de fusionar

---

<div align="center">

**Desarrollado por el equipo MathOs-Sky**

</div>
