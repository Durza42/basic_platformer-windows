#ifndef TILEMENU_H
 #define TILEMENU_H

 #define TILEMENU_PATH "../data/imgs/tile_menu.png"

 #include <SDL2/SDL.h>
 #include <vector>
 #include "utilities.h"

class Tilemenu {

  public:

   Tilemenu ();
   Tilemenu (SDL_Renderer* renderer);
   ~Tilemenu ();

   void load (SDL_Renderer* renderer);
   void print (SDL_Renderer* renderer);
   bool is_clicked(SDL_Point mouse);
   bool is_clicked_right(SDL_Point mouse);

   void set_tile(int x, int y);

  private:

   SDL_Texture* m_look;
   SDL_Rect m_pos;

   std::vector<SDL_Rect> m_fields;
};

#endif
