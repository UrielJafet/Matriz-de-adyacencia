#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

class CGraph
{
private:
    //Estructura de la matriz de adyacencia
    std::vector<std::vector<int>> adj_matrix_;

    //Mapeo nombre a indice(ej. "paris" = 0)
    std::unordered_map<std::string, int> node_index_;

    //Contador para asignar el sigiente indice (comienza en 0)
    int next_node_ = 0;
    
    //Accede al indice->nombre
    std::vector<std::string> index_to_name_;

public:
// Constructor
    CGraph() :
        adj_matrix_{},
        node_index_{},
        next_node_{0}
    {} 

    // Maneja mapeo de datos y redimenciona la matriz
    int getOrCreateIndex(const std::string& name_node);
    // Agregar una arista junto con su peso
    void addEdge(const std::string& origin, const std::string& destiny, int weight);
    //Muestra la matriz de adyacencia
    void graphMatrix() const;

    // Guarda la matriz en un archivo
    void saveGraph(const std::string& name_archive) const;
    // Importar grafo
    void importGraph(const std::string& name_archive);

    // Grafo de salida y adyacencia de salida
    void degreeOfExit(const std::string& name_node);
    void adyOfExit(const std::string& name_node);


    /*
        Algoritmo Prim
        MST = Minimum Spanning Tree
    */
    int minKey(const std::vector<int>& key, const std::vector<bool>& inMST);
    void primMST();

};