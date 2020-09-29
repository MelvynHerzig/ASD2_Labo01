/* 
 * File:   main.cpp
 * Author: Olivier Cuisenaire
 * Modified: Raphaël Racine (2018), Antoine Rochat (2020)
 *
 * Inspiré par http://oracleofbacon.org 
 * 
 * Created on 26. septembre 2014, 16:38
 * Modified by Berney Alec, Forestier Quentin, Herzig Melvyn on 25 sep 2020
 */

#include <cstdlib>

#include "SymbolGraph.h"
#include "GraphUsingAdjacencyLists.h"
#include "BFS.h"

using namespace std;

/**
 * @brief Surcharge de l'opérateur de flux <<
 * @param os Flux de sortie
 * @param v Vecteur de string
 * @return Le flux de sortie concaténé avec le vecteur.
 */
ostream& operator<<(ostream& os, const vector<string>& v)
{
   for(const string& elem : v)
   {
      os << elem << endl;
   }
   return os;
}

int main (int argc, char **argv)
{

   string file("movies.txt");
   string source("Eric Beaver");
   string sink("Kevin Bacon");

   SymbolGraph<GraphUsingAdjacencyLists> SG(file, '|');

   BFS<GraphUsingAdjacencyLists> bfs(SG.G());
   bfs.visit(SG.index(sink), [] (int)
   {});

   // Affiche le chemin acteur->film->acteur->...->film->acteur
   cout << "Chemin entre " << source << " et " << sink << " :" << endl;

   vector<string> parents;
   parents.push_back(source);

   //Pour chaque nouveau parent nous insérons son parent.
   while(parents.back() != sink)
   {
      parents.push_back( SG.symbol( bfs.parentOf( SG.index( parents.back()))));
   }

  cout << parents;

   cout << endl;

   // Affiche les films dans lesquels Keanu Reeves a joué
   string actor = "Keanu Reeves";
   cout << "Tous les films avec " << actor << " : " << endl;

   vector<string> films = SG.adjacent(actor);

   cout << films;

   return EXIT_SUCCESS;
}