/*
 * Background.h
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



#ifndef BACKGROUND_H
 #define BACKGROUND_H

 #include <SDL2/SDL.h>
 #include <iostream>
 #include "utilities.h"
 #include "Context.h"

class Background {

  public:

   Background ();
   Background (const char* path, SDL_Renderer* renderer);
   Background (const char* bg_path, const char* filter_path, SDL_Renderer* renderer);
   ~Background ();

   void print (SDL_Renderer* renderer);
   void print_filter (SDL_Renderer* renderer);
   bool get_has_filter () const;

  private:

      // apparence de l'arrière plan
   SDL_Texture* m_look;

      // portion de l'arrière plan affichée
   SDL_Rect m_pos;

      // si l'arrière plan a un filtre (pour faire certains effets)
   bool m_has_filter;

      // apparence du filtre (si il n'y en a pas, vaut NULL)
   SDL_Texture* m_filter;
};

#endif
