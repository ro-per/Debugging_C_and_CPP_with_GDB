#include <iostream>

/*
This program creates the directed graph as shown on the slide and performs a 
depth first search on it

Output should be:
>> Constructing nodes:
  New Node created
    Node number: 0
  New Node created
    Node number: 1
  New Node created
    Node number: 2
  New Node created
    Node number: 3
  New Node created
    Node number: 4
  New Node created
    Node number: 5
>> Connecting nodes
>> Init finished, printing created graph:
    Node number: 0
    Node number: 1
    Node number: 2
    Node number: 3
    Node number: 4
    Node number: 5
Start DFS at index: 0
    Node number: 0
    Node number: 5
    Node number: 1
    Node number: 4
    Node number: 2
    Node number: 3
>> Printing final graph:
    Node number: 0
    Node number: 1
    Node number: 2
    Node number: 3
    Node number: 4
    Node number: 5

*/

class Node {
    int node_number;
    int connected_nodes_size;
    Node* connected_nodes[2];
    bool DFS_visited;

public:
    Node(): node_number(-1), connected_nodes_size(0), DFS_visited(false){
        std::cout << "  New Node created" << std::endl;
    }

    void set_number(int number){
        node_number = number;
    }

    void print(){
        std::cout << "    Node number: " << node_number << std::endl;
    }

    void DFS(){
        if(!DFS_visited){
            print();
            DFS_visited = true;
            for(int i = 0; i < connected_nodes_size; i++){
                connected_nodes[i]->DFS();
            }
        }
    }

    void connect_to(Node* child){
        if(child != this)
            connected_nodes[connected_nodes_size++] = child;
    }
};

class Graph {
    int node_count;
    Node** nodes_array;

public:
    void init(int node_count){
        this->node_count = node_count;
        Node* nodes[node_count];
        
        std::cout << ">> Constructing nodes:" << std::endl;
        for(int i = 0; i<node_count; i++){
            Node n;
            n.set_number(i);
            nodes[i] = &n;
            n.print();
        }

        std::cout << ">> Connecting nodes" << std::endl;
        for(int i = 0; i<(int)(node_count/2); i++){
            nodes[i]->connect_to(nodes[node_count-i-1]);
        }
        for(int i = 0; i<node_count-1; i++){
            nodes[i]->connect_to(nodes[i+1]);
        }

        this->nodes_array = nodes;

        std::cout << ">> Init finished, printing created graph:" << std::endl;
        print();
    }


    void print(){
        for(int i = 0; i < node_count; i++)
            nodes_array[i]->print();
    }

    void DFS(int start_node_index){
        std::cout << "Start DFS at index: " << start_node_index << std::endl;
        nodes_array[start_node_index]->DFS();
    }

    ~Graph(){}
};

int main(){
    Graph* g = new Graph();
    g->init(6); //graph containing 6 nodes
    g->DFS(0); //DFS starting at index 0

    std::cout << ">> Printing final graph:" << std::endl;
    g->print();
    delete g;
}