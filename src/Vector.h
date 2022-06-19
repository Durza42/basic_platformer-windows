/*
 * Vector.h
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


#ifndef VECTOR_H
 #define VECTOR_H

 #include <cmath>
 #include <ostream>
 #include <iostream>

/************************************
 * classe vector :                  *
 * ---------------                  *
 * un vecteur (ensemble de valeurs) *
 * à deux dimentions (x, y)         *
 ************************************/

class Vector {

  public:

   Vector ();
   Vector (const long double & value);
   Vector (const long double & x, const long double & y);
   ~Vector ();

   long double magnitude () const;
   Vector normalize ();

   friend long double magnitude (const Vector & v);
   friend Vector normalize (const Vector & v);

   long double get_x () const;
   long double get_y () const;

   void set_x (const long double & x);
   void set_y (const long double & y);

   friend Vector operator+ (const Vector & a, const Vector & b);
   friend Vector operator- (const Vector & a, const Vector & b);
   friend Vector operator+ (const Vector & a, const long double & b);
   friend Vector operator- (const Vector & a, const long double & b);

   friend long double operator* (const Vector & a, const Vector & b);

   friend std::ostream & operator<< (std::ostream & s, Vector const & v);

   Vector & operator+= (Vector const & v);
   Vector & operator-= (Vector const & v);
   Vector & operator*= (const long double & f);
   Vector & operator*= (const Vector & v);
   Vector & operator/= (const long double & d);
   Vector & operator/= (const Vector & v);

  private:

      // éléments X et Y
   long double m_x;
   long double m_y;
};

#endif
