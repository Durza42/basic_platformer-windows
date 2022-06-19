/*
 * Perso.h
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


#ifndef PERSO_H
 #define PERSO_H

 #include <SDL2/SDL.h>
 #include <iostream>
 #include <vector>
 #include <cmath>
 #include "utilities.h"
 #include "Vector.h"
 #include "Grid.h"
 #include "Context.h"

 #define DEFAULT_PERSO_POS_X 400
 #define DEFAULT_PERSO_POS_Y 300

 #define PERSO_HEIGHT   45
 #define PERSO_WIDTH    45

 #define MOOVE_ADD   7.5
 #define JUMP_ADD    (-25)
 #define GRAVITY_ADD 2

class Perso {

  public:

   Perso ();
   Perso (const char* path, SDL_Renderer* renderer);
   Perso (const char* path, SDL_Renderer* renderer, SDL_Point spawn);
   ~Perso ();

   void print (SDL_Renderer* renderer);

   void go_right ();
   void go_left ();
   void jump ();

   void moove_x (const Grid & grid);
   void moove_y (const Grid & grid);
   void loose_speed ();
   void fall (const Grid & grid);
   bool moove (const Grid & grid);

   SDL_Point get_offset () const;

  private:

      // apparence du perso
   SDL_Texture* m_look;

      // position du perso
   SDL_Rect m_pos;

      // vecteur unitaire direction du perso
   Vector m_dir;

      // vecteur mouvement du perso
   Vector m_moove;

      // vaut true si le perso peut sauter, false sinon
   bool m_can_jump;
};

#endif
