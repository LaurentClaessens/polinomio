#include "Polynomial.h"
#include "Monomial.h"
#include "Coefficient.h"
#include "Degree.h"

Polynomial::Polynomial(int coef,int expo=0)
{
    Monomial* m_ptr = new Monomial(coef,expo); 
    first=m_ptr;
}

Polynomial::Polynomial(smartp sp): first(sp){}

/* About iterator */


Polynomial::iterator::iterator(smartp first) : punt(first) {};
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

Monomial& Polynomial::operator[](const iterator it) const
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


/* Mathematical operations */

int Polynomial::degree(){ return first->getDegree(); }
Polynomial Polynomial::operator+(const Polynomial& P)
    // return the sum of 'this' and P
{
    // TODO
}

/*DEFINIZIONE METODI E COSTRUTTORI DI SMARTP***********************************************************************************************/

/*COSTRUTTORE*/
Polynimial::smartp::smartp(Monomial *p) : pMonomial(p) {
    if (pMonomial) pMonomial->riferimenti++;
}

/*COSTRUTTORE DI COPIA*/
Polynomial::smartp::smartp(const smartp &s) : pMonomial(s.pMonomial){
    if (pMonomial) //se ho inizializzato uno smartp con uno smartp con pMonomial non nullo
        pMonomial->riferimenti++; //incremento i riferimenti che pMonomialano a quel pMonomial
}

/*DISTRUTTORE*/
Polynomial::smartp::~smartp(){
    if (pMonomial) { //se lo smartp pMonomiala a un pMonomial non nullo
        pMonomial->riferimenti--; //decrementa i riferimenti a quel pMonomial
        if (pMonomial->riferimenti==0) //se i riferimenti sono 0 non pMonomiala nessuno al pMonomial
            delete pMonomial; //cancellalo
    }
}

/*ASSEGNAZIONE*/
Polynomial::smartp& smartp::operator=(const smartp& s){
    if (this != &s) {
        Monomial *t = pMonomial;
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

void smartp::make_zero() { pMonomial=0; }

Monomial& smartp::operator*() const{
    return *pMonomial; //*smartp = *pMonomial ora;
}

Monomial* smartp::operator->() const{
    return pMonomial; //smartp->membro = pMonomial->membro ora;
}

bool smartp::operator==(const smartp& p) const{
    return pMonomial==p.pMonomial; 
}

bool smartp::operator!=(const smartp& p) const{
    return !(pMonomial==p.pMonomial);
}

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
