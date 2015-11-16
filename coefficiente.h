#ifndef COEFFICIENTE_H
#define COEFFICIENTE_H

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;


class Coefficiente
{
  int c;

public:
  explicit Coefficiente(int x=0): c(x) {};
  Coefficiente(const Coefficiente&);
  Coefficiente& operator=(const Coefficiente&);


  bool operator== (const Coefficiente&) const;
  bool operator!= (const Coefficiente&) const;
  bool operator<  (const Coefficiente&) const;
  bool operator<= (const Coefficiente&) const;
  bool operator>  (const Coefficiente&) const;
  bool operator>= (const Coefficiente&) const;


  Coefficiente& operator+  (const Coefficiente&);
  Coefficiente& operator-  (const Coefficiente&);
  Coefficiente& operator*  (const Coefficiente&);
  Coefficiente& operator/  (const Coefficiente&);

   int getCoefficiente() const;
   void setCoefficiente(int );
};

/* Esternamente alla classe*/

  //ostream& operator<<(ostream&, const Coefficiente&);

  bool operator== (const Coefficiente& , const Coefficiente& );
  bool operator!= (const Coefficiente& , const Coefficiente& );

  bool operator<  (const Coefficiente& , const Coefficiente& );
  bool operator>  (const Coefficiente& , const Coefficiente& );
  bool operator<= (const Coefficiente& , const Coefficiente& );
  bool operator>= (const Coefficiente& , const Coefficiente& );

  const Coefficiente& operator+ (const Coefficiente& , const Coefficiente& );
  const Coefficiente& operator- (const Coefficiente& , const Coefficiente& );
  const Coefficiente& operator/ (const Coefficiente& , const Coefficiente& );
  const Coefficiente& operator* (const Coefficiente& , const Coefficiente& );


  ostream& operator<<(ostream& , const Coefficiente& );

#endif // COEFFICIENTE_H
