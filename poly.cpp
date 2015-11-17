#include "poly.h"
#include "Monomial.h"

Polynomial::Polynomial(int coef,int expo)
{
    Monomial* m_ptr = new Monomial(coef,expo); 
    first=m_ptr;
}

Polynomial::Polynomial(smartp sp): first(sp){}

/* About iterator */




Polynomial::iterator::iterator(smartp first) : punt(first) {};

Polynomial::iterator& Polynomial::iterator::operator++()  // ++itr 
{
    if (punt) punt=punt->next;
    return *this;
}

Polynomial::iterator Polynomial::iterator::operator++(int)   //it++
{
    iterator aux=this;
    ++this;
    return aux;
}

bool Polynomial::iterator::operator==(iterator it){
    return first == it.punt;  //non sicuro
}

bool Polynomial::iterator::operator!=(iterator it){
    return !(first == it.punt);
}

iterator Polynomial::iterator::begin() const{
    iterator aux;
    aux.punt = first;
    return aux;
}

iterator Polynomial::iterator::end() const{
    iterator aux;
    aux.punt = 0;
    return aux;
}

Polynomial Polynomial::iterator::operator[](iterator it){
    return it.punt->info; //non conosco l'interfaccia di Monomial ???????
}


Polynomial::iterator(smartp first): punt(first) { }; 

Polynomial::Polynomial(const int c)
{
    m=Monomial(c,0);
    first=smartp(m);
}

Polynomial::iterator Polynomial::begin() const {return Polynomial::iterator(first);}
Polynomial::iterator Polynomial::end() const 
{
    Polynomial::iterator aux;
    aux.punt=0;
    return aux;
}

/* Mathematical operations */

int Polynomial::degree(){ return first->grado; }
Polynomial Polynomial::operator+(const Polynomial& P)
    // return the sum of 'this' and P
{
    // TODO
}
