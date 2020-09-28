/* 
 * File:   main.cpp
 * Author: Olivier Cuisenaire
 * Created on 4 sept. 2014, 13:18:18
 * Modified by Andrei Popescu-Belis on 17 sep 2019
 *          by Alec Berney, Quentin Forestier et Melvyn Herzig on 15 sep 2020
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "CC.h"
#include "DFS.h"
#include "BFS.h"
#include "GraphUsingAdjacencyMatrix.h"

using namespace std;

/**
 * @brief compte et retourne le nombre d'arêtes contenues dans le graph donné
 * @tparam Graph
 * @param G un Graph à analyser
 * @return un entier correspondant au nombre d'arêtes du graphe
 */
template<typename Graph>
int CountEdges (const Graph &G)
{
   int nbEdges = 0;

   for(unsigned i = 0; i < G.V(); ++i)
   {
      nbEdges += G.adjacent(i).size();
   }

   return nbEdges/2;
}

// Retourne la distance maximale entre le sommet v et 
// le sommet le plus eloigne dans sa composante connexe
template<typename Graph>
int FindMaxDistanceFrom (const Graph &G, int v)
{
   vector<int> distances(G.V());
   distances[v] = 0;
   int maxDistance = 0;
   BFS<Graph> bfs(G);
   bfs.visit(v, [&] (int w)
   { // [&] assure que l'expression-lambda (la fonctionnelle)
      // a acces a toutes les variables externes (v, maxDistance, distances) par reference.
      // Il n'est pas necessaire de preciser "-> void" avant '{' car ca peut etre deduit.
      if (v == w)
      { return; }
      maxDistance = distances[w] = distances[bfs.parentOf(w)] + 1;
   });
   return maxDistance;
}

// affiche les proprietes du graphe
template<typename Graph>
void Analyse (const Graph &G)
{
   CC<Graph> cc(G);
   cout << "Sommets : " << G.V() << endl;
   cout << "Aretes : " << CountEdges(G) << endl;
   cout << "Composantes connexes : " << cc.Count() << endl;
   cout << "Le premier sommet fait partie de la CC numero : " << cc.Id(0) << endl;
   cout << "La distance maximale a ce sommet dans sa CC est : " << FindMaxDistanceFrom(G, 0) << endl;
   cout << "Le dernier sommet fait partie de la CC numero : " << cc.Id(G.V() - 1) << endl;
   cout << "La distance maximale a ce sommet dans sa CC est : " << FindMaxDistanceFrom(G, G.V() - 1) << endl;
   cout << endl;
}

int main ()
{

   string filenameTiny("tinyG.txt");
   ifstream fileTiny(filenameTiny);
   if (fileTiny.rdstate())
   {
      cerr << "Erreur de lecture tinyG";
      return (EXIT_FAILURE);
   } // tester ouverture

   GraphUsingAdjacencyMatrix Gt(fileTiny);
   fileTiny.close();
   cout << "Analyse de tinyG.txt" << endl;
   Analyse(Gt);

   string filenameMedium("mediumG.txt");
   ifstream fileMedium(filenameMedium);
   if (fileTiny.rdstate())
   {
      cerr << "Erreur de lecture mediumG";
      return (EXIT_FAILURE);
   } // tester ouverture

   GraphUsingAdjacencyMatrix Gm(fileMedium);
   fileMedium.close();
   cout << "Analyse de mediumG.txt" << endl;
   Analyse(Gm);

   return (EXIT_SUCCESS);
}
