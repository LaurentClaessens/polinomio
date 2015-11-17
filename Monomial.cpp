// Copyright 2015 Andrey Petrov
#include "./Monomial.h"


// In the following, 'next' will use its default constructor.
Monomial::Monomial(const int x, const int y ): coefficient(x), degree(y), riferimenti(0) {  }

Monomial::Monomial(const Monomial& m) {
  if (this != &m) {
    coefficient = m.getCof();
    degree = m.getGra();
  }
}

Monomial& Monomial::operator=(const Monomial& m) {
  if (this != &m) {
    coefficient = m.coefficient;
    degree = m.degree;
  } return *this;
}

Monomial Monomial::operator*(const Monomial& m) const {
  return Monomial(coefficient * m.coefficient, degree + m.degree );
}

const Coefficiente& Monomial::getCoefficient() const { return coefficient; }

const Degree& MOnomial::getDegree() const {  return degree; }

ostream& operator<<(ostream& os, const Monomial& m) {
  os << "Il Monomial e' caratterizzato da  \n";
  os << "Coefficiente c= "<< (m.getCof()).getCoefficiente() << '\n';
  os << "Degree degree= "<< (degree.getGra()).getDegree() << '\n';
  os << " Riferimenti r = " << riferimenti << '\n';
  return os;
}
