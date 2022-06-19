/*
 * Background.cpp
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

 

#include "Background.h"


/***************************************************
 * Background :                                    *
 * ------------                                    *
 * constructeur par défaut de la classe background *
 ***************************************************/

Background::Background () :
            m_look { NULL },
            m_pos { 0, 0, 0, 0 },
            m_has_filter { false },
            m_filter { NULL } {

}


/*******************************************************************
 * Background :                                                    *
 * ------                                                          *
 * constructeur de la classe Background                            *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si on le crée avec une chaine de caractères (le chemin de       *
 * l'image du décor) et un renderer.                               *
 *******************************************************************/

Background::Background (const char* path, SDL_Renderer* renderer) :
            m_look { uts::load_img (path, renderer) },
            m_pos { 0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT },
            m_has_filter { false },
            m_filter { NULL } {

   if (!m_look)
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Background::Background(const char*, SDL_Renderer*)] %s", SDL_GetError ());
}


/*******************************************************************
 * Background :                                                    *
 * ------                                                          *
 * constructeur de la classe Background                            *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si on le crée avec deux chaine de caractères (les chemins des   *
 * images du décor et du filtre) et un renderer.                   *
 *******************************************************************/

Background::Background (const char* bg_path, const char* filter_path, SDL_Renderer* renderer) :
            m_look { uts::load_img (bg_path, renderer) },
            m_pos { 0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT },
            m_has_filter { true },
            m_filter { uts::load_img (filter_path, renderer) } {

   if (!m_look)
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Background::Background(const char*, SDL_Renderer*)] %s", SDL_GetError ());

   if (!m_filter)
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Background::Background(const char*, SDL_Renderer*)] %s", SDL_GetError ());
}

/**********************************************************************
 * ~Background :                                                      *
 * ------                                                             *
 * destructeur de la classe Background                                *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Background::~Background () {

// // TODO: si commenté, bg affiché... (??)
// // --> Oui : problème vient probablement de Lvl::get_background () : retourne un objet background...
// //     => chercher pourquoi le destructeur est appelé lors d'un 'return m_background;'.

//    SDL_DestroyTexture (m_look);
//    SDL_DestroyTexture (m_filter);

//    std::cout << "[Background::~] : [##-debug-##] textures destoyed." << std::endl;
}


/**************************
 * print :                *
 * -------                *
 * affiche l'arrière plan *
 **************************/

void Background::print (SDL_Renderer* renderer) {

      // on affiche la bonne portion de l'arrière plan
   SDL_RenderCopy (renderer, m_look, &m_pos, NULL);

}


/*********************
 * print_filter :    *
 * -------           *
 * affiche le filter *
 **********************/

void Background::print_filter (SDL_Renderer* renderer) {

      // si il y a un filtre
   if (m_has_filter)
      SDL_RenderCopy (renderer, m_filter, NULL, NULL); // on l'applique 

}


/**************************************************
 * has_filter :                                   *
 * ------------                                   *
 * retourne vrai si il y a un filtre, faux sinon. *
 **************************************************/

bool Background::get_has_filter () const {
   return m_filter;
}
