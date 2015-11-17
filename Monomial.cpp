// Copyright 2015 Andrey Petrov
#include "Monomial.h"


// In the following, 'next' will use its default constructor.
Monomial::Monomial(int x, int y ): coefficient(x), degree(y), riferimenti(0) {  }
//Monomial::Monomial(Coefficent x, Degree y ): coefficient(x), degree(y), riferimenti(0) {  }


Monomial::Monomial(const Monomial& m) : coefficient(m.getCoefficient()),degree(m.getDegree()),riferimenti(0) { }

Monomial& Monomial::operator=(const Monomial& m) {
  if (this != &m) {
    coefficient = m.coefficient;
    degree = m.degree;
  } return *this;
}

Monomial Monomial::operator*(const Monomial& m) const {
  return Monomial(coefficient * m.coefficient, degree + m.degree );
}

Coefficient Monomial::getCoefficient() const { return coefficient; }
int Monomial::getDegree() const {  return degree.getInt(); }

ostream& operator<<(ostream& os, const Monomial& m) {
  os << "Il Monomial e' caratterizzato da  \n";
  os << "Coefficient c= "<< m.getCoefficient() << '\n';
  os << "Degree degree= "<< m.getDegree() << '\n';
  os << " Riferimenti r = " << m.riferimenti << '\n';
  return os;
}
