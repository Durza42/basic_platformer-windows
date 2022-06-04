#ifndef BACKGROUND_H
 #define BACKGROUND_H

 #include <SDL2/SDL.h>
 #include <iostream>
 #include "utilities.h"
 #include "Context.h"

class Background {

  public:

   Background ();
   Background (const char* path, SDL_Renderer* renderer);
   Background (const char* bg_path, const char* filter_path, SDL_Renderer* renderer);
   ~Background ();

   void print (SDL_Renderer* renderer);
   void print_filter (SDL_Renderer* renderer);
   bool get_has_filter () const;

  private:

      // apparence de l'arrière plan
   SDL_Texture* m_look;

      // portion de l'arrière plan affichée
   SDL_Rect m_pos;

      // si l'arrière plan a un filtre (pour faire certains effets)
   bool m_has_filter;

      // apparence du filtre (si il n'y en a pas, vaut NULL)
   SDL_Texture* m_filter;
};

#endif
