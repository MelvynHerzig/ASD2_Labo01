/*
 * File:   GraphFromImage.h
 * Author: Olivier Cuisenaire
 *
 * Created on 2. octobre 2014, 12:09
 * Updated on 8. septembre 2020 by Antoine Rochat
 */
#include "GraphFromImage.h"

GraphFromImage::GraphFromImage (const bitmap_image &i) : image(i)
{

}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent (int v) const
{
   Iterable adj;

   unsigned vPx, vPy;

   vPx = x(v);
   vPy = y(v);

   if(vPx > 0 && )


}

// throws std::out_of_range
int GraphFromImage::idx (int x, int y) const
{
   if(x < 0 || x >= image.width() || y < 0 || y >= image.height())
   {
      throw std::out_of_range("Coordonnees invalides");
   }
   return y * image.width() + x;
}

// throws std::out_of_range
int GraphFromImage::x (int idx) const
{
   if(idx >= V() || idx < 0) throw std::out_of_range("Index invalide");

   return idx % image.width();
}

// throws std::out_of_range
int GraphFromImage::y (int idx) const
{
   if(idx >= V() || idx < 0) throw std::out_of_range("Index invalide");

   return idx / image.width();
}

int GraphFromImage::V () const
{
   return image.width() * image.height();
}