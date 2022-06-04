#ifndef CONTEXT_H
 #define CONTEXT_H

 #include <SDL2/SDL.h>

 #define REFRESH_RATE (1000. / 30.) // 30 fps

 #define DEFAULT_WINDOW_HEIGHT 800
 #define DEFAULT_WINDOW_WIDTH  1200

/*****************************************************
 * classe Context :                                  *
 * ----------------                                  *
 * s'occupe du contexte du jeu comme la fenêtre      *
 * ou des ressources comme les polices de caractère. *
 *****************************************************/

class Context {

  public:

   Context ();
   ~Context ();

   SDL_Renderer* get_renderer () const;

  private:

      // la fenêtre
   SDL_Window* m_window;
      // C'est en quelque sorte la feuille que l'on colle à la fenêtre.
      // C'est ici que l'on va "dessiner" le jeu.
   SDL_Renderer* m_renderer;
};

#endif
