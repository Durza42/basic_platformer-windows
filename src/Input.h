#ifndef INPUT_H
 #define INPUT_H

 #include <SDL2/SDL.h>
 #include <cstddef>

/*************************************
 * classe Input :                    *
 * --------------                    *
 * Permet la gestion des évènements  *
 * (touches appuillées, souris, ...) *
 *************************************/

class Input {

  public:

   Input ();
   ~Input ();

   bool update ();

   bool request_close () const;
   const bool* get_keys_array () const;
   bool get_key (size_t const & key) const;

  private:

      // contient les évènements
   SDL_Event m_event;

      // pour chaque touche du clavier, true si elle este enfoncée, false sinon.
   bool m_keys [SDL_NUM_SCANCODES];

      // true si la fenêtre doit être fermée
   bool m_request_close;
};

#endif
