/*
 * File:   SymbolGraph.h
 * Author: Olivier Cuisenaire
 * Modified: Raphaël Racine (2018), Antoine Rochat (2020)
 *
 * Created on 26. septembre 2014, 15:08
 *
 * Modified by Berney Alec, Forestier Quentin, Herzig Melvyn on 25 sep 2020
 */
#ifndef SYMBOLGRAPH_H
#define SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

#include "Util.h"

template<typename GraphType>
class SymbolGraph
{
   typedef GraphType Graph;

private:

   Graph* g;

   /**
    * @brief stocke les noms associés au no de sommet dans g.
    * @details
    *           Soit:
    *           N = nombre d'auteurs et de films
    *           M = 3 * sizeof(void*) + sizeof(key) + sizeof(value)
    *
    *           Accès en O(log(N))
    *           Empreinte en O(N * M)
    *
    *           Il est claire que la structure de stockage n'est pas la plus optimisée
    *           d'un point de vue vitesse place, mais elle est un bon compromis.
    *           Elle offre un mécanisme anti doublon en O(Nlog(N)) bien meilleur
    *           que dans un vecteur en O(N^2). Les opérations les plus fréquentes
    *           consistant à passer de nom -> id sont également en O(log(n)) ce qui est
    *           mieux que du O(N) dans un vecteur, par exemple. Toutefois l'accès
    *           id -> nom se fait en O(N), cette opération est pas primordiale,
    *           nous avons donc privilegié la précédente.
    *
    *           En résumé nous avons préféré cette structure pour son temps de calcul
    *           en recherche de doublons et en conversion nom -> id, opérations les
    *           plus fréquentes.
    */
   std::map< std::string, int> m;

public:

   ~SymbolGraph ()
   {
      delete g;
   }

   /**
    * @brief Création du SymbolGraph a partir du fichier filename.
    * @param filename Fichier à utiliser pour créer le graphe à symbole.
    * @param delim Délimiteur des sommets dans le fichier.
    * @details On considère que les films sont le premier élément de ligne.
    */
   SymbolGraph (const std::string &filename, char delim = '/')
   {
      std::string line;
      std::ifstream s(filename);

      int cnt = 0;

      std::vector<std::vector<int>> edges;
      std::vector<int> edge;

      while (std::getline(s, line))
      {
         auto names = split(line, delim);

         edges.push_back(edge);

         for (const auto &name : names)
         {
            if ( ! contains(name))
            {
               m[name] = cnt++;;
            }

            edges.back().push_back(index(name));
         }
      }

      s.close();
      g = new Graph(cnt);

      for(size_t i = 0; i < edges.size(); ++i)
      {
         for(size_t j = 1; j < edges[i].size(); ++j)
         {
            g->addEdge(edges[i][0], edges[i][j]);
         }
      }

   }

   /**
    * @brief verifie la presence d'un symbole.
    * @param name Symbole à rechercher.
    * @return Vrai si existant sinon faux.
    */
   bool contains (const std::string &name) const
   {
      return m.find(name) != m.end();
   }

   /**
    * @brief Cherche l'index du sommet correspondant au symbole.
    * @param name Symbole à traduire en index.
    * @return Le numéro du sommet lié dans le graphe sinon -1.
    */
   int index (const std::string &name) const
   {
      if(!contains(name)) return -1;

      return m.at(name);
   }

   /**
    * @brief Retourne le nom d'un numero de sommet.
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

   /**
    * @brief Retourne les symboles adjacents à un symbole.
    * @param name Symbole à chercher les adjacences.
    * @return Vecteur des syboles adjacents, vide si le nom existe pas.
    */
   std::vector<std::string> adjacent (const std::string &name) const
   {
      std::vector<std::string> adjName;
      int v = index(name);

      if(v < 0) return adjName;

      std::list<int> adjNum = g->adjacent(v);

      for(auto it = adjNum.begin(); it != adjNum.end();  ++it)
      {
         adjName.push_back( symbol(*it) );
      }

      return adjName;
   }

   const Graph &G () const
   {
      return *g;
   }

};

#endif    /* SYMBOLGRAPH_H */
