#ifndef FOREGROUND_H
 #define FOREGROUND_H

 #include <SDL2/SDL.h>
 #include <iostream>
 #include "utilities.h"
 #include "Context.h"


/**************************
 * classe Foreground :    *
 * -------------------    *
 * Décors du premier plan *
 * (devant le personnage) *
 **************************/

class Foreground {

  public:

   Foreground ();
   Foreground (const char* path, SDL_Renderer* renderer);
   Foreground (std::string path, SDL_Renderer* renderer);
   ~Foreground ();

   void print (SDL_Renderer* renderer);

  private:

      // apparence de l'avant plan
   SDL_Texture* m_look;

      // portion de l'avant plan affichée
   SDL_Rect m_pos;
};

#endif
