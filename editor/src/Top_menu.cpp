/*
 * Top_menu.cpp
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

 
#include "Top_menu.h"

Top_menu::Top_menu (SDL_Renderer* renderer) :
          m_hitboxes { { 0, 0, 75, TOP_MENU_HEIGHT },
                       { 75, 0, 75, TOP_MENU_HEIGHT } },
          m_look { uts::load_img("../data/imgs/top_menu.png", renderer) },
          m_global_hitbox { 0, 0, 75 * 2, TOP_MENU_HEIGHT },
          m_menus_hitboxes { { 0, 25, 200, 300 },
                             { 75, 25, 200, 300 }, },
          m_menus_looks { { uts::load_img("../data/imgs/top_menu_fichier.png", renderer) },
                          { uts::load_img("../data/imgs/top_menu_edition.png", renderer) } },
          m_iMenu { -1 }
{
   
}

Top_menu::~Top_menu () {
   
}

bool Top_menu::click (SDL_Point mouse)
{
   m_iMenu = -1;
   for (size_t i = 0 ; i < m_hitboxes.size() ; ++i)
   {
      if (SDL_PointInRect(&mouse, &m_hitboxes[i]))
      {
         int m_iMenu = i;
         return true;
      }
   }
   return false;
}

void Top_menu::print (SDL_Renderer* renderer)
{
   SDL_RenderCopy(renderer, m_look, NULL, &m_global_hitbox);
   if (m_iMenu != -1)
      SDL_RenderCopy(renderer, m_menus_looks[m_iMenu], NULL, &m_menus_hitboxes[m_iMenu]);
}
