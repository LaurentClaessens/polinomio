#include "poly.h"
#include "monomio.h"

Polynomial::Polynomial(int coef,int expo)
{
    monomio* m_ptr = new monomio(coef,expo); 
    first=m_ptr;
}

Polynomial::Polynomial(smartp sp): first(sp){}

/* About iterator */


Polynomial::iterator(smartp ptr) mono_ptr(ptr) { }; 

Polynomial::iterator& operator++()  // ++itr 
{
    if (mono_ptr) mono_ptr=mono_ptr->next;
    return *this;
}

Polynomial::iterator operator++(int)   //itr++
{
    iterator aux=this;
    ++this;
    return aux;
}

Polynomial::Polynomial(const int c)
{
    m=monomio(c,0);
    first=smartp(m);
}

Polynomial::iterator Polynomial::begin() const {return Polynomial::iterator(first);}
Polynomial::iterator Polynomial::end() const 
{
    Polynomial::iterator aux;
    aux.index=0;
    return aux;
}

/* Mathematical operations */

Polynomial Polynomial::operator+(const Polynomial& P)
    // return the sum of 'this' and P
{
    // TODO
}
