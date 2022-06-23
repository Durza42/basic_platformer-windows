#include "Left_menu.h"

Left_menu::Left_menu (SDL_Renderer* renderer) :
           m_look(uts::load_img(DEFAULT_LEFT_MENU_PATH, renderer)),
           m_pos { 0, 0, 100, 800 },
           m_fields { { 0, 0, 100, 45 } }
{

}

Left_menu::~Left_menu () {
   
}

void Left_menu::print(SDL_Renderer* renderer)
{
   SDL_RenderCopy(renderer, m_look, NULL, &m_pos);
}

void Left_menu::click(SDL_Point mouse, std::vector<std::vector<char>> grid)
{
   if (SDL_PointInRect(&mouse, &m_fields[0]))
      save_map(grid);
}

void Left_menu::save_map(std::vector<std::vector<char>> grid)
{
   std::cout << "Saving" << std::endl;

      // on commence par ouvrir le bon fichier en mode écriture
   std::ofstream file ("../data/lvls/edited.lvl", std::ios::trunc);
   if (!file) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "cannot save edited map under ../data/lvls/edited.lvl;\nAbort.");
      // TODO: solution de ratrapage
      exit(EXIT_FAILURE);
   }

   file << "\\tileset" << std::endl;
   file << "1" << std::endl;
   file << "   \\path" << std::endl;
   file << "   ../data/tileset/dark.png" << std::endl;
   file << "\\map" << std::endl;
   file << "   \\sizeX" << std::endl;
   file << "   " << grid.size() << std::endl;

   std::cout << "X : " << grid.size() << std::endl;

   file << "   \\sizeY" << std::endl;
   file << "   " << grid[0].size() << std::endl;

   std::cout << "Y : " << grid[0].size() << std::endl;

   file << "   \\map" << std::endl;

   for (size_t j = 0 ; j < grid[0].size() ; ++j)
   {
      for (size_t i = 0 ; i < grid.size() ; ++i)
         file << grid[i][j];
      file << std::endl;
   }
}
