#include <iostream>
#include "CGraph.h"

int main()
{
    
    CGraph grafo;

    grafo.getOrCreateIndex("A");
    grafo.getOrCreateIndex("B");
    grafo.getOrCreateIndex("C");
    grafo.getOrCreateIndex("D");

    grafo.addEdge("A","B",10);
    grafo.addEdge("B","C",30);
    grafo.addEdge("C","D",20);
    grafo.addEdge("D","A",60);

    grafo.graphMatrix();
    grafo.degreeOfExit("A");
    grafo.adyOfExit("A");


    grafo.saveGraph("prueba.txt");

    grafo.importGraph("prueba2.txt");

    grafo.graphMatrix();
    grafo.degreeOfExit("Paris");
    grafo.adyOfExit("Paris");

    
    return 0;
}