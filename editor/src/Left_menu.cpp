#include "Left_menu.h"

Left_menu::Left_menu (SDL_Renderer* renderer) :
           m_look(uts::loag_img(DEFAULT_LEFT_MENU_PATH, renderer)),
           m_pos { 0, 0, 100 800 },
           m_fields { 0, 0 100, 45 }
{

}

Left_menu::~Left_menu () {
   
}

void Left_menu::print(SDL_Renderer* renderer)
{
   SDL_RenderCopy(renderer, m_look, NULL, &m_pos);
}

void Left_menu::click(SDL_Point mouse, Grid grid)
{
   if (SDL_PointInRect(&mouse, m_fields[0]))
   {
      save_map(grid);
      return true;
   }
   else
      return false;
}

void Left_menu::save_map(Grid grid)
{
      // on commence par ouvrir le bon fichier en mode écriture
   std::ofstream file ("../data/lvls/" + (std::string){ std::to_string(lvl_id) + ".lvl" }, ios::trunc);
   if (!file) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "ERROR: [Loader::load_lvl] error when loading the lvl config file <%s>.", ((std::string){ "../data/lvls_configs/" + std::to_string(lvl_id) + ".lvl" }).c_str ());
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "cannot load lvl 1. abort.");
      exit(EXIT_FAILURE);
   }

   file << "\\tileset" << std::endl;
   file << "1" << std::endl;
   file << "   \\path" << std::endl;
   file << "   ../data/tileset/dark.png" << std::endl;
   file << "\\map" << std::endl;
   file << "   \\sizeX" << std::endl;
   file << "   " << grid.get_grid().size() << std::endl;

   std::cout << "X : " << grid.get_grid().size() << std::endl;

   file << "   \\sizeY" << std::endl;
   file << "   " << grid.get_grid()[0].size() << std::endl;

   std::cout << "Y : " << grid.get_grid()[0].size() << std::endl;

   file << "   \\map" << std::endl;

   for (size_t i = 0 ; i < grid.get_grid().size() ; ++i)
   {
      for (size_t j = 0 ; j < grid.get_grid()[0].size() ; ++j)
        file << grid.get_grid()[i][j];
      file << std::endl;
   }
}
