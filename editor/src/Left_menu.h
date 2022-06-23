#ifndef LEFT_MENU_H
 #define LEFT_MENU_H

 #include <vector>
 #include <string>
 #include <fstream>
 #include <SDL2/SDL.h>

 #include "Grid.h"

 #define DEFAULT_LEFT_MENU_PATH "../data/imgs/left_menu.png"

class Left_menu {

  public:

   Left_menu (SDL_Renderer* renderer);
   ~Left_menu ();

   void print(SDL_Renderer* renderer);

   void click(SDL_Point mouse, std::vector<std::vector<char>> grid);

   void save_map(std::vector<std::vector<char>> grid);

  private:

   SDL_Texture* m_look;
   SDL_Rect m_pos;

   std::vector<SDL_Rect> m_fields;
};

#endif
