// Copyright 2015 Andrey Petrov
#include "./grado.h"


bool Degree::isPositive() const {
  return g > 0;
}

bool Degree::isNegative() const {
  return !(g > 0);
}


Degree::Degree(const Degree& x) {
  if (x.isNegative()) {
    cout << " Degree del polinommio negativo " << '\n';
    return;
  }
  g = x.g;
}

Degree& Degree::operator=(const Degree& x) {
  if (this != &x) {
    if (x.isPositive()) {
      g = x.g;
    }
    return *this;
  }
}

int Degree::getDegree() const { return g; }

void Degree::setDegree(int x) {
  if (x > 0) {   // grado positivo
    g = x;
  } else {
         cout << "Degree negativo! Situazione illegale! \n";
       }
}


ostream& operator<<(ostream& os, const Degree& x ) {
  os << "Il grado e'  " << x.getDegree() << '\n';
  return os;
}
