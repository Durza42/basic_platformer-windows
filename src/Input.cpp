#include "Input.h"


/***************************
 * Input :                 *
 * -------                 *
 * constructeur par défaut *
 ***************************/

Input::Input () : 
       m_keys { false },
       m_request_close { false } {
   
}


/**************************
 * ~Input :               *
 * --------               *
 * destructeur par défaut *
 **************************/

Input::~Input () {
   
}


/************************************
 * update :                         *
 * --------                         *
 * met à jour le tableau de touches *
 ************************************/

bool Input::update () {

      // si il y a de nouveaux évènements
   if (SDL_PollEvent (&m_event)) {
         // tant qu'il reste des évènements à traiter
      do {
         switch (m_event.type) {
            case SDL_QUIT: // si l'évènement correspond à une fermeture de la fenêtre
               m_request_close = true;
           break;
            case SDL_KEYDOWN: // si c'est un appuie de touche
               m_keys [m_event.key.keysym.scancode] = true;
           break;
            case SDL_KEYUP: // si c'est un relachement de touche
               m_keys [m_event.key.keysym.scancode] = false;
           break;
         }
      } while (SDL_PollEvent (&m_event));
      return true;
   }
   else {
      return false;
   }
}


/************************************************
 * request_close :                              *
 * ---------------                              *
 * retourne true si la fenêtre doit être fermée *
 ************************************************/

bool Input::request_close () const {
   return m_request_close;
}


/****************************************************
 * get_keys_array :                                 *
 * ----------------                                 *
 * renvoie le tableau des touches appuillées ou non *
 ****************************************************/

const bool* Input::get_keys_array () const {
   return m_keys;
}


/***************************************************
 * get_key :                                       *
 * ----------------                                *
 * renvoie true si la touche spécifiée est pressée *
 ***************************************************/

bool Input::get_key (size_t const & key) const {
   return m_keys [key];
}
