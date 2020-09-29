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
 * @brief Crée et ajoute une arête entre 2 sommets.
 * @param v Entier correspondant au 1er sommet.
 * @param w Entier correspondant au 2ème sommet.
 * @details La fonction n'ajoute pas l'arrête si les sommets passés en paramètre ne
 *         font pas partie du graphe.
 */
void GraphUsingAdjacencyMatrix::addEdge (int v, int w)
{
   if(v < 0 || w < 0 || v >= V() || w >= V()) return;

   adjMatrix.at(v).at(w) = true;
   adjMatrix.at(w).at(v) = true;
}

/**
 * @brief Crée et retourne la liste d'adjacence du sommet donné en paramètre.
 * @param v Entier correspondant à un sommet du graphe.
 * @return Retourne la liste d'adjacence du sommet donné.
 * @details La fonction retourne une liste d'adjacence vide si le sommet passé en
 *          paramètre ne fait pas partie du graphe.
 */
Iterable GraphUsingAdjacencyMatrix::adjacent (int v) const
{
   Iterable adj;

   if(v < 0 || v >= V()) return adj;

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
 * @brief Donne l'ordre du graphe.
 * @return Retourne un entier inqiquant l'ordre du graphe.
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


