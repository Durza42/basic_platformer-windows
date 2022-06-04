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
