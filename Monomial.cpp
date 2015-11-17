// Copyright 2015 Andrey Petrov
#include "./Monomial.h"


Monomial(const Monomial& m) {
  if (this != &m) {
    c = m.getCof();
    g = m.getGra();
  }
}

Monomial& operator=(const Monomial& m) {
  if (this != &m) {
    c = m.c;
    g = m.g;
  } return *this;
}

Monomial operator*(const Monomial& m) const {
  return Monomial(c * m.c, g + m.g );
}

const Coefficiente& getCof() const { return c; }

const Grado& getGra() const {  return g; }

ostream& operator<<(ostream& os, const Monomial& m) {
  os << "Il Monomial e' caratterizzato da  \n";
  os << "Coefficiente c= "<< (m.getCof()).getCoefficiente() << '\n';
  os << "Grado g= "<< (g.getGra()).getGrado() << '\n';
  os << " Riferimenti r = " << riferimenti << '\n';
  return os;
}
