#ifndef GRAPHAPP_HPP
#define GRAPHAPP_HPP

#include "Graph.hpp"

namespace GraphSpace{
    void Demo()
    {
        Graph *g = Graph::create_graph(
            "C:/Users/kisor/Academics/SEM-3/DSA - 2/New folder/ADA_XXX/ADA_XXX/graph_desc.txt"

        );
        if (g != nullptr) {
            g->print();
            g->bfs(0); 
            g->dfs(0); 
            delete g;
        }
    }
}

#endif