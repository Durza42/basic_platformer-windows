/*
 * Grid.cpp
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

 
#include "Grid.h"

Grid::Grid () {

}

Grid::~Grid () {
   // [TODO]
}


/***************************
 * print :                 *
 * -------                 *
 * affiche toute la grille *
 ***************************/

void Grid::print (SDL_Renderer* renderer, int x_offset, int y_offset) {

   for (size_t i {0} ; i < m_col_grid.size() ; ++i) {
      for (size_t j {0} ; j < m_col_grid[0].size() ; ++j) {

            // créé uniquement car SDL_RenderCopy demande un pointeur
         SDL_Rect pos_this_square = { (int)i * BLOC_GRID_SIZE + x_offset,
                                      (int)j * BLOC_GRID_SIZE + y_offset,
                                      BLOC_GRID_SIZE, BLOC_GRID_SIZE };
         SDL_RenderCopy (renderer, m_look_grid[i][j], NULL, &pos_this_square);
      }
   }
}


/*********************************************************
 * automap :                                             *
 * ---------                                             *
 * donne la bonne image à chaque carré de façon          *
 * à ce que les murs s'emboitent bien les uns aux autres *
 *********************************************************/

void Grid::automap (Tileset tileset) {
   // [TODO]

      // ceci est temporaire...
   for (size_t i {0} ; i < m_look_grid[i].size() ; ++i)
      for (size_t j {0} ; j < m_look_grid.size() ; ++j)
         if (m_col_grid[j][i] == 'X')
            m_look_grid[j][i] = tileset.get_tile(compute_tile_look(j, i));
}


/*********************************************************
 * compute_tile_look :                                   *
 * -------------------                                   *
 * calcule quelle apparence doit avoir la tuile demandée *
 * en fonction de celles qui l'entourent                 *
 *********************************************************/

Tiletype Grid::compute_tile_look(size_t x, size_t y) {

      // la conversion en entier est nécessaire,
      // car size_t est non signé ; la comparaison avec 0 renverrait alors toujours false.
   if ((int)x - 1 < 0) {
      if ((int)y - 1 < 0)
         return CORNER_LEFT_UP;
      else if ((int)y + 1 >= m_col_grid[0].size())
         return CORNER_LEFT_DOWN;
      else
         return LEFT;
   }
   else if ((int)x + 1 >= m_col_grid.size()) {
      if ((int)y - 1 < 0)
         return CORNER_RIGHT_UP;
      else if ((int)y + 1 >= m_col_grid[0].size())
         return CORNER_RIGHT_DOWN;
      else
         return RIGHT;
   }

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] == 'X')
      return FULL;


   /* TODO: links */


   if (m_col_grid[x - 1][y] != 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] != 'X'
   and m_col_grid[x][y + 1] == 'X')
      return CORNER_LEFT_UP;

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] != 'X'
   and m_col_grid[x][y - 1] != 'X'
   and m_col_grid[x][y + 1] == 'X')
      return CORNER_RIGHT_UP;

   if (m_col_grid[x - 1][y] != 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] != 'X')
      return CORNER_LEFT_DOWN;

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] != 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] != 'X')
      return CORNER_RIGHT_DOWN;


   if (m_col_grid[x - 1][y] != 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] == 'X')
      return LEFT;

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] != 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] == 'X')
      return RIGHT;

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] != 'X'
   and m_col_grid[x][y + 1] == 'X')
      return UP;

   if (m_col_grid[x - 1][y] == 'X'
   and m_col_grid[x + 1][y] == 'X'
   and m_col_grid[x][y - 1] == 'X'
   and m_col_grid[x][y + 1] != 'X')
      return DOWN;

   return FULL;

}

/****************************************
 * load :                               *
 * ------                               *
 * charge la grille d'un nouveau niveau *
 ****************************************/

void Grid::load (std::vector<std::vector<char>> & grid, Tileset tileset) {
   m_col_grid = grid;

   std::vector<SDL_Texture*> tmp_text_v(grid[0].size(), NULL);
   for (size_t i {0} ; i < grid.size() ; ++i)
      m_look_grid.push_back(tmp_text_v);

   automap(tileset);
}


/***********************************************************
 * has_col :                                               *
 * ---------                                               *
 * indique si le rectangle donné rentre dans un mur ou non *
 ***********************************************************/

bool Grid::has_col (SDL_Rect & r) const {

   if (m_col_grid[r.x / BLOC_GRID_SIZE][r.y / BLOC_GRID_SIZE] == 'X')
      return true;

      // Pour chaque tuile dans le rectangle : si vaut 'X' (mur), renvoyer vrai. 
   for (int i { r.x / BLOC_GRID_SIZE } ; i <= (r.x + r.w) / BLOC_GRID_SIZE ; ++i)
      for (int j { r.y / BLOC_GRID_SIZE } ; j <= (r.y + r.h) / BLOC_GRID_SIZE ; ++j)
         if (m_col_grid[i][j] == 'X')
            return true;
   return false;
}


/**********************************************
 * is_wall :                                  *
 * ---------                                  *
 * indique si le bloc donné est un mur ou non *
 **********************************************/

bool Grid::is_wall (size_t x, size_t y) const {

   if (m_col_grid[x][y] == 'X')
      return true;
   else
      return false;
}
