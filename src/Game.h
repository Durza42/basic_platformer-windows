/*
 * Game.h
 * This file is part of 'basic platformer template'
 *
 * Copyright (C) 2022 - Durza42
 *
 * 'basic platformer template' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'basic platformer template' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'basic platformer template'. If not, see <http://www.gnu.org/licenses/>.
 */


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

   /* TODO: tableau pour être flexible quant à l'ajout de niveaux */
      // le niveau 'forêt'
   Lvl m_forest;

      // le personage que le joueur contrôle
   Perso m_perso;

};

#endif
