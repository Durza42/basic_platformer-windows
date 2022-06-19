/*
 * Vector.cpp
 * This file is part of 'basic platformer template'
 *
 * Copyright (C) 2022 - Durza42
 *
 * 'basic platformer template' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'basic platformer template' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'basic platformer template'. If not, see <http://www.gnu.org/licenses/>.
 */

 
#include "Vector.h"


/***************************
 * Vector :                *
 * --------                *
 * constructeur par défaut *
 ***************************/

Vector::Vector () :
        m_x { 0 },
        m_y { 0 } {
   
}


/******************************************
 * Vector :                               *
 * --------                               *
 * constructeur avec les coordonnées x, y *
 ******************************************/

Vector::Vector (const long double & x, const long double & y) :
        m_x { x },
        m_y { y } {
   
}


/**************************************
 * Vector :                           *
 * --------                           *
 * constructeur avec une seule valeur *
 **************************************/

Vector::Vector (const long double & value) :
        m_x { value },
        m_y { value } {
   
}


Vector::~Vector () {
   
}


/***************************************
 * get_x :                             *
 * -------                             *
 * retourne la coordonnée X du vecteur *
 ***************************************/

long double Vector::get_x () const {
   return m_x;
}


/***************************************
 * get_y :                             *
 * -------                             *
 * retourne la coordonnée Y du vecteur *
 ***************************************/

long double Vector::get_y () const {
   return m_y;
}


/**********************************
 * set_x :                        *
 * -------                        *
 * met la coordonnée X au X donné *
 **********************************/

void Vector::set_x (const long double & x) {
   m_x = x;
}


/**********************************
 * set_y :                        *
 * -------                        *
 * met la coordonnée Y au Y donné *
 **********************************/

void Vector::set_y (const long double & y) {
   m_y = y;
}


/********************************************
 * TODO: are_parallels & are_perpendiculars *
 ********************************************/


/************************************************
 * operator + :                                 *
 * ------------                                 *
 * permet d'additionner des vecteurs entre eux. *
 ************************************************/

Vector operator+ (const Vector & a, const Vector & b) {
   long double x = a.m_x + b.m_x;
   long double y = a.m_y + b.m_y;
   return { x, y };
}


/***********************************************
 * operator - :                                *
 * ------------                                *
 * permet de soustraire un vecteur à un autre. *
 ***********************************************/

Vector operator- (const Vector & a, const Vector & b) {
   long double x = a.m_x - b.m_x;
   long double y = a.m_y - b.m_y;
   return { x, y };
}


/**************************************************
 * operator + :                                   *
 * ------------                                   *
 * permet d'additionner un scalaire et un vecteur *
 **************************************************/

Vector operator+ (const Vector & a, const long double & b) {
   long double x = a.m_x + b;
   long double y = a.m_y + b;
   return { x, y };
}


/*************************************************
 * operator - :                                  *
 * ------------                                  *
 * permet de soustraire un scalaire à un vecteur *
 *************************************************/

Vector operator- (const Vector & a, const long double & b) {
   long double x = a.m_x - b;
   long double y = a.m_y - b;
   return { x, y };
}


/******************************************
 * magnitude :                            *
 * ------                                 *
 * donne la norme (longueur) d'un vecteur *
 ******************************************/

long double magnitude (const Vector & v) {
      // la fonction hypot renvoie la racine de la somme des carrés de deux nombres.
      // C'est donc bien ce qu'il nous faut : le théorème de pythagore.
   return hypot (v.m_x, v.m_y);
}


/****************************************
 * magnitude :                          *
 * ------                               *
 * donne la norme (longueur) du vecteur *
 ****************************************/

long double Vector::magnitude () const {
      // la fonction hypot renvoie la racine de la somme des carrés de deux nombres.
      // C'est donc bien ce qu'il nous faut : le théorème de pythagore.
   return hypot (m_x, m_y);
}


/******************************************
 * normalize :                            *
 * -----------                            *
 * donne le vecteur unitaire d'un vecteur *
 ******************************************/

Vector normalize (const Vector & v) {
      // On obtient un vecteur unitaire simplement
      // en divisant chaque composant d'un vecteur par la norme de celui-ci.
      // On obtient alors forcément un vecteur de norme 1.
   long double x = v.m_x / v.magnitude ();
   long double y = v.m_y / v.magnitude ();
   return { x, y };
}


/****************************************
 * normalize :                          *
 * -----------                          *
 * donne le vecteur unitaire du vecteur *
 ****************************************/

Vector Vector::normalize () {

      // attention : division par 0 !
   if (magnitude () == 0)
      return { 0 };

      // On obtient un vecteur unitaire simplement
      // en divisant chaque composant d'un vecteur par la norme de celui-ci.
      // On obtient alors forcément un vecteur de norme 1.
   long double x = m_x / magnitude ();
   long double y = m_y / magnitude ();
   return { x, y };
}


/*********************************************
 * operator * :                              *
 * ------------                              *
 * fait le produit scalaire de deux vecteurs *
 *********************************************/

long double operator* (const Vector & a, const Vector & b) {
   return (a.m_x * b.m_x + a.m_y * b.m_y);
}


/********************************************
 * operator << :                            *
 * -------------                            *
 * permet d'envoyer un vecteur dans un flux *
 * (par exemple pour l'afficher)            *
 ********************************************/

std::ostream & operator<< (std::ostream & s, Vector const & v) {
   return s << "(" << v.m_x << ", " << v.m_y << ")";
}


/****************************************************
 * operator += :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération += *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator+= (Vector const & v) {

      // on modifie les coordonnées X et Y
   m_x += v.m_x;
   m_y += v.m_y;

      // on renvoie l'objet courrant
   return *this;
}


/****************************************************
 * operator -= :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération += *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator-= (Vector const & v) {

      // on modifie les coordonnées X et Y
   m_x -= v.m_x;
   m_y -= v.m_y;

      // on renvoie l'objet courrant
   return *this;
}


/****************************************************
 * operator *= :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération *= *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator*= (const long double & f) {

      // on modifie les coordonnées X et Y
   m_x *= f;
   m_y *= f;

      // on renvoie l'objet courrant
   return *this;
}


/****************************************************
 * operator *= :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération *= *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator*= (const Vector & v) {

      // on modifie les coordonnées X et Y
   m_x *= v.m_x;
   m_y *= v.m_y;

      // on renvoie l'objet courrant
   return *this;
}


/****************************************************
 * operator /= :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération /= *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator/= (const long double & d) {

   if (d == 0) {
      std::cout << "ERROR: [Vector::operator/=]: cannot divide by 0." << std::endl;
      return *this;
   }

      // on modifie les coordonnées X et Y
   m_x /= d;
   m_y /= d;

      // on renvoie l'objet courrant
   return *this;
}


/****************************************************
 * operator /= :                                    *
 * -------------                                    *
 * pour pouvoir faire n'importe quelle opération /= *
 * comme sur une variable standard                  *
 ****************************************************/

Vector & Vector::operator/= (const Vector & v) {

      // on modifie les coordonnées X et Y
      // en faisant bien attention à ne pas diviser par 0
      // mais en laissant la possibilité de diviser par un vecteur ayant une coordonnée à 0
   if (v.m_x != 0)
      m_x /= v.m_x;
   if (v.m_y != 0)
      m_y /= v.m_y;

      // on renvoie l'objet courrant
   return *this;
}
