// Copyright 2015 Andrey Petrov
#ifndef MONOMIO_H_
#define MONOMIO_H_

#include <iostream>

using std::ostream;

class Monomial {
  Coefficient coefficient;   // was c
  Degree degree;   // was g

 public:
  int riferimenti;
  smartp next;

  Monomial(int, int );
  Monomial(Coefficient, Degree );
  Monomial(const Monomial&);
  Monomial& operator=(const Monomial&);
  Monomial operator*(const Monomial&) const;

  Coefficient getCoefficient() const;
  int getDegree() const;
};

ostream& operator<<(ostream& os, const Monomial& m);



#endif  // MONOMIO_H_
