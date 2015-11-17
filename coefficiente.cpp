// Copyright 2015, Andrey Petrov

#include "./coefficiente.h"



Coefficiente::Coefficiente(const Coefficiente& C): c(C.c) {}

Coefficiente& Coefficiente::operator=(const Coefficiente& C) {
  if (this != &C)
      c = C.c;
  return *this;
}

/*Opeartori relazionali interni*/
bool Coefficiente::operator==(const Coefficiente& C) const {
  return c == C.c;
}

bool Coefficiente::operator!=(const Coefficiente& C) const {
  return !(c==C.c);
}

bool Coefficiente::operator<(const Coefficiente& C) const {
  return c < C.c;
}

bool Coefficiente::operator<=(const Coefficiente& C ) const {
  return c < C.c || c == C.c;
}


bool Coefficiente::operator>(const Coefficiente& C) const {
  return !(c <= C.c);
}

bool Coefficiente::operator>=(const Coefficiente& C ) const {
  return !(c < C.c);
 }


/*Operatori operazionali interni*/
Coefficiente  Coefficiente::operator+(const Coefficiente& C) {
   return Coefficiente( this->c+C.c );
 }

Coefficiente Coefficiente::operator-(const Coefficiente& C) {
  c = c - C.c;
  return *this;
 }

Coefficiente Coefficiente::operator*(const Coefficiente& C ) {
  c = c * C.c;
  return *this;
 }

Coefficiente Coefficiente::operator/(const Coefficiente& C) {
    if (C.c != 0 && c%C.c == 0)
      c = c / C.c;
    else 
      cout << "Non va bene! \n";
    return *this;
 }


/*Getters and Setters*/
int Coefficiente::getCoefficiente() const {
   return c;
 }

 void Coefficiente::setCoefficiente(int x) {
   c = x;
 }




/*Operatori relazionali esterni*/
 bool operator== (const Coefficiente& a, const Coefficiente& b) {
   return  a.operator==(b);
 }

 bool operator!= (const Coefficiente& a, const Coefficiente& b) {
   return !( a.operator==(b));
 }

 bool operator<  (const Coefficiente& a, const Coefficiente& b) {
   return a.operator<(b);
 }

 bool operator<= (const Coefficiente& a, const Coefficiente& b) {
   return (a.operator<(b)) || (a.operator==(b));
 }

 bool operator>  (const Coefficiente& a, const Coefficiente& b) {
   return !(a.operator<=(b));
 }

 bool operator>= (const Coefficiente& a, const Coefficiente& b) {
   return !(a.operator<(b));
 }

ostream& operator<<(ostream& os, const Coefficiente& C) {
  os << "il valore del Coefficiente e'  "  << C.getCoefficiente() << ' ';
  return os;
}
