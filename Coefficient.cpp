// Copyright 2015, Andrey Petrov

#include "coefficiente.h"
#include  <string>


Coefficient::Coefficient(const Coefficient& C): c(C.c) {}

Coefficient& Coefficient::operator=(const Coefficient& C) {
  if (this != &C)
      c = C.c;
  return *this;
}

/*Opeartori relazionali interni*/
bool Coefficient::operator==(const Coefficient& C) const {
  return c == C.c;
}

bool Coefficient::operator!=(const Coefficient& C) const {
  return !(c==C.c);
}

bool Coefficient::operator<(const Coefficient& C) const {
  return c < C.c;
}

bool Coefficient::operator<=(const Coefficient& C ) const {
  return c < C.c || c == C.c;
}


bool Coefficient::operator>(const Coefficient& C) const {
  return !(c <= C.c);
}

bool Coefficient::operator>=(const Coefficient& C ) const {
  return !(c < C.c);
 }


/*Operatori operazionali interni*/
Coefficient  Coefficient::operator+(const Coefficient& C) const
{
   return Coefficient( this->c+C.c );
 }

Coefficient Coefficient::operator-(const Coefficient& C) const 
{
   return Coefficient( this->c-C.c );
 }

Coefficient Coefficient::operator*(const Coefficient& C ) const
{
   return Coefficient( this->c*C.c );
 }

Coefficient Coefficient::operator/(const Coefficient& C) const
{
   if (C.c==0) {  throw std::string("Division by zero !"); }
   if (this->c%C.c == 0){  throw std::string("only integer division !"); }
   return Coefficient(this->c/C.c);
 }


/*Getters and Setters*/
int Coefficient::getCoefficient() const {
   return c;
 }

 void Coefficient::setCoefficient(int x) {
   c = x;
 }




/*Operatori relazionali esterni*/
 bool operator== (const Coefficient& a, const Coefficient& b) {
   return  a.operator==(b);
 }

 bool operator!= (const Coefficient& a, const Coefficient& b) {
   return !( a.operator==(b));
 }

 bool operator<  (const Coefficient& a, const Coefficient& b) {
   return a.operator<(b);
 }

 bool operator<= (const Coefficient& a, const Coefficient& b) {
   return (a.operator<(b)) || (a.operator==(b));
 }

 bool operator>  (const Coefficient& a, const Coefficient& b) {
   return !(a.operator<=(b));
 }

 bool operator>= (const Coefficient& a, const Coefficient& b) {
   return !(a.operator<(b));
 }

ostream& operator<<(ostream& os, const Coefficient& C) {
  os << "il valore del Coefficient e'  "  << C.getCoefficient() << ' ';
  return os;
}
