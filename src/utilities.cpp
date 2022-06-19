/*
 * utilities.cpp
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

 
#include "utilities.h"

/*******************************************
 * load_img :                              *
 * ----------                              *
 * renvoie une SDL_Texture affichable à la *
 * fenêtre à partir du chemin de l'image   *
 *******************************************/

SDL_Texture* uts::load_img (const char* path, SDL_Renderer *renderer) {

      // on charge l'image dans une SDL_Surface
   SDL_Surface* tmp { NULL };
   tmp = IMG_Load (path);

      // si il y a eu une erreur (par ex. que l'image n'existe pas)
   if (!tmp) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[uts::load_img] Erreur when loading %s : %s", path, IMG_GetError()); // on affiche un message d'erreur
      return NULL; // on retourne une erreur
   }

      // on rend tous les pixels de la SDL_Surface squi sont blancs transparants
   SDL_SetColorKey (tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

      // on crée une SDL_Texture à partir de la SDL_Surface
   SDL_Texture *tex { NULL };
   tex = SDL_CreateTextureFromSurface (renderer, tmp);

      // on libère la SDL_Surface, maintenant inutilisée
   SDL_FreeSurface (tmp);

      // si il y a eu une erreur
   if (tex == NULL) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[uts::load_img] Erreur when creating SDL_Texture for %s : %s", path, SDL_GetError()); // on affiche un message
      return NULL; // on retourne une erreur
   }

      // si tout s'est bien passé
   return tex; // on retourne la SDL_Texture finale
}
