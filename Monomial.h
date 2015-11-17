// Copyright 2015 Andrey Petrov
#ifndef MONOMIO_H_
#define MONOMIO_H_

#include <iostream>
#include "coefficiente.h"
#include "Degree.h"
#include "smartp.h"

using std::ostream;

class Monomial {
  Coefficiente coefficient;   // was c
  Degree degree;   // was g

 public:
  int riferimenti;
  smartp next;

  Monomial(int, int );
  Monomial(const Monomial&);
  Monomial& operator=(const Monomial&);
  Monomial operator*(const Monomial&) const;

  const Coefficiente& getCof() const;
  const Degree& getGra() const;
};

ostream& operator<<(ostream& os, const Monomial& m);



#endif  // MONOMIO_H_
