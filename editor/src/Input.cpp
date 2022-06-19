/*
 * Input.cpp
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

 
#include "Input.h"


/***************************
 * Input :                 *
 * -------                 *
 * constructeur par défaut *
 ***************************/

Input::Input () : 
       m_keys { false },
       m_request_close { false }
{
   
}


/**************************
 * ~Input :               *
 * --------               *
 * destructeur par défaut *
 **************************/

Input::~Input ()
{
   
}


/************************************
 * update :                         *
 * --------                         *
 * met à jour le tableau de touches *
 ************************************/

bool Input::update ()
{

      // si il y a de nouveaux évènements
   if (SDL_PollEvent (&m_event))
   {
         // tant qu'il reste des évènements à traiter
      do
      {
         switch (m_event.type)
         {
            case SDL_QUIT: // si l'évènement correspond à une fermeture de la fenêtre
               m_request_close = true;
           break;
            case SDL_KEYDOWN: // si c'est un appuie de touche
               m_keys [m_event.key.keysym.scancode] = true;
           break;
            case SDL_KEYUP: // si c'est un relachement de touche
               m_keys [m_event.key.keysym.scancode] = false;
           break;
            case SDL_MOUSEMOTION:
               m_mouse_pos.x = m_event.motion.x;
               m_mouse_pos.y = m_event.motion.y;
           break;
            case SDL_MOUSEBUTTONDOWN:
               m_mouse_is_clicked = true;
           break;
            case SDL_MOUSEBUTTONUP:
               m_mouse_is_clicked = false;
           break;
         }
      } while (SDL_PollEvent (&m_event));
      return true;
   }
   else
      return false;
}


/************************************************
 * request_close :                              *
 * ---------------                              *
 * retourne true si la fenêtre doit être fermée *
 ************************************************/

bool Input::request_close () const
{
   return m_request_close;
}


/****************************************************
 * get_keys_array :                                 *
 * ----------------                                 *
 * renvoie le tableau des touches appuillées ou non *
 ****************************************************/

const bool* Input::get_keys_array () const
{
   return m_keys;
}


/***************************************************
 * get_key :                                       *
 * ----------------                                *
 * renvoie true si la touche spécifiée est pressée *
 ***************************************************/

bool Input::get_key (size_t const & key) const
{
   return m_keys [key];
}


/*************************************
 * get_mouse_pos :                   *
 * ---------------                   *
 * retourne la position de la souris *
 *************************************/

SDL_Point Input::get_mouse_pos () const
{
   return m_mouse_pos;
}


/*************************************************************
 * mouse_is_clicked :                                        *
 * ------------------                                        *
 * retourne true si la souris fait clique gauche, faux sinon *
 *************************************************************/

bool Input::mouse_is_clicked () const
{
   return m_mouse_is_clicked;
}
