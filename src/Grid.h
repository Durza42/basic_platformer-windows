/*
 * Grid.h
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


#ifndef GRID_H
 #define GRID_H

 #include <SDL2/SDL.h>
 #include <vector>
 #include "Tileset.h"

 #define BLOC_GRID_SIZE 25

/*****************************************
 * classe Grid :                         *
 * -------------                         *
 * classe gérant la grille de collision. *
 *****************************************/

class Grid {

  public:

   Grid ();
   ~Grid ();

   void load (std::vector<std::vector<char>> & grid, Tileset tileset); // TODO: réfléchir à un meilleur moyen de chargement. Référence, puis copier-coller ? Vraiment ? Ou passer direct le flux du fichier ?

   void print (SDL_Renderer* renderer, int x_offset, int y_offset);
   void automap (Tileset tileset); // <- TODO
   Tiletype compute_tile_look(size_t x, size_t y);

   bool has_col (SDL_Rect & r) const;
   bool is_wall (size_t x, size_t y) const;

   int get_x_offset () const;
   int get_y_offset () const;
   void set_offset (int x, int y);

  private:

      // une grille (2D) de caractères : 'X' pour un mur, '.' pour du vide, etc. Voir "../data/lvls_config/aide.lvl" pour la liste complète.
   std::vector<std::vector<char>> m_col_grid;

      // la grille qui apparaitra à l'écran
   std::vector<std::vector<SDL_Texture*>> m_look_grid; 
};

#endif
