#include "Game.h"


/*******************************************************************
 * Game :                                                          *
 * ------                                                          *
 * constructeur de la classe Game                                  *
 * C'est cette fonction qui sera appelée à la création de l'objet. *
 *******************************************************************/

Game::Game () :
      m_perso { "../data/imgs/perso.png", m_context.get_renderer () },
      m_forest { m_context.get_renderer (), 1 } {
}


/**********************************************************************
 * ~Game :                                                            *
 * ------                                                             *
 * destructeur de la classe Game                                      *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Game::~Game () {

}


/********************************************************************
 * main_loop :                                                      *
 * -----------                                                      *
 * C'est la boucle principale du programme.                         *
 * C'est à dire cette fonction tourne en boucle, à qu'à chaque tour *
 * elle fait toutes les actions nécessaires, comme réagir aux       *
 * évènements ou afficher le décor et les personnages à l'écran.    *
 ********************************************************************/

void Game::main_loop () {

      // boucle infinie (elle se répète tant qu'on est dans le jeu)
   while (true) {

         // on s'occupe de tous les nouveaux évènements
      do_events ();

         // on fait bouger le perso si besoin
      m_perso.moove (m_forest.get_grid());

         // on rafraichit l'écran
      refresh ();

         // on attends un peu, pour limiter les ressources demandées par le jeu
      SDL_Delay (REFRESH_RATE);

   }
}


/********************************************************
 * do_events :                                          *
 * -----------                                          *
 * fait les actions correspondantes aux évènements      *
 * par exemple : touche haut pressée -> monter le perso *
 ********************************************************/

void Game::do_events () {

   m_input.update ();

      // la fenêtre doit être fermée
   if (m_input.request_close () || m_input.get_key (SDL_SCANCODE_ESCAPE))
      exit (EXIT_SUCCESS);

      // touche D pressée
   if (m_input.get_key (SDL_SCANCODE_D))
      m_perso.go_right (); // le perso va à droite

      // touche Q pressée
   if (m_input.get_key (SDL_SCANCODE_Q))
      m_perso.go_left (); // le perso va à gauche

      // touche ESPACE pressée
   if (m_input.get_key (SDL_SCANCODE_SPACE))
      m_perso.jump (); // le perso saute
}


/*******************************************************************
 * refresh :                                                       *
 * ---------                                                       *
 * met l'écran à jour en affichant les personnages, le décor, etc. *
 *******************************************************************/

void Game::refresh () {

      // on efface le renderer
   SDL_RenderClear (m_context.get_renderer ());

      // on dessine l'arrière plan du niveau
   m_forest.get_background ().print (m_context.get_renderer ());

      // si il y en a un, on dessine le filtre du niveau
   if (m_forest.get_background ().get_has_filter ())
      m_forest.get_background ().print_filter (m_context.get_renderer ());

      // on dessine le personnage sur le renderer
   m_perso.print (m_context.get_renderer ());

      // on affiche chaque bloc du niveau
   m_forest.get_grid ().print (m_context.get_renderer (), -m_perso.get_offset().x, -m_perso.get_offset().y);

      // on dessine l'avant-plan
   m_forest.get_foreground ().print (m_context.get_renderer ());

      // on met la fenêtre à jour (on copie le renderer, sur lequel on vient de dessiner, dessus)
   SDL_RenderPresent (m_context.get_renderer ());
}


/********************************************
 * reception_menu :                         *
 * ----------------                         *
 * menu d'arrivée dans le jeu               *
 * (TODO: avant plan = menu,                *
 * arrière plan = passages du jeu défilent) *
 ********************************************/

void Game::reception_menu () {
   return;
}
