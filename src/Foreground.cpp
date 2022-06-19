/*
 * Foreground.cpp
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

 

#include "Foreground.h"


/**********************************************
 * Foreground :                               *
 * ------------                               *
 * constructeur par défaut                    *
 * (appelé lors de la construction de l'objet *
 * si aucun argument n'est donné)             *
 **********************************************/

Foreground::Foreground () : 
            m_look { NULL },
            m_pos { 0, 0, 0, 0 } {

}

/*******************************************************************
 * Foreground :                                                    *
 * ------                                                          *
 * constructeur de la classe Foreground                            *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si on le crée avec une chaine de caractères (le chemin de       *
 * l'image du décor) et un renderer.                               *
 *******************************************************************/

Foreground::Foreground (const char* path, SDL_Renderer* renderer) :
            m_look { uts::load_img (path, renderer) },
            m_pos { 0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT } {

   if (!m_look)
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Background::Background(const char*, SDL_Renderer*)] %s", SDL_GetError ());
}


/*******************************************************************
 * Foreground :                                                    *
 * ------                                                          *
 * constructeur de la classe Foreground                            *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si on le crée avec une chaine de caractères (le chemin de       *
 * l'image du décor) et un renderer.                               *
 *******************************************************************/

Foreground::Foreground (std::string path, SDL_Renderer* renderer) :
            m_look { uts::load_img (path.c_str(), renderer) },
            m_pos { 0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT } {

   if (!m_look)
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Background::Background(const char*, SDL_Renderer*)] %s", SDL_GetError ());
}


/**********************************************************************
 * ~Foreground :                                                      *
 * ------                                                             *
 * destructeur de la classe Foreground                                *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Foreground::~Foreground () {

// // TODO: si commenté, bg affiché... (??)
// // --> Oui : problème vient probablement de Lvl::get_Foreground () : retourne un objet Foreground...
// //     => chercher pourquoi le destructeur est appelé lors d'un 'return m_Foreground;'.

//    SDL_DestroyTexture (m_look);

//    std::cout << "[Foreground::~] : [##-debug-##] textures destoyed." << std::endl;
}


/************************
 * print :              *
 * -------              *
 * affiche l'avant plan *
 ************************/

void Foreground::print (SDL_Renderer* renderer) {

      // on affiche la bonne portion de l'arrière plan
   SDL_RenderCopy (renderer, m_look, &m_pos, NULL);
}
