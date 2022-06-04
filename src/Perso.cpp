#include "Perso.h"


/*******************************************************************
 * perso :                                                         *
 * -------                                                         *
 * constructeur par défaut de de la classe Perso                   *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si aucun argument n'est spécifié.                               *
 *******************************************************************/

Perso::Perso () :
       m_look { NULL },
       m_pos { DEFAULT_PERSO_POS_X, DEFAULT_PERSO_POS_Y, PERSO_WIDTH, PERSO_HEIGHT },
       m_dir { 1, 0 },
       m_moove { 0, 0 },
       m_can_jump { true } {

}


/*******************************************************************
 * perso :                                                         *
 * -------                                                         *
 * constructeur de la classe Perso                                 *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si le chemin de son image est spécifiée en argument             *
 *******************************************************************/

Perso::Perso (const char* path, SDL_Renderer* renderer) :
       m_look { uts::load_img (path, renderer) },
       m_pos { DEFAULT_PERSO_POS_X, DEFAULT_PERSO_POS_Y, PERSO_WIDTH, PERSO_HEIGHT },
       m_dir { 1, 0 },
       m_moove { 0, 0 },
       m_can_jump { true } {

}


/**********************************************************************
 * ~Perso :                                                           *
 * ------                                                             *
 * destructeur de la classe Perso                                     *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Perso::~Perso () {
// TODO
//   SDL_DestroyTexture (m_look);
}


/***********************************
 * print :                         *
 * -------                         *
 * affiche le personnage à l'écran *
 ***********************************/

void Perso::print (SDL_Renderer* renderer) {
   SDL_Rect center { DEFAULT_WINDOW_WIDTH / 2 - 25, DEFAULT_WINDOW_HEIGHT / 2 - 25, PERSO_WIDTH, PERSO_HEIGHT };
   SDL_RenderCopy (renderer, m_look, NULL, &center);
}


/********************************
 * go_right :                   *
 * ----------                   *
 * fait aller le perso à droite *
 ********************************/

void Perso::go_right () {
   m_moove += (Vector){ MOOVE_ADD, 0 };
}


/********************************
 * go_left :                    *
 * ----------                   *
 * fait aller le perso à gauche *
 ********************************/

void Perso::go_left () {
   m_moove += (Vector){ -MOOVE_ADD, 0 };
}


/************************
 * jump :               *
 * ----------           *
 * fait sauter le perso *
 ************************/

void Perso::jump () {

      // si il peut bien sauter
   if (m_can_jump)
      m_moove += (Vector){ 0, JUMP_ADD };
}


/**********************************************
 * moove_x :                                  *
 * ---------                                  *
 * fait bouger le perso sur l'axe des absices *
 * (en prenant en compte les blocs et autres) *
 **********************************************/

void Perso::moove_x (const Grid & grid) {

   if (m_moove.get_x() == 0)
      return;

      // il va vers la droite
   if (m_moove.get_x() > 0) {

      SDL_Rect col_zone { m_pos.x, m_pos.y, m_pos.w + int(round(m_moove.get_x())), m_pos.h };

      if (!grid.has_col(col_zone))
         m_pos.x += int(round(m_moove.get_x()));
      else {
         m_moove.set_x(0);
         if (m_pos.x % BLOC_GRID_SIZE > 1)
            m_pos.x += BLOC_GRID_SIZE - (m_pos.x % BLOC_GRID_SIZE) - 1;
      }
   }
   else {

      SDL_Rect col_zone { m_pos.x - (0 - int(round(m_moove.get_x()))), m_pos.y, m_pos.w + (0 - int(round(m_moove.get_x()))), m_pos.h };

      if (!grid.has_col(col_zone))
         m_pos.x += int(round(m_moove.get_x()));
      else {
         m_moove.set_x(0);
         if (m_pos.x % BLOC_GRID_SIZE > 1)
            m_pos.x -= m_pos.x % BLOC_GRID_SIZE - 1;
      }
   }
}


/************************************************
 * moove_y :                                    *
 * ---------                                    *
 * fait bouger le perso sur l'axe des ordonnées *
 * (en prenant en compte les blocs et autres)   *
 ************************************************/

void Perso::moove_y (const Grid & grid) {

   if (m_moove.get_y() > 0) {
      SDL_Rect col_zone { m_pos.x, m_pos.y, m_pos.w, m_pos.h + int(round(m_moove.get_y())) };
      if (!grid.has_col(col_zone))
         m_pos.y += int(round(m_moove.get_y()));
      else {
         m_moove.set_y(0);
         if (m_pos.y % BLOC_GRID_SIZE > 1)
            m_pos.y += BLOC_GRID_SIZE - (m_pos.y % BLOC_GRID_SIZE) - 1;
         m_can_jump = true;
      }
   }
   else if (m_moove.get_y() < 0) {
      SDL_Rect col_zone { m_pos.x, m_pos.y - (0 - int(round(m_moove.get_y()))), m_pos.w, m_pos.h + (0 - int(round(m_moove.get_y()))) };
      if (!grid.has_col(col_zone))
         m_pos.y += int(round(m_moove.get_y()));
      else
         m_moove.set_y(0);
   }
}

/**********************************************
 * loose_speed :                              *
 * -------------                              *
 * immobilise fluidement le perso quand plus  *
 * aucune touche de mouvement n'est appuillée *
 **********************************************/

void Perso::loose_speed () {

      // on divise sa vitesse horizontale par deux
   m_moove /= (Vector){ 1.5, 0 };

      // si il ne bouge presque plus en X
   if (m_moove.get_x () < 1 && m_moove.get_x () > -1)
      m_moove.set_x (0); // on le rend immobile
}


/*************************************************
 * fall :                                        *
 * -------------                                 *
 * fait tomber le personnage (simule la gravité) *
 *************************************************/

void Perso::fall (const Grid & grid) {

   if (m_moove.get_y() == 0) {
      if (grid.is_wall(m_pos.x / BLOC_GRID_SIZE, (m_pos.y + m_pos.h) / BLOC_GRID_SIZE + 1)
       || grid.is_wall((m_pos.x + m_pos.w) / BLOC_GRID_SIZE, (m_pos.y + m_pos.h) / BLOC_GRID_SIZE + 1)) {
         m_can_jump = true;
         if (m_pos.y % BLOC_GRID_SIZE > 1)
            m_pos.y += BLOC_GRID_SIZE - (m_pos.y % BLOC_GRID_SIZE) - 1;
         return;
      }
      else {
         m_can_jump = false;
         SDL_Rect hitbox { m_pos.x, m_pos.y, m_pos.w, m_pos.h + GRAVITY_ADD }; // -1 pour compenser celui mis à l'initialisation
         if (!grid.has_col(hitbox)) {
            m_moove += (Vector){ 0, GRAVITY_ADD };
            return;
         }
         else {
            m_moove.set_y(0);
            return;
         }
      }
   }
   else {
      m_moove += (Vector){ 0, GRAVITY_ADD };
      m_can_jump = false;
   }
}


/************************************
 * moove :                          *
 * -------                          *
 * fait bouger le perso en fonction *
 * de son vecteur mouvement         *
 ************************************/

bool Perso::moove (const Grid & grid) {

      // on fait tomber le perso
   fall (grid);

      // si le perso est toujours immobile
   if (m_moove.get_x () == 0 && m_moove.get_y () == 0)
      return false; // il ne se déplace pas

      // on fait bouger le perso sur l'axe X
   moove_x (grid);

      // on fait bouger le perso sur l'axe Y
   moove_y (grid);

      // on baisse sa vitesse
   loose_speed ();

   return true;
}


/*************************************************************************
 * get_pos :                                                             *
 * ---------                                                             *
 * retourne le décalage de la grille en fonction de la position du perso *
 *************************************************************************/

SDL_Point Perso::get_offset () const {
   return (SDL_Point){ m_pos.x - (DEFAULT_WINDOW_WIDTH / 2 - 25), m_pos.y - (DEFAULT_WINDOW_HEIGHT / 2 - 25) };
}
