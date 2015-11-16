// Copyright 2015 Andrey Petrov
#ifndef MONOMIO_H_
#define MONOMIO_H_

#include <iostream>
using std::ostream;

#include "./coefficiente.h"
#include "./grado.h"

class smartp;

class Monomio {
  Coefficiente c;
  Grado g;

 public:
  int riferimenti;
  smartp* next;

  Monomio(int x = 0, int y = 0): c(x), g(y), riferimenti(0), next(0) { }
  Monomio(const Monomio&);
  Monomio& operator=(const Monomio&);
  Monomio operator*(const Monomio&) const;

  const Coefficiente& getCof() const;
  const Grado& getGra() const;
};

ostream& operator<<(ostream& os, const Monomio& m);



#endif  // MONOMIO_H_
