/* 
 * File:   GraphUsingAdjacencyMatrix.cpp
 * Author: Olivier Cuisenaire
 * Created on 19. septembre 2014, 04:51
 * Modified by Andrei Popescu-Belis on 17 sep 2019
 * Modified by Antoine Rochat on 8 sep 2020
 */
#include "GraphUsingAdjacencyMatrix.h"
#include <list>
#include <vector>

typedef std::list<int> Iterable;

GraphUsingAdjacencyMatrix::GraphUsingAdjacencyMatrix (std::istream &s)
{
   int V, E, v, w;
   s >> V;
   s >> E;
   Init(V);
   for (int i = 0; i < E; i++)
   {
      s >> v;
      s >> w;
      addEdge(v, w);
   }
}

GraphUsingAdjacencyMatrix::GraphUsingAdjacencyMatrix (int V)
{
   Init(V);
}

// ajoute une arete
void GraphUsingAdjacencyMatrix::addEdge (int v, int w)
{
   adjMatrix.at(v).at(w) = true;
   adjMatrix.at(w).at(v) = true;
}

// voisins du sommet v
Iterable GraphUsingAdjacencyMatrix::adjacent (int v) const
{

   Iterable adj;

   for (int w = 0; w < V(); ++w)
   {
      if (adjMatrix.at(v)[w])
      {
         adj.push_back(w);
      }
   }
   return adj;
}

// ordre du graphe
int GraphUsingAdjacencyMatrix::V () const
{
   return (int) adjMatrix.size();
}

void GraphUsingAdjacencyMatrix::Init (int V)
{

   adjMatrix.resize(V);
   for (int v = 0; v < V; v++)
   {
      adjMatrix[v].resize(V);
   }
}


