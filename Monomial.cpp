// Copyright 2015 Andrey Petrov
#include "./Monomial.h"


// In the following, 'next' will use its default constructor.
Monomial::Monomial(const int x, const int y ): c(x), g(y), riferimenti(0) {  }

Monomial::Monomial(const Monomial& m) {
  if (this != &m) {
    c = m.getCof();
    g = m.getGra();
  }
}

Monomial& Monomial::operator=(const Monomial& m) {
  if (this != &m) {
    c = m.c;
    g = m.g;
  } return *this;
}

Monomial Monomial::operator*(const Monomial& m) const {
  return Monomial(c * m.c, g + m.g );
}

const Coefficiente& Monomial::getCoefficient() const { return c; }

const Degree& MOnomial::getDegree() const {  return g; }

ostream& operator<<(ostream& os, const Monomial& m) {
  os << "Il Monomial e' caratterizzato da  \n";
  os << "Coefficiente c= "<< (m.getCof()).getCoefficiente() << '\n';
  os << "Degree g= "<< (g.getGra()).getDegree() << '\n';
  os << " Riferimenti r = " << riferimenti << '\n';
  return os;
}
