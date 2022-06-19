/*
 * Input.h
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


#ifndef INPUT_H
 #define INPUT_H

 #include <SDL2/SDL.h>
 #include <cstddef>

/*************************************
 * classe Input :                    *
 * --------------                    *
 * Permet la gestion des évènements  *
 * (touches appuillées, souris, ...) *
 *************************************/

class Input {

  public:

   Input ();
   ~Input ();

   bool update ();

   bool request_close () const;
   const bool* get_keys_array () const;
   bool get_key (size_t const & key) const;

  private:

      // contient les évènements
   SDL_Event m_event;

      // pour chaque touche du clavier, true si elle este enfoncée, false sinon.
   bool m_keys [SDL_NUM_SCANCODES];

      // true si la fenêtre doit être fermée
   bool m_request_close;
};

#endif
