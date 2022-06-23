#ifndef LOADER_H
 #define LOADER_H

 #include <SDL2/SDL.h>

 #include <iostream> // TODO: remove

 #include <fstream>
 #include <cstddef>
 #include <algorithm>

 #include "Grid.h"
 #include "Tileset.h"

namespace Loader {
   bool load (const size_t & lvl_id, SDL_Renderer* renderer, Grid& grid, Tileset& tileset);
   void load_tileset (std::ifstream& file, SDL_Renderer* renderer, Tileset &tileset);
   void load_grid (std::ifstream& file, Grid& grid, Tileset& tileset);
   std::ifstream compile_lvl_file (const size_t & lvl_id);
};

#endif
