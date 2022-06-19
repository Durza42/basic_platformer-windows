/*
 * Lvl.h
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


#ifndef LVL_H
 #define LVL_H

 #include <SDL2/SDL.h>
 #include <vector>
 #include <fstream>
 #include <string>
 #include <algorithm>
 #include "utilities.h"
 #include "types.h"
 #include "Background.h"
 #include "Foreground.h"
 #include "Grid.h"
 #include "Tileset.h"
 #include "Perso.h"


/****************
 * classe Lvl : *
 * ------------ *
 * Un niveau.   *
 ****************/

class Lvl {

  public:

   Lvl (SDL_Renderer* renderer, const size_t & lvl_id);
   ~Lvl ();

   bool load_lvl (const size_t & lvl_id, SDL_Renderer* renderer);

   Background get_background () const;
   Foreground get_foreground () const;
   Grid get_grid () const;

   std::ifstream compile_lvl_file (const size_t & lvl_id);

   void load_foreground (std::ifstream& file, SDL_Renderer* renderer);
   void load_grid (std::ifstream& file);
   void load_tileset (std::ifstream& file, SDL_Renderer* renderer);
   void load_background (std::ifstream& file, SDL_Renderer* renderer);

   void print_grid (SDL_Renderer* renderer, int x_offet, int y_offset);

   SDL_Point get_spawn () const;

  private:

      // type de lvl
   Lvl_type m_type;

      // arrière-plan
   Background m_background;

      // grille de collision et apparence du niveau
   Grid m_grid;

      // avant-plan
   Foreground m_foreground;

      // jeu d'apparences des murs
   Tileset m_tileset;

      // point d'apparition du joueur
   SDL_Point m_spawn;
};

#endif
