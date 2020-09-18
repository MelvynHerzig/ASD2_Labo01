/*
 * File:   GraphFromImage.h
 * Author: Olivier Cuisenaire
 *
 * Created on 2. octobre 2014, 12:09
 * Updated on 8. septembre 2020 by Antoine Rochat
 */
#ifndef GRAPHFROMIMAGE_H
#define   GRAPHFROMIMAGE_H

#include <list>
#include <vector>
#include <utility>

#include "bitmap_image.hpp"

class GraphFromImage
{
// INTERFACE PUBLIQUE A NE PAS MODIFIER
public:

   // constructeur
   GraphFromImage (const bitmap_image &i);

   typedef std::list<int> Iterable;

   // Retourne les sommets adjacents au sommet v, THROWS std::out_of_range
   Iterable adjacent (int v) const;

   // Retourne le nombre de sommets
   int V () const;

   // Méthodes permettants de passer de x/y à idx et vice-versa
   // THROWS std::out_of_range

   // Index du sommet représentant le pixel a la position x, y
   int idx (int x, int y) const;

   // Coordonnée x du sommet idx
   int x (int idx) const;

   // Coordonnée y du sommet idx
   int y (int idx) const;

// ELEMENTS PRIVES: LIBRE D'AJOUTER DES ELEMENTS
private:

   bool comparePixelColor( int x1, int y1, int x2, int y2) const;

   const bitmap_image &image;
};

#endif   /* GRAPHFROMIMAGE_H */
