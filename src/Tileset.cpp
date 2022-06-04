#include "Tileset.h"

Tileset::Tileset () {
   
}

Tileset::~Tileset () {
   
}


/*****************************************************
 * load :                                            *
 * ------                                            *
 * charge le tileset à partir du chemin de son image *
 *****************************************************/

void Tileset::load (std::string path, SDL_Renderer* renderer) {

   m_tiles_global_look = uts::load_img (path.c_str(), renderer);

   for (size_t i = 0 ; i < 13 ; ++i)
      m_tiles_look.push_back(NULL);

      // temporaire. version de développement.
   for (size_t i {0} ; i < m_tiles_look.size() ; ++i)
      m_tiles_look [i] = m_tiles_global_look;

   // [TODO] découper la texture en rectangles ?
//   m_tiles_look [i] = SDL_SetTextInputRect (m_tiles_global_look, &full_rect);

}



/*********************************************************
 * get_tile :                                            *
 * ----------                                            *
 * renvoie la texture correspondant à la position voulue *
 *********************************************************/

SDL_Texture* Tileset::get_tile (Tiletype type) {
   return m_tiles_look [type];
}
