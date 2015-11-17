#ifndef GRADO_H
#define GRADO_H


#include <iostream>
using std::ostream;
using std::cout;


class Degree {
  int g;

public:
  Degree(int x=0): g(x) {}
  Degree(const Degree& x);

  bool isPositive() const;
  bool isNegative() const;


  Degree& operator=(const Degree&);
  Degree operator+(const Degree&) const;

  int getInt() const;
  void setDegree(int x);

};

ostream& operator<<(ostream& os, const Degree& g);

#endif
