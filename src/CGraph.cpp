#include "CGraph.h"

int CGraph :: getOrCreateIndex(const std::string& name_node)
{
    //Verifica si existe o no el nodo
    if(node_index_.count(name_node)){
        return node_index_[name_node];
    }

    /*LOGICA DE CREACION Y REDIMENSION*/

    int new_index = next_node_ ++;//El indice crece en 1
    node_index_[name_node] = new_index;//Le asignamos el nuevo indice al nodo
    
    //Guarda el nombre en el indice 'new_index'
    index_to_name_.push_back(name_node);    
   
    // N es igual al tamaño del siguiente indice (ej. 0-1-2-3-...)
    int N_nuevo = next_node_;



    // Agregamos la nueva FILA (el tamaño de N)
    // Le agremgamos 0 al vector 
    adj_matrix_.emplace_back(N_nuevo, 0);

    //Agregamos la nueva COLUMNA a las filas existentes
    // Recorremos las filas existentes (desde 0 hasta N_nuevo-1)
    for(int i = 0; i < N_nuevo -1; i++)
    {
        adj_matrix_[i].push_back(0);
    }

    return new_index;
}

void CGraph :: addEdge(const std::string& origin, const std::string& destiny, int weight)
{
    //Obtenemos los indices de los nodos con unordered_map
    int index_origin = getOrCreateIndex(origin);
    int index_destiny = getOrCreateIndex(destiny);

    //Asignamos el valor a la matriz con el indice
    adj_matrix_[index_origin][index_destiny] = weight;
}

void CGraph :: graphMatrix() const{
    int n_nodes = next_node_;

    if(n_nodes == 0){
        std::cout << "El grafo esta vacio";
        return;
    }


    /*--- Imprimir el encabezado (columnas) ---*/
    std::cout << std::setw(10) << "";

    for(int i = 0; i < n_nodes; i++)
    {// Imprime los nombres de los nodos destino
        std::cout << std::setw(10) << index_to_name_[i];
    }
    std::cout << "\n";
    /*--- Imprimir Filas y Contenido ---*/
    for(int i = 0; i < n_nodes; i++){
        // Imprimir etiqueta de fila (Nodo de Origen)
        std::cout << std::setw(10) << index_to_name_[i] << "|";
        // Imprimir los valores de la matriz
        for(int j = 0; j < n_nodes; j++){
            std::cout << std::setw(10) << adj_matrix_[i][j];
        }
        std::cout << "\n";
    }
}

void CGraph :: saveGraph(const std::string& name_archive) const
{
    // Abrir el archivo
    std::ofstream archivo(name_archive);

    if(!archivo.is_open()){
        std::cerr << "Error: No se pudo abrir el archivo:  " << name_archive << "\n";
        return;
    }

    int N = next_node_;
    
    // Recorrer la matriz y escribir las aristas
    // Doble bucle (for anidado) para revisar todas las posibles conexiones A[i][j]
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int peso = adj_matrix_[i][j];
            // Si la celda es mayor a 0, existe una arista.
            if(peso > 0){
                const std::string& origen = index_to_name_[i];
                const std::string& destino = index_to_name_[j];

                archivo << origen << " " << destino;
                // Si el peso es diferente de 1, añadirlo como etiqueta
                if(peso != 1){
                    archivo << " " << peso;
                }
                archivo << "\n";
            }
        }
    }

    std::cout << "El archivo " << name_archive << " fue generado con exito\n";

}

void CGraph :: importGraph(const std::string& name_archive)
{
    //LIMPIEZA/RESET DEL ESTADO ANTERIOR
    adj_matrix_.clear(); 
    node_index_.clear();
    index_to_name_.clear();
    next_node_ = 0;

    // Abrir el archivo
    std::ifstream archivo(name_archive);

    if(!archivo.is_open()){
        std::cerr << "Error: No se pudo abrir el archivo:  " << name_archive << "\n";
        return;
    }

    std::string line;
    int line_number = 0;

    while(std::getline(archivo, line))
    {
        line_number ++;
        // Ignorar líneas vacías o de comentario
        if (line.empty() || line[0] == '#') continue;

        // Usar stringstream para parsear los valores dentro de la línea
        std::stringstream ss(line);

        std::string origen, destino;
        int peso;

        if (ss >> origen >> destino >> peso){
            addEdge(origen, destino, peso);
        }else {
            std::cerr << "Advertencia: Formato incorrecto en la línea " 
                      << line_number << ". Línea ignorada.\n";
        }
    }
    std::cout << "Carga de grafo finalizada. Total de nodos: " << next_node_ << "\n";

}

void CGraph :: degreeOfExit(const std::string& name_node)
{
    if(node_index_.find(name_node) == node_index_.end()){
        std::cerr << "ERROR: El nodo " << name_node << " no exste";
    }

    // Usamos .at() para consuktar el nodo
    int index_i = node_index_.at(name_node);
     
    int degree_exit_ = 0;
    int N = next_node_;

    // Recorrer la fila [indice_i] de columna j=0 hasta N-1
    for(int j = 0; j < N; j++){
        int value = adj_matrix_[index_i][j];

        if(value > 0)
            degree_exit_++;

    }

    std::cout << "El grado de salida de " << name_node << " es: " << degree_exit_ << std::endl;

}

void CGraph :: adyOfExit(const std::string& name_node)
{
    if(node_index_.find(name_node) == node_index_.end()){
        std::cerr << "ERROR: El nodo " << name_node << " no exste";
    }

    // Usamos .at() para consuktar el nodo
    int index_i = node_index_.at(name_node);
    int N = next_node_;

    // Se usa un vector para almacenar todos los nombres 
    std::vector<std::string> vecinos;

    // Recorrer la fila [indice_i] de columna j=0 hasta N-1
    for(int j = 0; j < N; j++){
        int value = adj_matrix_[index_i][j];

        if(value > 0)
            vecinos.push_back(index_to_name_[j]);

    }

    std::cout << "La adyacencia de salida de " << name_node << " es: ";
    if (vecinos.empty()) {
        std::cout << "Ninguno" << std::endl;
    } else {
        // Recorrer el vector de vecinos e imprimirlos
        for (size_t k = 0; k < vecinos.size(); ++k) {
            std::cout << vecinos[k];
            // Agregar una coma si no es el último elemento
            if (k < vecinos.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}