#include <iostream>
#include "CGraph.h"

int main()
{
    
    CGraph grafo;

    grafo.getOrCreateIndex("A");
    grafo.getOrCreateIndex("B");
    grafo.getOrCreateIndex("C");
    grafo.getOrCreateIndex("D");
    grafo.getOrCreateIndex("F");

    grafo.addEdge("A","B",7);
    grafo.addEdge("A","C",9);
    grafo.addEdge("A","F",14);
    grafo.addEdge("B","C",10);
    grafo.addEdge("B","D",15);
    grafo.addEdge("C","D",11);
    grafo.addEdge("C","F",2);
    grafo.addEdge("F","E",9);
    grafo.addEdge("D","E",6);

    grafo.graphMatrix();
    std::cout <<"\n";

    grafo.primMST();
    std::cout <<"\n";
    grafo.bfs("A", "F");
    std::cout <<"\n";
    grafo.dfs("A", "D");
    std::cout <<"\n";
    grafo.dls("A","D", 1);
    std::cout <<"\n";

    grafo.idffs("A","D");

    /*grafo.getOrCreateIndex("A");
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
    grafo.adyOfExit("Paris");*/
    
    return 0;
}