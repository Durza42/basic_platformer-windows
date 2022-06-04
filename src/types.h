#ifndef TYPES_H
 #define TYPES_H


/*************************************************************************
 * énumération Lvl_type :                                                *
 * ----------------------                                                *
 * énumère les types de niveau possible.                                 *
 * Une variable de ce type peux prendre une des possibilités ci-dessous. *
 *************************************************************************/

typedef enum {
   LVL_LINEAR = 1, // pour un niveau à une dimention (ex. la forêt)
   LVL_2D     = 2 // pour un niveau en 2D (ex. le village)
} Lvl_type;

#endif
