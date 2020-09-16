/* File: DFS.h
 * Original file: ComposantesConnexes.cpp
 * Author: Olivier Cuisenaire
 * Created on 18. septembre 2014, 10:46
 * Modified by Antoine Rochat on 7 sep 2020
 */
#ifndef CC_H
#define CC_H

#include <vector>
#include "DFS.h"

template<typename GraphType>
class CC
{
private:
   // numéro de la CC à laquelle appartient chaque sommet (-1 si pas encore assigné)
   std::vector<int> id;

   // nombre de composantes connexes
   int count;

public:
   // v et w sont-ils connectés ?
   bool Connected (int v, int w)
   {
      return Id(v) == Id(w);
   }

   // à quelle CC appartient v ?
   int Id (int v)
   {
      return id.at(v);
   }

   // combien y a-t-il de CC ?
   int Count ()
   {
      return count;
   }

   // constructeur
   CC (const GraphType &g)
   {
      id.assign(g.V(), -1);
      count = 0;
      for (int v = 0; v < g.V(); ++v)
      {
         if (id[v] == -1)
         {
            DFSIter<GraphType> P(g);
            P.visit(v, [&] (int w)
            {
               id[w] = count;
            }, [] (int w)
                    {});
            ++count;
         }
      }
   }// constructeur.
};

#endif /* CC_H */

