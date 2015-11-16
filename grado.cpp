// Copyright 2015 Andrey Petrov
#include "./grado.h"


bool Grado::isPositive() const {
  return g > 0;
}

bool Grado::isNegative() const {
  return !(g > 0);
}


Grado::Grado(const Grado& x) {
  if (x.isNegative()) {
    cout << " Grado del polinommio negativo " << '\n';
    return;
  }
  g = x.g;
}

Grado& Grado::operator=(const Grado& x) {
  if (this != &x) {
    if (x.isPositive()) {
      g = x.g;
    }
    return *this;
  }
}

int Grado::getGrado() const { return g; }

void Grado::setGrado(int x) {
  if (x > 0) {   // grado positivo
    g = x;
  } else {
         cout << "Grado negativo! Situazione illegale! \n";
       }
}


ostream& operator<<(ostream& os, const Grado& x ) {
  os << "Il grado e'  " << x.getGrado() << '\n';
  return os;
}
