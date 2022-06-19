/*
 * Foreground.h
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



#ifndef FOREGROUND_H
 #define FOREGROUND_H

 #include <SDL2/SDL.h>
 #include <iostream>
 #include "utilities.h"
 #include "Context.h"


/**************************
 * classe Foreground :    *
 * -------------------    *
 * Décors du premier plan *
 * (devant le personnage) *
 **************************/

class Foreground {

  public:

   Foreground ();
   Foreground (const char* path, SDL_Renderer* renderer);
   Foreground (std::string path, SDL_Renderer* renderer);
   ~Foreground ();

   void print (SDL_Renderer* renderer);

  private:

      // apparence de l'avant plan
   SDL_Texture* m_look;

      // portion de l'avant plan affichée
   SDL_Rect m_pos;
};

#endif
