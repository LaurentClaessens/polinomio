#ifndef COEFFICIENTE_H
#define COEFFICIENTE_H

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;


class Coefficient
{
  int c;

public:
  explicit Coefficient(int x=0): c(x) {};
  Coefficient(const Coefficient&);
  Coefficient& operator=(const Coefficient&);


  bool operator== (const Coefficient&) const;
  bool operator!= (const Coefficient&) const;
  bool operator<  (const Coefficient&) const;
  bool operator<= (const Coefficient&) const;
  bool operator>  (const Coefficient&) const;
  bool operator>= (const Coefficient&) const;


  Coefficient operator+  (const Coefficient&) const;
  Coefficient operator-  (const Coefficient&) const;
  Coefficient operator*  (const Coefficient&) const;
  Coefficient operator/  (const Coefficient&) const;

   int getCoefficient() const;
   void setCoefficient(int );
};

/* Esternamente alla classe*/

  //ostream& operator<<(ostream&, const Coefficient&);

  bool operator== (const Coefficient& , const Coefficient& );
  bool operator!= (const Coefficient& , const Coefficient& );

  ostream& operator<<(ostream& , const Coefficient& );

#endif // COEFFICIENTE_H
