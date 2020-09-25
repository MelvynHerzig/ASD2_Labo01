/* 
 * File:   main.cpp
 * Author: Olivier Cuisenaire
 * Modified: Raphaël Racine (2018), Antoine Rochat (2020)
 *
 * Inspiré par http://oracleofbacon.org 
 * 
 * Created on 26. septembre 2014, 16:38
 */

#include <cstdlib>

#include "SymbolGraph.h"
#include "GraphUsingAdjacencyLists.h"
#include "BFS.h"

using namespace std;

string lastParent(const vector<string>& parents);

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

   while(lastParent(parents) != sink)
   {
      parents.push_back( SG.symbol( bfs.parentOf( SG.index(lastParent(parents)))));
   }

   for(const string& parent : parents)
   {
      cout << parent << endl;
   }

   cout << endl;

   // Affiche les films dans lesquels Keanu Reeves a joué
   string actor = "Keanu Reeves";
   cout << "Tous les films avec " << actor << " : " << endl;

   vector<string> films = SG.adjacent(actor);

   for(const string& film : films)
   {
      cout << film << endl;
   }

   return EXIT_SUCCESS;
}

string lastParent(const vector<string>& parents)
{
   return parents[parents.size()-1];
}