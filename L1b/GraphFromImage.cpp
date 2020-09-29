/*
 * File:   GraphFromImage.h
 * Author: Olivier Cuisenaire
 *
 * Created on 2. octobre 2014, 12:09
 * Updated on 8. septembre 2020 by Antoine Rochat
 * Modified on 25. septembre 2020 by Berney Alec, Forestier Quentin, Herzig Melvyn
 */
#include "GraphFromImage.h"

GraphFromImage::GraphFromImage (const bitmap_image &i) : image(i)
{}


GraphFromImage::Iterable GraphFromImage::adjacent (int v) const
{
   Iterable adj;

   unsigned vPx, vPy;

   vPx = x(v);
   vPy = y(v);

   // Pixel gauche
   if(vPx > 0 && comparePixelColor(vPx, vPy, vPx-1, vPy))
   {
      adj.push_back(idx(vPx - 1, vPy));
   }

   // Pixel haut
   if(vPy > 0 && comparePixelColor(vPx, vPy, vPx, vPy - 1))
   {
      adj.push_back(idx(vPx, vPy - 1));
   }

   // Pixel droite
   if(vPx < image.width() - 1 && comparePixelColor(vPx, vPy, vPx + 1, vPy))
   {
      adj.push_back(idx(vPx + 1, vPy));
   }

   // Pixel bas
   if(vPy < image.height() - 1 && comparePixelColor(vPx, vPy, vPx, vPy + 1))
   {
      adj.push_back(idx(vPx, vPy + 1));
   }

   return adj;
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

bool GraphFromImage::comparePixelColor(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) const
{
   unsigned char r1, g1, b1;
   unsigned char r2, g2, b2;

   image.get_pixel(x1, y1, r1, g1, b1);
   image.get_pixel(x2, y2, r2, g2, b2);

   return r1 == r2 && g1 == g2  && b1 == b2;
}