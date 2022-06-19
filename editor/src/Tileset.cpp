/*
 * Tileset.cpp
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

//   m_tiles_global_look = uts::load_img (path.c_str(), renderer);


      // [TODO] Un seul fichier rassemblant toutes les images (fourni via l'arg path).
      // --> le découper en plusieurs textures, mais garder un seul fichier de départ
   std::vector<std::string> files_names
   {
      "../data/imgs/tiles/dev.png",
      "../data/imgs/tiles/left.png",
      "../data/imgs/tiles/bottom.png",
      "../data/imgs/tiles/right.png",
      "../data/imgs/tiles/top.png",
      "../data/imgs/tiles/top_left.png",
      "../data/imgs/tiles/bottom_left.png",
      "../data/imgs/tiles/top_right.png",
      "../data/imgs/tiles/bottom_right.png",
      "../data/imgs/tiles/center_top_left.png",
      "../data/imgs/tiles/center_bottom_left.png",
      "../data/imgs/tiles/center_top_right.png",
      "../data/imgs/tiles/center_bottom_left.png"
   };


   m_tiles_look.clear();
   for (size_t i = 0 ; i < 13 ; ++i)
      m_tiles_look.push_back(uts::load_img(files_names[i].c_str(), renderer));

   m_tiles_look[0];
   std::cout << "safe ?" << std::endl;

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
