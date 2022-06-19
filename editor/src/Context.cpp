/*
 * Context.cpp
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

 
#include "Context.h"


/*******************************************************************
 * Context :                                                       *
 * ---------                                                       *
 * constructeur de la classe context                               *
 * C'est cette fonction qui sera appelée à la création de l'objet. *
 *******************************************************************/

Context::Context () :
         m_window { NULL },
         m_renderer { NULL }
{

      // On essaies d'initialiser la SDL (bibliothèque graphique).
      // Si ça rate, on affiche un message d'erreur et on quitte.
   if (SDL_Init (SDL_INIT_VIDEO) < 0)
   {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[CONTEXT::Context] error when init SDL library: %s\n", SDL_GetError ());
      exit (EXIT_FAILURE);
   }

      // On essaies de créer une fenêtre.
   m_window = SDL_CreateWindow ("editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
      // Si ça rate, on affiche un message d'erreur et on quitte.
   if (!m_window)
   {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[CONTEXT::Context] error when creating window: %s\n", SDL_GetError ());
      exit (EXIT_FAILURE);
   }

      // On essaies de créer le renderer correspondant.
   m_renderer = SDL_CreateRenderer (m_window, -1, SDL_RENDERER_ACCELERATED);
      // Si ça rate, on affiche un message d'erreur et on quitte.
   if (!m_renderer)
   {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[CONTEXT::Context] error when creating renderer: %s\n", SDL_GetError ());
      exit (EXIT_FAILURE);
   }

      // paramètrage de la couleur avec laquelle on effacera la fenêtre (noir)
   SDL_SetRenderDrawColor (m_renderer, 10, 10, 10, 255);

      // on rend le renderer compatible avec la transparence des textures
   SDL_SetRenderDrawBlendMode (m_renderer, SDL_BLENDMODE_BLEND);
}


/******************************************************************
 * ~Context :                                                     *
 * ----------                                                     *
 * destructeur de la classe context                               *
 * C'est la fonction qui sera appelée à la suppression de l'objet *
 ******************************************************************/

Context::~Context ()
{
   SDL_DestroyWindow (m_window);
   SDL_DestroyRenderer (m_renderer);
}


/********************************
 * get_font :                   *
 * ----------                   *
 * permet d'obtenir le renderer *
 ********************************/

SDL_Renderer* Context::get_renderer () const
{
   return m_renderer;
}
