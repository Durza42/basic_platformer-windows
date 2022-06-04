#include "utilities.h"

/*******************************************
 * load_img :                              *
 * ----------                              *
 * renvoie une SDL_Texture affichable à la *
 * fenêtre à partir du chemin de l'image   *
 *******************************************/

SDL_Texture* uts::load_img (const char* path_tmp, SDL_Renderer *renderer) {

   size_t size = strlen(path_tmp);
   char path[size];
   for (size_t i = 0 ; i < size ; ++i)
      path[i] = path_tmp[i];
   path[size - 3] = 'b';
   path[size - 2] = 'm';
   path[size - 1] = 'p';
   path[size] = '\0';

      // on charge l'image dans une SDL_Surface
   SDL_Surface* tmp { NULL };
//   tmp = IMG_Load (path);
   tmp = SDL_LoadBMP (path);

      // si il y a eu une erreur (par ex. que l'image n'existe pas)
   if (!tmp) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[uts::load_img] Erreur when loading %s : %s", path, IMG_GetError()); // on affiche un message d'erreur
      return NULL; // on retourne une erreur
   }

      // on rend tous les pixels de la SDL_Surface squi sont blancs transparants
   SDL_SetColorKey (tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

      // on crée une SDL_Texture à partir de la SDL_Surface
   SDL_Texture *tex { NULL };
   tex = SDL_CreateTextureFromSurface (renderer, tmp);

      // on libère la SDL_Surface, maintenant inutilisée
   SDL_FreeSurface (tmp);

      // si il y a eu une erreur
   if (tex == NULL) {
      SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "[uts::load_img] Erreur when creating SDL_Texture for %s : %s", path, SDL_GetError()); // on affiche un message
      return NULL; // on retourne une erreur
   }

      // si tout s'est bien passé
   return tex; // on retourne la SDL_Texture finale
}
