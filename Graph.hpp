#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <sstream>



#include "Queue.hpp"
#include "Stack.hpp" 
#include "List.hpp"

enum STATUS {FAILED = 0, SUCCESS = 1};

class Graph {
private:
    struct edgeNode {
        int v;
        edgeNode(int v_) : v{v_} {}
        edgeNode() : v{0} {}
    };

    int n_vertices;
    int n_edges;
    List<edgeNode *> *adjList;

    Graph() : n_vertices{0}, n_edges{0}, adjList{nullptr} {}

public:
    static Graph* create_graph(std::string path);
    void bfs(int s);
    void dfs(int s);
    void print();
    ~Graph() {
        if (adjList) {
            for (int i = 0; i < n_vertices; ++i) {
                edgeNode *node;
                for (bool status = adjList[i].begin(node); status != false; status = adjList[i].getNext(node)) {
                    delete node;
                }
            }
            delete[] adjList;
        }
    }
};

Graph* Graph::create_graph(std::string path)
{
    std::ifstream in{path};

    if (!in) {
        std::cerr << "File Open Failed " << std::endl;
        std::cerr << "Check File : " << path << std::endl;
        return nullptr;
    }

    Graph *G = new Graph();
    std::string line;
    int u, v;
    int n_vertices_, n_edges_;

    if (!std::getline(in, line)) {
        std::cerr << "Vertex Information Missing " << std::endl;
        delete G;
        return nullptr;
    }
    {
        std::istringstream iss(line);
        if (!(iss >> n_vertices_) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Vertex Information Missing : Instead found " << line << '\n';
            delete G;
            return nullptr;
        }
    }

    if (!std::getline(in, line)) {
        std::cerr << "Edge Information Missing" << std::endl;
        delete G;
        return nullptr;
    }
    {
        std::istringstream iss(line);
        if (!(iss >> n_edges_) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Edge Information Missing : Instead Found  " << line << '\n';
            delete G;
            return nullptr;
        }
    }

    std::cout << "n_vertices : " << n_vertices_ << " " << "n_edges : " << n_edges_ << std::endl;

    G->adjList = new List<edgeNode *>[n_vertices_];
    G->n_vertices = n_vertices_;
    G->n_edges = n_edges_;

    edgeNode *node;

    while (std::getline(in, line)) {
        std::istringstream iss(line);

        if (!(iss >> u >> v) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Parsing Failed : Check Content for Format " << std::endl;
            continue;
        }
        if ((u >= n_vertices_) || (v >= n_vertices_)) {
            std::cerr << "Nodes Should be between " << 0 << " and " << n_vertices_ - 1 << std::endl;
            delete G;
            return nullptr;
        }

        node = new edgeNode(v);
        G->adjList[u].add(node);
    }
    return G;
}

void Graph::print()
{
    edgeNode *node;

    for (int u = 0; u < n_vertices; u++) {
        std::cout << u << " : ";
        for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
            std::cout << node->v << " ";
        }
        std::cout << std::endl;
    }
}


void Graph::bfs(int s)
{
    
    bool* visited = new bool[n_vertices];
    for (int i = 0; i < n_vertices; ++i) {
        visited[i] = false;
    }

    
    Queue<int> q;

    visited[s] = true;
    q.enqueue(s); 

    std::cout << "BFS starting from vertex " << s << ": ";

    while (!q.isEmpty()) { 
        int u;
        q.dequeue(u); 
        
        std::cout << u << " ";

        edgeNode *node;
        for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
            int v = node->v;
            if (!visited[v]) {
                visited[v] = true;
                q.enqueue(v); 
            }
        }
    }
    std::cout << std::endl;
    
    
    delete[] visited;
}


void Graph::dfs(int s)
{
    
    bool* visited = new bool[n_vertices];
    for (int i = 0; i < n_vertices; ++i) {
        visited[i] = false;
    }

    
    Stack<int> st;

    st.push(s);

    std::cout << "DFS starting from vertex " << s << ": ";

    while (!st.isEmpty()) { 
        int u;
        st.pop(u); 

        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << " ";

            edgeNode *node;

            for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
                if (!visited[node->v]) {
                    st.push(node->v);
                }
            }
        }
    }
    std::cout << std::endl;

    
    delete[] visited;
}


#endif