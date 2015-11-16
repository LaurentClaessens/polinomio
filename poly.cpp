#include "poly.h"
#include "monomio.h"

polynomial::polynomial(int coef,int expo)
{
    monomio* m_ptr = new monomio(coeff,expo); 
    first=m_ptr;
}



/* About iterator */


polynomial::iterator(smartp ptr) mono_ptr(ptr) { }; 

polynomial::iterator& operator++()  // ++itr 
{
    if (mono_ptr) mono_ptr=mono_ptr->next;
    return *this;
}

polynomial::iterator operator++(int)   //itr++
{
    iterator aux=this;
    ++this;
    return aux;
}

polynomial::polynomial(const int c)
{
    m=Monomio(c,0);
    first=smartp(m);
}

polynomial::iterator polynomial::begin() const {return polynomial::iterator(first);}
