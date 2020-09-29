/*
 * File:   GraphUsingAdjacencyLists.cpp
 * Author: Olivier Cuisenaire
 * Created on 19. septembre 2014, 04:51
 * Modified by Antoine Rochat on 8 sep 2020
 * Modified by Berney Alec, Forestier Quentin, Herzig Melvyn on 25 sep 2020
 */
#include "GraphUsingAdjacencyLists.h"

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists (int V)
{
   adjacencyLists.resize(V);
}

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists (std::istream &s)
{
   int V, E, v, w;

   s >> V;
   s >> E;

   adjacencyLists.resize(V);

   for (int i = 0; i < E; i++)
   {
      s >> v;
      s >> w;
      addEdge(v, w);
   }
}

/**
 * @brief Pour deux sommets, ajoute un lien dans la liste d'adjacence.
 * @param v sommet v.
 * @param w sommet w.
 */
void GraphUsingAdjacencyLists::addEdge (int v, int w)
{
   if(v < 0 || w < 0 || v >= V() || w >= V()) return;

   adjacencyLists.at(v).push_back(w);

   if(v != w)
   {
      adjacencyLists.at(w).push_back(v);
   }
}

/**
 * @brief Pour un sommet, retourne la liste d'adjacence.
 * @param v Sommet à retourner la liste d'adjacence.
 * @return Liste de int des sommets adjacents.
 * @throws out_of_range si v n'est pas un sommet du graphe.
 */
GraphUsingAdjacencyLists::Iterable GraphUsingAdjacencyLists::adjacent (int v) const
{
   return adjacencyLists.at(v);
}

/**
 * @brief Indique l'ordre du graphe.
 * @return Retourne le nombre de sommets.
 */
int GraphUsingAdjacencyLists::V () const
{
   return (int) adjacencyLists.size();
}
