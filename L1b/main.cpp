/* 
 * File:   ex1.cpp
 * Author: Olivier Cuisenaire
 *
 * Created on 2 oct. 2014, 11:19:03
 */

#include <stdlib.h>
#include <iostream>

#include "GraphFromImage.h"
#include "DFS.h"

int main(int argc, char** argv) {

    std::string filename("input.bmp");
    bitmap_image image(filename);

    if (!image) {
        std::cout << "test1 : Failed to open " << filename << ") \n";
        return (EXIT_FAILURE);
    }

    std::cout << "image size: " << image.width() << " x " << image.height() << "\n";

    GraphFromImage G(image);

/****
*
*  Question BONUS :
*  Pourquoi utilisons-nous la classe DFSIter et non la classe DFS pour parcourir l'image ?
*
*  DFSIter permet de parcourir l'image sans utiliser de récursion, cela nous permet donc
*  d'éviter des récursion profondes avec des grandes images, ce qui risquerait de faire
*  crasher le programme.
*
****/

    DFSIter<GraphFromImage> dfs(G);

    //on colore le centre de la pomme
    dfs.visit(G.idx(250, 400), [](int v) {}, [&G, &image](int v) {
        image.set_pixel(G.x(v), G.y(v), 250, 150, 65);
    });

    // on colore la feuille en haut de la pomme
    dfs.visit(G.idx(225, 100), [](int v) {}, [&G, &image](int v) {
        image.set_pixel(G.x(v), G.y(v), 0, 225, 0);
    });

    // on ajoute une couleur de fond
    dfs.visit(G.idx(50, 50), [](int v) {}, [&G, &image](int v) {
        image.set_pixel(G.x(v), G.y(v), 150, 220, 255);
    });

    // on sauve l'image modifiee
    // A décommenter si vous voulez observer le résultat obtenu, attention : fait crasher le codecheck
    // image.save_image("output.bmp");

    //on charge l'image temoin pour verifier notre code
    bitmap_image image_gold("goal.bmp");

    if (image.psnr(image_gold) < 1000000)
        std::cout << "test failed - psnr = " << image.psnr(image_gold) << ") \n";
    else
        std::cout << "test succeeded - image is identical to goal.bmp\n";

    return (EXIT_SUCCESS);

}

