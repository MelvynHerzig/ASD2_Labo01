/*
 * File:   GraphUsingAdjacencyLists.cpp
 * Author: Olivier Cuisenaire
 * Created on 19. septembre 2014, 04:51
 * Modified by Antoine Rochat on 8 sep 2020
 */
#include "GraphUsingAdjacencyLists.h"

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists(int V) {
    adjacencyLists.resize(V);
}

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists(std::istream& s) {
    int V, E, v, w;

    s >> V;
    s >> E;

    adjacencyLists.resize(V);

    for (int i = 0; i < E; i++) {
        s >> v;
        s >> w;
        addEdge(v, w);
    }
}

void GraphUsingAdjacencyLists::addEdge(int v, int w) {
/****
*
*  A IMPLEMENTER
*
****/
}

GraphUsingAdjacencyLists::Iterable GraphUsingAdjacencyLists::adjacent(int v) const {
/****
*
*  A IMPLEMENTER
*
****/
}

int GraphUsingAdjacencyLists::V() const {
/****
*
*  A IMPLEMENTER
*
****/
}
