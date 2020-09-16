#ifndef GRAPH_USING_ADJACENCYLISTS_H
#define    GRAPH_USING_ADJACENCYLISTS_H

#include <iostream>
#include <list>
#include <vector>

class GraphUsingAdjacencyLists {
public:
    typedef const std::list<int>& Iterable;

    GraphUsingAdjacencyLists(std::istream& stream); // constructeur vu au cours d'ASD1. NE PAS UTILISER !!!
    GraphUsingAdjacencyLists(int V);

    void addEdge(int v, int w);              // ajoute une arête
    Iterable adjacent(int v) const;          // voisins du sommet v
    int V() const;                           // ordre du graphe

private:
    GraphUsingAdjacencyLists(const GraphUsingAdjacencyLists& G) {}; // constructeurs non autorises
    GraphUsingAdjacencyLists();

    std::vector<std::list<int>> adjacencyLists;
};

#endif    /* GRAPH_H */

