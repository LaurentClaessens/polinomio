#include "poly.h"
#include "monomio.h"

polynom::polynom(int coef,int expo)
{
    monomio* m_ptr = new monomio(coeff,expo); 
    first=m_ptr;
}


polynom::iterator(smartp ptr) mono_ptr(ptr) { }; 

polynom::iterator& operator++()  // ++itr 
{
    if (mono_ptr) mono_ptr=mono_ptr->next;
    return *this;
}

polynom::iterator operator++(int)   //itr++
{
    iterator aux=this;
    ++this;
    return aux;
}

polynom::polynom(const int c)
{
    m=Monomio(c,0);
    first=smartp(m);
}

polynom::iterator polynom::begin() const {return polynom::iterator(first);}

