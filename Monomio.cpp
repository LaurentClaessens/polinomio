// Copyright 2015 Andrey Petrov
#include "./Monomio.h"


Monomio(const Monomio& m) {
  if (this != &m) {
    c = m.getCof();
    g = m.getGra();
  }
}

Monomio& operator=(const Monomio& m) {
  if (this != &m) {
    c = m.c;
    g = m.g;
  } return *this;
}

Monomio operator*(const Monomio& m) const {
  return Monomio(c * m.c, g + m.g );
}

const Coefficiente& getCof() const { return c; }

const Grado& getGra() const {  return g; }

ostream& operator<<(ostream& os, const Monomio& m) {
  os << "Il Monomio e' caratterizzato da  \n";
  os << "Coefficiente c= "<< (m.getCof()).getCoefficiente() << '\n';
  os << "Grado g= "<< (g.getGra()).getGrado() << '\n';
  os << " Riferimenti r = " << riferimenti << '\n';
  return os;
}
