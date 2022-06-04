#ifndef UTILITIES_H
 #define UTILITIES_H

 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>
 #include <cstring>


/*********************************************************
 * namespace uts :                                       *
 * ---------------                                       *
 * regroupe un ensemble de fonctions utiles au programme *
 *********************************************************/

namespace uts {
   SDL_Texture* load_img (const char* path_tmp, SDL_Renderer *renderer);
}

#endif
