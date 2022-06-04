#include "Game.h"

/* ##################################################################
   # TODO: delete textures at destructors (!!! fuites mémoires !!!) #
   ################################################################## */


#include "Vector.h"
#include <iostream>
#include <SDL2/SDL.h>

/***************************************************
 * main :                                          *
 * ------                                          *
 * C'est ici que commence l'exécution du programme *
 ***************************************************/


int main (int argc, char** argv) {

   Game game;
   game.main_loop ();

   return EXIT_SUCCESS;
}
