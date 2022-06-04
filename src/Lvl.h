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
};

#endif
