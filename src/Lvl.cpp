/*
 * Lvl.cpp
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

 
#include "Lvl.h"


/******************************************************************
 * Lvl :                                                          *
 * ------                                                         *
 * constructeur de la classe Lvl                                  *
 * C'est cette fonction qui sera appelée à la création de l'objet *
 ******************************************************************/

Lvl::Lvl (SDL_Renderer* renderer, const size_t & lvl_id) :
     m_spawn { DEFAULT_PERSO_POS_X, DEFAULT_PERSO_POS_Y } {
   load_lvl (lvl_id, renderer);
}


/**********************************************************************
 * ~Lvl :                                                             *
 * ------                                                             *
 * destructeur de la classe Lvl                                       *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Lvl::~Lvl () {
   
}


/*****************************
 * load_lvl :                *
 * ----------                *
 * charge le niveau spécifié *
 *****************************/

bool Lvl::load_lvl (const size_t & lvl_id, SDL_Renderer* renderer) {

   /* =================================================== *
    * Pour comprendre la manière donc sont stockées       *
    * les informations, allez voir le fichier 'aide.lvl'. *
    * =================================================== */

   std::ifstream f { compile_lvl_file (lvl_id) };

   if (!f)
      return false;

   std::ifstream& file = f;

   load_background (file, renderer);
   load_tileset (file, renderer);
   load_grid (file);
   load_foreground (file, renderer);

   return true;
}

/**********************************************************
 * load_background :                                      *
 * -----------------                                      *
 * charge le background depuis un fichier lvl             *
 * Attention : le curseur doit être placé au bon endroit. *
 **********************************************************/

void Lvl::load_background (std::ifstream& file, SDL_Renderer* renderer) {

      // on voit si il y a un arrière plan spécifique au niveau
   int has_background { 0 };
   file >> has_background;

   if (has_background == 1) {

         // position et taille de l'arrière plan
      int posX, posY, sizeX, sizeY;
      file >> posX >> posY >> sizeX >> sizeY;

         // chemin de l'image de l'arrière-plan
      std::string background_path;
      file.ignore();
      std::getline (file, background_path);

         // on configure l'arrière plan en conséquence
      m_background = (Background){ background_path.c_str (), renderer };
   }
//   else { mettre un arrière plan par défaut. }
}


/*************************************
 * load_tileset :                    *
 * --------------                    *
 * charge le jeu de tuiles du niveau *
 *************************************/

void Lvl::load_tileset (std::ifstream& file, SDL_Renderer* renderer) {

      // on voit si il y a un tileset spécifique au niveau
   int has_tileset { 0 };
   file >> has_tileset;

   if (has_tileset == 1) {
      std::string path;
      file >> path;

         // temporaire
      m_tileset.load (DEV_TILESET_PATH, renderer);

// TODO      m_tileset.load (path);
   }
// else { tileset par défaut ? } TODOs
}


/***************************
 * load_grid :             *
 * --------------          *
 * charge la map elle-même *
 ***************************/

void Lvl::load_grid (std::ifstream& file) {


      // taille de la grille
   size_t sizeX, sizeY;
   file >> sizeX >> sizeY;

   file.ignore();

      // on crée la grille
      // pour cela, on utilise un vector représentant une ligne par défaut,
      // pour pouvoir initisaliser directement la grille, sans boucles.
   std::vector<char> default_line(sizeY, ' ');
   std::vector<std::vector<char>> grid(sizeX, default_line);

      // puis on lui assigne la map contenue dans le fichier
   for (size_t i { 0 } ; i < sizeY ; ++i) {
      for (size_t j { 0 } ; j < sizeX ; ++j) {
         grid[j][i] = file.get();
         if (grid[j][i] == '\n')
            --j;
         else if (grid[j][i] == 'S') {
            m_spawn.x = j * 25;
            m_spawn.y = i * 25;
         }
      }
   }

      // et on la charge dans la classe correspondante
   m_grid.load (grid, m_tileset);
}


void Lvl::load_foreground (std::ifstream& file, SDL_Renderer* renderer) {

         // on voit si le niveau utilise un avant-plan
   int has_foreground;
   file >> has_foreground;

      // si oui
   if (has_foreground == 1) {

         // on récupère son chemin
      std::string foreground_path;
      std::getline (file >> std::ws, foreground_path);

         // on configure l'avant-plan en conséquence
      m_foreground = (Foreground){foreground_path.c_str (), renderer};
   }
// else { foreground par défaut ? } TODO
}

/*******************************************************************
 * compile_lvl_file :                                              *
 * ------------------                                              *
 * enlève les espaces en début de ligne ainsi que les commentaires *
 * à partir d'un fichier .lvl                                      *
 *******************************************************************/

std::ifstream Lvl::compile_lvl_file (const size_t & lvl_id) {

      // on commence par ouvrir le bon fichier en lecture.
      // les fichiers de sauvegarde sont au format [niveau].lvl
      // donc par exemple pour le niveau 1 on ouvre 1.lvl
   std::ifstream file ("../data/lvls_configs/" + (std::string){ std::to_string(lvl_id) + ".lvl" });
   if (!file) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Lvl::load_lvl] error when loading the lvl config file <%s>.", ((std::string){ "../data/lvls_configs/" + std::to_string(lvl_id) + ".lvl" }).c_str ());
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "cannot load lvl 1. abort.");
      exit(EXIT_FAILURE);
   }

      // le futur fichier compilé
   std::ofstream compiled_file { "compiled_" + (std::string){ std::to_string(lvl_id) } + ".Clvl" };

   std::string tmp_line;
   while (std::getline(file, tmp_line)) { // pour chaque ligne du fichier

         // on enlève les espaces au début
      tmp_line.erase (std::begin (tmp_line), std::find_if_not (std::begin (tmp_line), std::end (tmp_line), isspace));
         // et les commentaires (ce qu'il y a après un '%')
      tmp_line.erase (std::find (std::begin(tmp_line), std::end (tmp_line), '%'), std::end(tmp_line));

         // on la copie dans le nouveau fichier si ce n'est pas une indication
      if (tmp_line [0] != '\\')
         compiled_file << tmp_line << std::endl;
   }

      // on retourne un flux de lecture pour le nouveau fichier
   std::ifstream returned_file { "compiled_" + (std::string){ std::to_string(lvl_id) } + ".Clvl" };
   return returned_file;
}


/***************************
 * get_background :        *
 * ----------------        *
 * retourne l'arrière plan *
 ***************************/

Background Lvl::get_background () const {
   return m_background;
}


/*************************
 * get_foreground :      *
 * ----------------      *
 * retourne l'avant plan *
 *************************/

Foreground Lvl::get_foreground () const {
   return m_foreground;
}


/************************************
 * print_grid :                    *
 * -------------                    *
 * affiche tous les blocs du niveau *
 ************************************/

void Lvl::print_grid (SDL_Renderer* renderer, int x_offset, int y_offset) {
   m_grid.print (renderer, x_offset, y_offset);
}


/********************************
 * get_grid :                   *
 * ------------                 *
 * retourne la grille du niveau *
 ********************************/

Grid Lvl::get_grid () const {
   return m_grid;
}

SDL_Point Lvl::get_spawn () const {
   return m_spawn;
}
