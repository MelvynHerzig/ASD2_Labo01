/*
 * File:   GraphUsingAdjacencyMatrix.h
 * Original file:   GraphUsingAdjacencyMatrix.cpp
 * Author: Olivier Cuisenaire
 * Created on 19. septembre 2014, 04:51
 * Modified by Andrei Popescu-Belis on 17 sep 2019
 */
#ifndef GRAPHUSINGADJACENCYMATRIX_H
#define GRAPHUSINGADJACENCYMATRIX_H

#include <list>
#include <vector>
#include <istream>

class GraphUsingAdjacencyMatrix
{
public:
   typedef std::list<int> Iterable;

   GraphUsingAdjacencyMatrix (std::istream &s);

   GraphUsingAdjacencyMatrix (int V);

   // ajoute une arete
   void addEdge (int v, int w);

   // voisins du sommet v
   Iterable adjacent (int v) const;

   // ordre du graphe
   int V () const;

private:
   // constructeurs non autorises
   GraphUsingAdjacencyMatrix (const GraphUsingAdjacencyMatrix &G);

   GraphUsingAdjacencyMatrix ();

   void Init (int V);

   std::vector<std::vector<bool>> adjMatrix;
};


#endif /* GRAPHUSINGADJACENCYMATRIX_H */

