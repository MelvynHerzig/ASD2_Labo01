/*
 * File:   GraphFromImage.h
 * Author: Olivier Cuisenaire
 *
 * Created on 2. octobre 2014, 12:09
 * Updated on 8. septembre 2020 by Antoine Rochat
 *
 * Modified by Berney Alec, Forestier Quentin, Herzig Melvyn on 25 sep 2020
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

   /**
    * @brief Retourne les sommets adjacents au sommet v
    * @param v Numero du sommet
    * @return Liste contenant tous les sommets adjacents au sommet souhaité
    * @throw std::out_of_range
    */
   Iterable adjacent (int v) const;

   /**
    * @brief Retourne le nombre de sommets du graphe
    * @return int contenant le nombre de sommets du graphe
    */
   int V () const;

   // Méthodes permettants de passer de x/y à idx et vice-versa
   // THROWS std::out_of_range

   /**
    * @brief Index du sommet représentant le pixel a la position x, y
    * @param x Position x du pixel
    * @param y Position y du pixel
    * @return Retourne l'index du sommet
    * @throw std::out_of_range
    */
   int idx (int x, int y) const;

   /**
    * @brief Coordonné x du sommet idx
    * @param idx Index du sommet
    * @return Cordonné x du sommet souhaité
    * @throw std::out_of_range
    */
   int x (int idx) const;

   /**
    * @brief Coordonné y du sommet idx
    * @param idx Index du sommet
    * @return Coordonné y du sommet souhaité
    * @throw std::out_of_range
    */
   int y (int idx) const;

// ELEMENTS PRIVES: LIBRE D'AJOUTER DES ELEMENTS
private:

   /**
    * @brief Compare la couleur de 2 pixels
    * @param x1 Coordonné x du premier pixel
    * @param y1 Coordonné y du premier pixel
    * @param x2 Coordonné x du deuxième pixel
    * @param y2 Coordonné y du deuxième pixel
    * @return True si les 2 pixels ont la même couleur
    */
   bool comparePixelColor(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) const;

   const bitmap_image &image;
};

#endif   /* GRAPHFROMIMAGE_H */
