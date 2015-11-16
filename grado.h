#ifndef GRADO_H
#define GRADO_H
#include <iostream>
using std::ostream;
using std::cout;


class Grado {
  int g;

public:
  Grado(int x=0): g(x) {}
  Grado(const Grado& x);

  bool isPositive() const;
  bool isNegative() const;


  Grado& operator=(const Grado&);

  int getGrado() const;
  void setGrado(int x);

};

ostream& operator<<(ostream& os, const Grado& g);

#endif
