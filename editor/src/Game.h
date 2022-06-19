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

 #include <iostream> // TODO: remove

 #include "Context.h"
 #include "Input.h"
 #include "Top_menu.h"
 #include "Grid.h"
 #include "Loader.h"

class Game
{

  public:

   Game ();
   ~Game ();

   void main_loop ();
   bool manage_input ();
   void refresh ();

  private:

      // gestion de l'entrée utilisateur
   Input m_input;

      // gestion de la couche de base : fenêtres, renderer, etc.
   Context m_context;

      // menu du haut
   Top_menu m_top_menu;


      // apparences des blocs utilisés dans le monde
   Tileset m_tileset;

      // monde en édition
   Grid m_grid;
};

#endif
