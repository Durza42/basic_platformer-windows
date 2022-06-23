#include "Grid.h"

Grid::Grid () :
      m_part_of_screen { 100, 50, DEFAULT_WINDOW_WIDTH - 100, DEFAULT_WINDOW_HEIGHT - 50 },
      m_x_offset { 100 },
      m_y_offset { 50 },
      m_mouse_before_moove { -1, -1},
      m_last_size_change { 0 }
{

}

Grid::~Grid () {
   // [TODO]
}


/***************************
 * print :                 *
 * -------                 *
 * affiche toute la grille *
 ***************************/

void Grid::print (SDL_Renderer* renderer) {

   SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
   SDL_RenderFillRect(renderer, &m_part_of_screen);

   for (size_t i {0} ; i < m_col_grid.size() ; ++i) {
      for (size_t j {0} ; j < m_col_grid[0].size() ; ++j) {

            // créé uniquement car SDL_RenderCopy demande un pointeur
         SDL_Rect pos_this_square = { (int)i * (BLOC_GRID_SIZE + 1) + m_x_offset,
                                      (int)j * (BLOC_GRID_SIZE + 1) + m_y_offset,
                                      BLOC_GRID_SIZE, BLOC_GRID_SIZE };

         SDL_RenderCopy (renderer, m_look_grid[i][j], NULL, &pos_this_square);
      }
   }

//   m_tilemenu.print(renderer);

   SDL_SetRenderDrawColor(renderer, CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B, 255);
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
         (m_col_grid[j][i] == 'X')
            ? m_look_grid[j][i] = tileset.get_tile(FULL)
            : m_look_grid[j][i] = tileset.get_tile(AIR);


/* Fonction à terme : (TODO)
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

   m_x_offset = 100;
   m_y_offset = 50;

//   m_tilemenu.load(renderer);
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

bool Grid::is_wall (size_t x, size_t y) const 
{
   return m_col_grid[x][y] == 'X';
}


/****************************************************************
 * is_clicked :                                                 *
 * ------------                                                 *
 * retourne vrai si la souris clique la zone consacrée à la map *
 * et fait les actions nécessaires                              *
 ****************************************************************/

bool Grid::is_clicked (SDL_Point mouse, Tileset tileset)
{
   if (SDL_PointInRect(&mouse, &m_part_of_screen))
   {
      int pos_x = floor((mouse.x - m_x_offset) / ((double)BLOC_GRID_SIZE + 1));
      int pos_y = floor((mouse.y - m_y_offset) / ((double)BLOC_GRID_SIZE + 1));

      if (pos_x >= m_col_grid.size())
         pos_x = m_col_grid.size() - 1;
      if (pos_y >= m_col_grid[0].size())
         pos_y = m_col_grid[0].size() - 1;

      if (pos_x < 0)
         pos_x = 0;
      if (pos_y < 0)
         pos_y = 0;

      m_col_grid [pos_x][pos_y] = 'X';
      m_look_grid[pos_x][pos_y] = tileset.get_tile(FULL);

      return true;
   }
   return false;
}


/****************************************************************
 * is_clicked_right :                                           *
 * ------------                                                 *
 * retourne vrai si la souris clique la zone consacrée à la map *
 * et fait les actions nécessaires                              *
 ****************************************************************/

bool Grid::is_clicked_right (SDL_Point mouse, Tileset tileset)
{
   if (SDL_PointInRect(&mouse, &m_part_of_screen))
   {
      int pos_x = floor((mouse.x - m_x_offset) / ((double)BLOC_GRID_SIZE + 1));
      int pos_y = floor((mouse.y - m_y_offset) / ((double)BLOC_GRID_SIZE + 1));

      if (pos_x >= m_col_grid.size())
         pos_x = m_col_grid.size() - 1;
      if (pos_y >= m_col_grid[0].size())
         pos_y = m_col_grid[0].size() - 1;

      if (pos_x < 0)
         pos_x = 0;
      if (pos_y < 0)
         pos_y = 0;

      m_col_grid [pos_x][pos_y] = '.';
      m_look_grid[pos_x][pos_y] = tileset.get_tile(AIR);

      return true;
   }
   return false;
}


/****************************************************************
 * is_clicked_middle :                                                 *
 * ------------                                                 *
 * retourne vrai si la souris clique la zone consacrée à la map *
 * et fait les actions nécessaires                              *
 ****************************************************************/

bool Grid::is_clicked_middle (SDL_Point mouse)
{
   if (SDL_PointInRect(&mouse, &m_part_of_screen))
   {
      if (m_mouse_before_moove.x < 0 or m_mouse_before_moove.y < 0)
      {
         m_mouse_before_moove.x = mouse.x + m_x_offset;
         m_mouse_before_moove.y = mouse.y + m_y_offset;
      }

      m_x_offset = m_mouse_before_moove.x - mouse.x;
      m_y_offset = m_mouse_before_moove.y - mouse.y;

      return true;
   }
   return false;
}


/*****************************************************************
 * is_not_clicked_middle :                                       *
 * ------------                                                  *
 * remet la position de la souris avant le déplacement de la map *
 * à une valeur indiquant que celle-ci ne se déplace pas         *
 *****************************************************************/

void Grid::is_not_clicked_middle ()
{
   m_mouse_before_moove.x = -1;
   m_mouse_before_moove.y = -1;
}


/***********************************
 * get_grid :                      *
 * ----------                      *
 * renvoie la grille des colisions *
 ***********************************/

std::vector<std::vector<char>> Grid::get_grid() const
{
   return m_col_grid;
}

int Grid::get_x_offset () const
{
   return m_x_offset;
}

int Grid::get_y_offset () const
{
   return m_y_offset;
}

void Grid::set_offset (int x, int y)
{
   m_x_offset = x;
   m_y_offset = y;
}

void Grid::add_w (Tileset tileset)
{
   if (SDL_GetTicks() - m_last_size_change < 250)
      return;

   m_last_size_change = SDL_GetTicks();

   m_col_grid.push_back( { '.' } );
   m_look_grid.push_back( { tileset.get_tile(AIR) } );
}

void Grid::remove_w ()
{
   if (SDL_GetTicks() - m_last_size_change < 250)
      return;

   m_last_size_change = SDL_GetTicks();

   if (m_col_grid.size() <= 0)
      return;

   m_col_grid.pop_back();
   m_look_grid.pop_back();
}

void Grid::add_h (Tileset tileset)
{
   if (SDL_GetTicks() - m_last_size_change < 250)
      return;

   m_last_size_change = SDL_GetTicks();

   for (size_t i = 0 ; i < m_col_grid.size() ; ++i)
   {
      m_col_grid[i].push_back('.');
      m_look_grid[i].push_back(tileset.get_tile(AIR));
   }
}

void Grid::remove_h ()
{
   if (SDL_GetTicks() - m_last_size_change < 250)
      return;

   m_last_size_change = SDL_GetTicks();

   for (size_t i = 0 ; i < m_col_grid.size() ; ++i)
   {
      if (m_col_grid[i].size() > 0)
      {
         m_col_grid[i].pop_back();
         m_look_grid[i].pop_back();
      }
   }
}
