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

int main(int argc, char **argv) {

    string file("movies.txt");
    string source("Eric Beaver");
    string sink("Kevin Bacon");

    SymbolGraph<GraphUsingAdjacencyLists> SG(file, '|');

    BFS<GraphUsingAdjacencyLists> bfs(SG.G());
    bfs.visit(SG.index(sink), [](int) {});

    // Affiche le chemin acteur->film->acteur->...->film->acteur
    cout << "Chemin entre " << source << " et " << sink << " :" << endl;

/****
*
*  A IMPLEMENTER
*
****/

    cout << endl;

    // Affiche les films dans lesquels Keanu Reeves a joué
    string actor = "Keanu Reeves";
    cout << "Tous les films avec " << actor << " : " << endl;

/****
*
*  A IMPLEMENTER
*
****/

    return EXIT_SUCCESS;
}

