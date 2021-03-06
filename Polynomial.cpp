#include "Polynomial.h"
#include "Coefficient.h"
#include "Degree.h"

Polynomial::Polynomial(int coef,int expo=0)
{
    Polynomial::Monomial* m_ptr = new Polynomial::Monomial(coef,expo); 
    first=m_ptr;
}

Polynomial::Polynomial(Polynomial::smartp sp): first(sp){}

/* About iterator */


Polynomial::iterator::iterator(Polynomial::smartp first) : punt(first) {};
Polynomial::iterator::iterator()  
{
    punt.make_zero();
};

Polynomial::iterator& Polynomial::iterator::operator++()  // ++itr 
{
    if (punt.is_valid()) { punt=punt->next; }
    return *this;
}

Polynomial::iterator Polynomial::iterator::operator++(int)   //it++
{
    iterator aux=*this;
    ++(*this);
    return aux;
}

bool Polynomial::iterator::operator==(const iterator it) const
{
    return punt == it.punt;  //non sicuro
}

bool Polynomial::iterator::operator!=(iterator it){
    return !(punt == it.punt);
}

Polynomial::Monomial& Polynomial::operator[](const iterator it) const
{
    return *(it.punt);
}


Polynomial::iterator Polynomial::begin() const {return Polynomial::iterator(first);}

Polynomial::iterator Polynomial::end() const 
{
    Polynomial::iterator aux;
    aux.punt.make_zero();
    return aux;
}

Monomial Polynomial::highest_monomial() {return *first;}
Polynomial Polynomial::lower_polynomial() 
{
    if (first.is_valid()) 
    {
         if (first->getDegree() == 0)  { return 0 }
         if (first->next.is_valid) { return Polynomial(first->next); }
         return 0;
    }
    return 0;
}

/* Mathematical operations */

int Polynomial::degree(){ return first->getDegree(); }




/*DEFINIZIONE METODI E COSTRUTTORI DI SMARTP*/

Polynomial::smartp::smartp(Polynomial::Monomial *p) : pMonomial(p) {
    if (pMonomial) pMonomial->riferimenti++;
}

Polynomial::smartp::smartp(const Polynomial::smartp &s) : pMonomial(s.pMonomial){
    if (pMonomial) //se ho inizializzato uno smartp con uno smartp con pMonomial non nullo
        pMonomial->riferimenti++; //incremento i riferimenti che pMonomialano a quel pMonomial
}

Polynomial::smartp::~smartp(){
    if (pMonomial) { //se lo smartp pMonomiala a un pMonomial non nullo
        pMonomial->riferimenti--; //decrementa i riferimenti a quel pMonomial
        if (pMonomial->riferimenti==0) 
            delete pMonomial; 
    }
}

Polynomial::smartp& Polynomial::smartp::operator=(const Polynomial::smartp& s){
    if (this != &s) {
        Polynomial::Monomial *t = pMonomial;
        pMonomial = s.pMonomial;
        if (pMonomial) pMonomial->riferimenti++;
        if (t) {
            t->riferimenti--;
            if (t->riferimenti == 0) delete t;
        }
    }
    return *this;
}





bool Polynomial::smartp::is_valid(){ 
    if (pMonomial) return true;
    return false;
}
void Polynomial::smartp::make_zero() { pMonomial=0; }




Polynomial::Monomial& Polynomial::smartp::operator*() const{
    return *pMonomial; 
}

Polynomial::Monomial* Polynomial::smartp::operator->() const{
    return pMonomial;
}

bool Polynomial::smartp::operator==(const Polynomial::smartp& p) const{
    return pMonomial==p.pMonomial; 
}

bool Polynomial::smartp::operator!=(const Polynomial::smartp& p) const{
    return !(pMonomial==p.pMonomial);
}

// In the following, 'next' will use its default constructor.
Polynomial::Monomial::Monomial(int x, int y ): coefficient(x), degree(y), riferimenti(0) {  }
Polynomial::Monomial::Monomial(const Polynomial::Monomial& m) : coefficient(m.getCoefficient()),degree(m.getDegree()),riferimenti(0) { }
Polynomial::Monomial::Monomial(Coefficient x, Degree y ): coefficient(x), degree(y), riferimenti(0) {  }

Polynomial::Monomial& Polynomial::Monomial::operator=(const Polynomial::Monomial& m) {
  if (this != &m) {
    coefficient = m.coefficient;
    degree = m.degree;
  } return *this;
}

Polynomial::Monomial Polynomial::Monomial::operator*(const Polynomial::Monomial& m) const {
  return Polynomial::Monomial(coefficient * m.coefficient, degree + m.degree );
}

int Polynomial::Monomial::getCoefficient() const { return coefficient.getInt(); }
int Polynomial::Monomial::getDegree() const {  return degree.getInt(); }

//
//
//  'Monomial' is private in Polynomial. It seem difficult/unnecessary to have a << operator on 'Monomial'.
//
//ostream& operator<<(ostream& os, const Polynomial::Monomial& m) {
//  os << "Il Monomial e' caratterizzato da  \n";
//  os << "Coefficient c= "<< m.getCoefficient() << '\n';
//  os << "Degree degree= "<< m.getDegree() << '\n';
//  os << " Riferimenti r = " << m.riferimenti << '\n';
//  return os;
//}
