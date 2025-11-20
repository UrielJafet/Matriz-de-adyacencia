# Implementación de Grafo Dirigido en C++  

Este proyecto implementa una **estructura de grafo dirigido** en C++ utilizando una **matriz de adyacencia dinámica**.  
Permite **crear nodos y aristas**, **guardar el grafo en un archivo**, **importar desde un archivo externo**,  
y analizar la **adyacencia** y el **grado de salida** de cualquier nodo.

---

## 🚀 Características
- Inserción automática de nodos mediante `getOrCreateIndex`.  
- Creación de aristas dirigidas con peso (`addEdge`).  
- Representación mediante **matriz de adyacencia redimensionable**.  
- Impresión formateada del grafo en consola (`graphMatrix`).  
- Guardado del grafo en archivo de texto (`saveGraph`).  
- Carga desde archivo externo con validación de formato (`importGraph`).  
- Cálculo del **grado de salida** de un nodo (`degreeOfExit`).  
- Obtención de la **adyacencia de salida** (`adyOfExit`).
- Recorridos del grafo:
  - BFS (Recorrido por anchura).
  - DFS (Recorrido por profundidad).
  - DLS (Depth Limited Search).
  - IDDFS (Iterative Deepening Depth-First Search).
- Algoritmo de Prim para generar el Árbol de Expansión Mínima.

---

## 🗂️ Estructura del proyecto
- **CGraph.h / CGraph.cpp** → Implementación principal del grafo y sus operaciones.  
- **main.cpp** → Archivo de prueba donde se crean, guardan e importan grafos.  
- **graph.txt** → Archivo de ejemplo generado automáticamente con las aristas.  

---

## ⚙️ Compilación y ejecución
### Usando g++
```bash
g++ -Iinclude src/*.cpp main.cpp -o graph
./graph
