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
            m_look_grid[j][i] = tileset.get_tile(FULL);

/* Fonction à terme : 
 *
 *   5
 *   5
 *   ▪️▪️▪️▪️▪️
 *   ▪️⬜️⬜️⬜️▪️
 *   ▪️⬜️⬜️⬜️▪️
 *   ▪️⬜️⬜️⬜️▪️
 *   ▪️▪️▪️▪️▪️
 *
 *       ||
 *       \/
 *
 * -- algorithme --
 *
 *   Pour chaque bloc :
 *      * Si tous les blocs sont pleins autour :
 *         * bloc = ⬜️
 *      * Sinon Si les blocs au dessus et à gauche sont vides :
 *         * bloc = ↖️
 *      ...
 *      * Sinon Si le bloc juste au dessus est vide :
 *         * bloc = ⬆️
 *      * Sinon, Si le bloc juste à gauche est vide :
 *         * bloc = ⬅️
 *      ...
 *
 *       ||
 *       \/
 *
 * -- sortie voulue --
 *
 *   ▪️▪️▪️▪️▪️
 *   ▪️↖️⬆️↗️▪️
 *   ▪️⬅️⬜️➡️▪️
 *   ▪️↙️⬇️↘️▪️
 *   ▪️▪️▪️▪️▪️
 *
 */
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
