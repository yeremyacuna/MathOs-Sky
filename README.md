<div align="center">
  
<img src="MathOs-Sky_Desktop/Resources/upc_icon.png" alt="UPC" width="120" height="118" />

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

La aplicación representa cada destino como un nodo y cada conexión disponible como una arista ponderada. El núcleo matemático ya permite construir grafos desde código, generar ciclos canónicos, resolver el TSP, diagnosticar conexiones faltantes e inspeccionar una ruta paso a paso. La selección de departamentos, la creación manual o aleatoria y la integración con la interfaz final permanecen en desarrollo.

### Estado actual

- Grafo no dirigido y ponderado de 5 a 10 nodos
- Pesos positivos y finitos para tres métricas:
  - Distancia estimada en kilómetros
  - Tiempo estimado de viaje
  - Costo estimado en soles
- Matrices de adyacencia, distancia, tiempo y costo
- Rutas canónicas con origen fijo y eliminación de ciclos inversos
- Solucionador TSP por fuerza bruta
- Detección de rutas válidas e inválidas
- Selección determinista del ciclo mínimo según la métrica elegida
- Diagnóstico de las conexiones mínimas faltantes
- Evaluación detallada bajo demanda de una ruta
- Formulario interno `TestForm` para pruebas visuales del núcleo

### Funcionalidades pendientes

- Catálogo definitivo de departamentos del Perú y prevención de selecciones repetidas
- Construcción manual y generación aleatoria desde la aplicación
- Capa `Services` para comunicar la interfaz con el núcleo
- Integración de los resultados con `MainForm`
- Visualización final del grafo y reproducción interactiva
- Pruebas automatizadas permanentes

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

```text
MathOs-Sky/
├── MathOs-Sky.slnx
├── MathOs-Sky_Desktop/
│   ├── Forms/                  # Interfaz Windows Forms
│   ├── Models/                 # Grafo y contratos de resultados
│   ├── Algorithms/             # Rutas, TSP, diagnóstico y trazas
│   ├── Services/               # Reservado para la integración futura
│   ├── Resources/              # Recursos visuales
│   └── main.cpp                # Punto de entrada
├── tests/
│   ├── TestForm.h              # Consola visual interna
│   ├── TestForm.cpp
│   └── TestForm.resx
├── docs/
├── MathOs-Sky_Web/             # Ampliación futura
└── README.md
```

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

### Consola visual de pruebas

`MainForm` continúa siendo el formulario predeterminado. Para abrir la consola interna de pruebas:

La aplicacion abre `MainForm` de manera predeterminada. Para ejecutar temporalmente la consola visual, comenta la linea de `MainForm` en `main.cpp` y descomenta la linea de `TestForm`; al terminar la prueba, restaura ambas lineas.

`TestForm` utiliza directamente las APIs de `Models` y `Algorithms`. No sustituye las futuras pruebas automatizadas ni forma parte de la interfaz final.

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
