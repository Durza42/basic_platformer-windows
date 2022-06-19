/*
 * Tileset.h
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


#ifndef TILESET_H
 #define TILESET_H

 #include <SDL2/SDL.h>
 #include <string>
 #include <vector>
 #include "utilities.h"

 #define DEFAULT_TILESET_PATH "../data/imgs/tiles/blue_dev_tiles.png"
 #define DEV_TILESET_PATH "../data/imgs/tiles/dev.png"

/****************************************************
 * enum Tiletype :                                  *
 * ---------------                                  *
 * les différentes tuiles de mur qu'il peut y avoir *
 ****************************************************/

enum Tiletype {
   FULL = 0,
   LEFT = 1,
   DOWN = 2,
   RIGHT = 3,
   UP = 4,
   CORNER_LEFT_UP = 5,
   CORNER_LEFT_DOWN = 6,
   CORNER_RIGHT_UP = 7,
   CORNER_RIGHT_DOWN = 8,
   LINK_LEFT_UP = 9,
   LINK_LEFT_DOWN = 10,
   LINK_RIGHT_UP = 11,
   LINK_RIGHT_DOWN = 12
};


/*
 * classe Tileset :
 * ----------------
 * Représente un jeu de tuiles.
 * l'apparence d'un bloc est donnée par cette classe. *
 */

class Tileset {

  public:

   Tileset ();
   ~Tileset ();

   void load (std::string path, SDL_Renderer* renderer); // <- TODO
   SDL_Texture* get_tile (Tiletype type);

  private:

      // l'apparence de chaque tuile.
      // On renvoiera une partie de la texure lorsqu'une tuile sera demandée.
   SDL_Texture* m_tiles_global_look;
   std::vector<SDL_Texture*> m_tiles_look;
};

#endif
