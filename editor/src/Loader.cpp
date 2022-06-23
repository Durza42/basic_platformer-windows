#include "Loader.h"


/*****************************
 * load_lvl :                *
 * ----------                *
 * charge le niveau spécifié *
 *****************************/

bool Loader::load (const size_t & lvl_id, SDL_Renderer* renderer, Grid& grid, Tileset& tileset) {

   /* =================================================== *
    * Pour comprendre la manière donc sont stockées       *
    * les informations, allez voir le fichier 'aide.lvl'. *
    * =================================================== */

   std::ifstream f { compile_lvl_file (lvl_id) };

   if (!f)
      return false;

   std::ifstream& file = f;

   load_tileset (file, renderer, tileset);
   tileset.get_tile(FULL);
   load_grid (file, grid, tileset);

   return true;
}


/*************************************
 * load_tileset :                    *
 * --------------                    *
 * charge le jeu de tuiles du niveau *
 *************************************/

void Loader::load_tileset (std::ifstream& file, SDL_Renderer* renderer, Tileset& tileset) {

      // on voit si il y a un tileset spécifique au niveau
   int has_tileset { 0 };
   file >> has_tileset;

   if (has_tileset == 1) {
      std::string path;
      file >> path;

         // temporaire
      tileset.load (renderer);
   }
// else { tileset par défaut ? } TODO
}


/***************************
 * load_grid :             *
 * --------------          *
 * charge la map elle-même *
 ***************************/

void Loader::load_grid (std::ifstream& file, Grid& grid, Tileset& tileset) {

      // taille de la grille
   size_t sizeX = 0, sizeY = 0;
   file >> sizeX >> sizeY;

   file.ignore();

      // on crée la grille
      // pour cela, on utilise un vector représentant une ligne par défaut,
      // pour pouvoir initisaliser directement la grille, sans boucles.
   std::vector<char> default_line(sizeY, ' ');
   std::vector<std::vector<char>> tmp_grid(sizeX, default_line);

      // puis on lui assigne la map contenue dans le fichier
   for (size_t i { 0 } ; i < sizeY ; ++i) {
      for (size_t j { 0 } ; j < sizeX ; ++j) {
         tmp_grid[j][i] = file.get();
         if (tmp_grid[j][i] == '\n')
            --j;
      }
   }
      // et on la charge dans la classe correspondante
   grid.load (tmp_grid, tileset);
}


/*******************************************************************
 * compile_lvl_file :                                              *
 * ------------------                                              *
 * enlève les espaces en début de ligne ainsi que les commentaires *
 * à partir d'un fichier .lvl                                      *
 *******************************************************************/

std::ifstream Loader::compile_lvl_file (const size_t & lvl_id) {

      // on commence par ouvrir le bon fichier en lecture.
      // les fichiers de sauvegarde sont au format [niveau].lvl
      // donc par exemple pour le niveau 1 on ouvre 1.lvl
   std::ifstream file ("../data/lvls/" + (std::string){ std::to_string(lvl_id) + ".lvl" });
   if (!file) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Loader::load_lvl] error when loading the lvl config file <%s>.", ((std::string){ "../data/lvls_configs/" + std::to_string(lvl_id) + ".lvl" }).c_str ());
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

