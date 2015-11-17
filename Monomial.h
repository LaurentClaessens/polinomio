// Copyright 2015 Andrey Petrov
#ifndef MONOMIO_H_
#define MONOMIO_H_

#include <iostream>
#include "coefficiente.h"
#include "grado.h"

using std::ostream;

class Monomial {
  Coefficiente c;
  Grado g;

 public:
  int riferimenti;
  smartp next;

  Monomial(int x = 0, int y = 0): c(x), g(y), riferimenti(0), next(0) { }
  Monomial(const Monomial&);
  Monomial& operator=(const Monomial&);
  Monomial operator*(const Monomial&) const;

  const Coefficiente& getCof() const;
  const Grado& getGra() const;
};

ostream& operator<<(ostream& os, const Monomial& m);



#endif  // MONOMIO_H_
