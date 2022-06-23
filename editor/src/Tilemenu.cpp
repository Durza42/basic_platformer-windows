#include "Tilemenu.h"

Tilemenu::Tilemenu() :
          m_pos { -1, -1, 150, 300 },
          m_fields { { 0, 0,  50, 20 },
                     { 0, 20, 50, 15 } }
{
   
}


Tilemenu::Tilemenu(SDL_Renderer* renderer) :
          m_look { uts::load_img(TILEMENU_PATH, renderer) },
          m_pos { -1, -1, 150, 300 },
          m_fields { { 0, 0,  50, 20 },
                     { 0, 20, 50, 15 } }
{
   
}

Tilemenu::~Tilemenu()
{
   // TODO
}


/**************************
 * load :                 *
 * ------                 *
 * initialise le tilemenu *
 **************************/

void Tilemenu::load(SDL_Renderer* renderer)
{
   m_look = uts::load_img(TILEMENU_PATH, renderer);
   m_pos = { -1, -1, 150, 300 };
   m_fields = { { 0, 0,  50, 20 },
                { 0, 20, 50, 15 } };
}



/***********************
 * print :             *
 * ------              *
 * affiche le tilemenu *
 ***********************/

void Tilemenu::print(SDL_Renderer* renderer)
{
   if (m_pos.x > 0 and m_pos.y > 0)
      SDL_RenderCopy(renderer, m_look, NULL, &m_pos);
}


/*********************************************
 * is_clicked :                              *
 * ------------                              *
 * retourne vrai si la souris clique le menu *
 * et fait les actions nécessaires           *
 *********************************************/

bool Tilemenu::is_clicked(SDL_Point mouse)
{
   return SDL_PointInRect(&mouse, &m_pos);
}


/*********************************************
 * is_clicked_right :                        *
 * ------------                              *
 * retourne vrai si la souris clique le menu *
 * et fait les actions nécessaires           *
 *********************************************/

bool Tilemenu::is_clicked_right(SDL_Point mouse)
{
   return SDL_PointInRect(&mouse, &m_pos);
}


/***********************************************
 * set_tile :                                  *
 * ----------                                  *
 * définit pour quelle tuile le menu s'affiche *
 * (et donc sa position)                       *
 ***********************************************/

void Tilemenu::set_tile(int x, int y)
{
   m_pos.x = x;
   m_pos.y = y;
}
