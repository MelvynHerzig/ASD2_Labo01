/* 
 * File:   GraphUsingAdjacencyMatrix.cpp
 * Author: Olivier Cuisenaire
 * Created on 19. septembre 2014, 04:51
 * Modified by Andrei Popescu-Belis on 17 sep 2019
 * Modified by Antoine Rochat on 8 sep 2020
 *          by Alec Berney, Quentin Forestier et Melvyn Herzig on 15 sep 2020
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

/**
 * @brief créé et ajoute une arête entre 2 sommets
 * @param v un entier correspondant au 1er sommet
 * @param w un entier correspondant au 2ème sommet
 *
 * La fonction n'ajoute pas l'arête si les sommets passés en paramètres ne sont pas
 * correctes (ne font pas partie du graphe)
 */
void GraphUsingAdjacencyMatrix::addEdge (int v, int w)
{
   if(v < 0 or w < 0 or v > this->V() or w > this->V())
       return;
   adjMatrix.at(v).at(w) = true;
   adjMatrix.at(w).at(v) = true;
}

/**
 * @brief créé et retourne la liste d'adjacence du sommet donné en paramètre
 * @param v un entier correspondant à un sommet du graphe
 * @return une liste d'entier étant la liste d'adjacence du sommet donné
 *
 * La fonction retourne une liste d'adjacence vide si le sommet passé en paramètres
 * n'est pas correcte (ne fait pas partie du graphe)
 */
Iterable GraphUsingAdjacencyMatrix::adjacent (int v) const
{
   Iterable adj;
   if(v < 0 or v > this->V())
       return adj;

   for (int w = 0; w < V(); ++w)
   {
      if (adjMatrix.at(v)[w])
      {
         adj.push_back(w);
      }
   }
   return adj;
}

/**
 * @brief donne l'ordre du graphe
 * @return un entier inqiquant l'ordre du graphe
 */
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


