#include "poly.h"
<<<<<<< HEAD

/*IMPLEMENTO METODI RELATIVI ALLA CLASSE ITERATOR SULL'OGGETTO POLYNOM*/
=======
#include "monomio.h"

polynomial::polynomial(int coef,int expo)
{
    monomio* m_ptr = new monomio(coef,expo); 
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
polynomial::iterator polynomial::end() const 
{
    polynomial::iterator aux;
    aux.index=0;
    return aux;
}
>>>>>>> 46b30ea3792083fbb1cdb7d470279e54562f28df

/* Mathematical operations */

polynomial polynomial::operator+(const polynomial& P)
    // return the sum of 'this' and P
{
    // TODO
}
