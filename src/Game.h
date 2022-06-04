#ifndef GAME_H
 #define GAME_H

 #include <SDL2/SDL.h>
 #include "Context.h"
 #include "Perso.h"
 #include "Lvl.h"
 #include "Input.h"

/****************************************************
 * classe Game :                                    *
 * -------------                                    *
 * cette classe s'occupe du comportement général    *
 * du jeu : il affiche les éléments à l'écran,      *
 * fait bouger le personnage en fontion des touches *
 * appuiées par le joueur.                          *
 ****************************************************/

class Game {

  public:

   Game ();
   ~Game ();

   void main_loop ();
   void do_events ();
   void refresh ();
   void reception_menu ();

  private:

      // voir le fichier Context.h
   Context m_context;

      // voir le fichier Input.h
   Input m_input;

      // le personage que le joueur contrôle
   Perso m_perso;

   /* TODO: tableau pour être flexible quant à l'ajout de niveaux */
      // le niveau 'forêt'
   Lvl m_forest;
};

#endif
