/*
 * File:   SymbolGraph.h
 * Author: Olivier Cuisenaire
 * Modified: Raphaël Racine (2018), Antoine Rochat (2020)
 *
 * Created on 26. septembre 2014, 15:08
 */
#ifndef SYMBOLGRAPH_H
#define SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

#include "Util.h"

template<typename GraphType>
class SymbolGraph
{
   typedef GraphType Graph;

private:

   Graph* g;

   std::map< std::string, int> m;

/****
*
*  AJOUTEZ ICI VOS STRUCTURES PRIVEES
*  Justifiez le choix de vos structures de données en fonction de la complexité (mémoire et processeur)
*
****/
public:

   ~SymbolGraph ()
   {
      delete g;
   }

   //creation du SymbolGraph a partir du fichier movies.txt
   SymbolGraph (const std::string &filename, char delim = '/')
   {
      std::string line;
      std::ifstream s(filename);
      int cnt = 0;
      int currentFilm = 0;
      bool isFilm;

      std::map<int, std::vector<int>> edges;

      while (std::getline(s, line))
      {
         bool isFilm = true;
         auto names = split(line, delim);

         for (const auto &name : names)
         {
            if(isFilm)
            {
               currentFilm = cnt++;
               m[name] = currentFilm;
               isFilm = false;
               continue;
            }

            if ( ! contains(name))
            {
               m[name] = cnt++;
            }

            edges[currentFilm].push_back(index(name));
         }
      }
      s.close();

      g = G(cnt);

      for(auto it = edges.begin(); it != edges.end(); ++it)
      {
         for(size_t i = 0; i < it->second.size(); ++i)
         {
            g->addEdge(it->first, it->second[i]);
         }
      }

   }

   //verifie la presence d'un symbole
   bool contains (const std::string &name) const
   {
      return m.find(name) != m.end();
   }

   //index du sommet correspondant au symbole
   int index (const std::string &name) const
   {
      return m.at(name);
   }

   /**
    * Retourne le nom d'un numero de sommet.
    * @param idx Numéro de sommet
    * @return le nom du sommet si l'id est trouvé sinon chaine vide.
    * @details Idx doit être entre >= 0 et < m.size() (nombre de sommet du graphe).
    */
   std::string symbol (int idx) const
   {
      const std::string NOT_FOUND = "";

      if(idx >= m.size() || idx < 0) return NOT_FOUND;

      for(auto it = m.begin(); it != m.end(); ++it)
      {
         if(it->second == idx)
         {
            return it->first;
         }
      }

      return NOT_FOUND;
   }

   //symboles adjacents a un symbole
   std::vector<std::string> adjacent (const std::string &name) const
   {
      
   }

   const Graph &G () const
   {
      return *g;
   }

};

#endif    /* SYMBOLGRAPH_H */
