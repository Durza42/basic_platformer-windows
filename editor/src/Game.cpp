/*
 * Game.cpp
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

 
#include "Game.h"

Game::Game () :
      m_top_menu { m_context.get_renderer() }
      m_left_menu { m_context.get_renderer() }
{
   Loader::load(1, m_context.get_renderer(), m_grid, m_tileset);

   SDL_SetRenderDrawColor(m_context.get_renderer(), CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B, 255);
}

Game::~Game ()
{
   
}

void Game::main_loop ()
{
      // apparence de base de la fenêtre
   refresh();

   while (manage_input())
   {
      
   }
}

bool Game::manage_input ()
{
   if (m_input.update())
      refresh(); // on ne rafraichit que si quelque-chose a changé

   if (m_input.request_close())
      return false;

   if (m_input.get_key(SDL_SCANCODE_ESCAPE))
      return false;

   if (m_input.mouse_is_clicked())
   {
      m_top_menu.click(m_input.get_mouse_pos());
      m_left_menu.click(m_input.get_mouse_pos());
      m_grid.is_clicked(m_input.get_mouse_pos(), m_tileset);
   }

   if (m_input.mouse_is_clicked_right())
      m_grid.is_clicked_right(m_input.get_mouse_pos(), m_tileset);

   if (m_input.mouse_is_clicked_middle())
      m_grid.is_clicked_middle(m_input.get_mouse_pos());
   else
      m_grid.is_not_clicked_middle();

   return true;
}

void Game::refresh ()
{
   SDL_RenderClear(m_context.get_renderer());

   m_grid.print(m_context.get_renderer());

   SDL_Rect left_side { 0, 0, 100, DEFAULT_WINDOW_HEIGHT };
   SDL_Rect top_side { 0, 0, DEFAULT_WINDOW_WIDTH, 50 };

   SDL_RenderFillRect(m_context.get_renderer(), &left_side);
   SDL_RenderFillRect(m_context.get_renderer(), &top_side);

   m_top_menu.print(m_context.get_renderer());
   m_left_menu.print(m_context.get_renderer());

   SDL_RenderPresent(m_context.get_renderer());
}
