/*
 * Context.h
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



#ifndef CONTEXT_H
 #define CONTEXT_H

 #include <SDL2/SDL.h>

 #define REFRESH_RATE (1000. / 30.) // 30 fps

 #define DEFAULT_WINDOW_HEIGHT 800
 #define DEFAULT_WINDOW_WIDTH  1200

/*****************************************************
 * classe Context :                                  *
 * ----------------                                  *
 * s'occupe du contexte du jeu comme la fenêtre      *
 * ou des ressources comme les polices de caractère. *
 *****************************************************/

class Context {

  public:

   Context ();
   ~Context ();

   SDL_Renderer* get_renderer () const;

  private:

      // la fenêtre
   SDL_Window* m_window;
      // C'est en quelque sorte la feuille que l'on colle à la fenêtre.
      // C'est ici que l'on va "dessiner" le jeu.
   SDL_Renderer* m_renderer;
};

#endif
