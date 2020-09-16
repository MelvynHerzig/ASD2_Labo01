/*
 * File:   SymbolGraph.h
 * Author: Olivier Cuisenaire
 * Modified: Raphaël Racine (2018), Antoine Rochat (2020)
 *
 * Created on 26. septembre 2014, 15:08
 */
#ifndef SYMBOLGRAPH_H
#define    SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

#include "Util.h"

template<typename GraphType>
class SymbolGraph {
    typedef GraphType Graph;
private:
    Graph* g;

/****
*
*  AJOUTEZ ICI VOS STRUCTURES PRIVEES
*  Justifiez le choix de vos structures de données en fonction de la complexité (mémoire et processeur)
*
****/

public:

    ~SymbolGraph() {
        delete g;
    }

    //creation du SymbolGraph a partir du fichier movies.txt
    SymbolGraph(const std::string& filename, char delim = '/') {
/****
*
*  A IMPLEMENTER
*  Indication: nous autorisons une double lecture du fichier.
*
****/
        // exemple de lecture du fichier, ligne par ligne puis element par element (separe par des |)
        std::string line;

        std::ifstream s(filename);
        int cnt = 0;

        while (std::getline(s, line)) {
            auto names = split(line, delim);
            for (const auto& name : names) {
                // Récupération de tous les noeuds du graphe
            }

        }
        s.close();

    }

    //verifie la presence d'un symbole
    bool contains(const std::string& name) const {
/****
*
*  A IMPLEMENTER
*
****/
    }

    //index du sommet correspondant au symbole
    int index(const std::string& name) const {
/****
*
*  A IMPLEMENTER
*
****/
    }

    //symbole correspondant au sommet
    std::string symbol(int idx) const {
/****
*
*  A IMPLEMENTER
*
****/
    }

    //symboles adjacents a un symbole
    std::vector<std::string> adjacent(const std::string& name) const {
/****
*
*  A IMPLEMENTER
*
****/
    }

    const Graph& G() const {
        return *g;
    }

};


#endif    /* SYMBOLGRAPH_H */
