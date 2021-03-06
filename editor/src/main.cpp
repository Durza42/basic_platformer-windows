/*
 * main.cpp
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

 
#include <SDL2/SDL.h>
#include "Game.h"

// la SDL de Windows a besoin de argc & argv.
#if defined (_WIN32) || defined(WIN32) || defined(__WIN32__)
int main (int argc, char** argv) {
#else
int main () {
#endif

   Game game;
   game.main_loop();

   return EXIT_SUCCESS;
}
