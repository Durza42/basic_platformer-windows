#ifndef GRID_H
 #define GRID_H

 #include <iostream> // TODO: remove

 #include <SDL2/SDL.h>
 #include <vector>
 #include <cmath>

 #include "Tileset.h"
// #include "Tilemenu.h"
 #include "Context.h"

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

   void print (SDL_Renderer* renderer);
   void automap (Tileset tileset); // <- TODO

   bool has_col (SDL_Rect & r) const;
   bool is_wall (size_t x, size_t y) const;

   int get_x_offset () const;
   int get_y_offset () const;
   void set_offset (int x, int y);
   std::vector<std::vector<char>> get_grid() const;

   bool is_clicked (SDL_Point mouse, Tileset tileset);
   bool is_clicked_right (SDL_Point mouse, Tileset tileset);
   bool is_clicked_middle (SDL_Point mouse);
   void is_not_clicked_middle ();

   void add_w (Tileset tileset);
   void remove_w ();
   void add_h (Tileset tileset);
   void remove_h ();

  private:

      // une grille (2D) de caractères : 'X' pour un mur, '.' pour du vide, etc. Voir "../data/lvls_config/aide.lvl" pour la liste complète.
   std::vector<std::vector<char>> m_col_grid;

      // la grille qui apparaitra à l'écran
   std::vector<std::vector<SDL_Texture*>> m_look_grid;

      // la partie de la fenêtre où il y aura la map
   SDL_Rect m_part_of_screen;

      // le menu s'affichant lors du clique sur les tuiles
//   Tilemenu m_tilemenu;

   int m_x_offset, m_y_offset;

      // emplacement de la souris avant le mouvement de la grille
   SDL_Point m_mouse_before_moove;

   unsigned long int m_last_size_change;
};

#endif
