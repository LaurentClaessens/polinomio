#include "Polynomial.h"
#include "Monomial.h"

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

int Polynomial::degree(){ return first->degree; }
Polynomial Polynomial::operator+(const Polynomial& P)
    // return the sum of 'this' and P
{
    // TODO
}
