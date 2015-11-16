#include "poly.h"
polynom::polynom(int coef,int expo)
{
    m* = new monomio(coeff,expo); 
}


polynom::iterator(smartp ptr) mono_ptr(ptr) { }; 


polynom::iterator operator++(int)   //itr++
{
    iterator aux=this;
    ++this;
    return aux;
}


polynom::begin() const {return polynom::iterator(first);}


/*IMPLEMENTAZIONE FUNZIONI ESTERNE FRIEND*/
std::ostream& polynom::operator<<(std::ostream&, const polynom& p) {
    for(iteratore it = p.begin(); it != p.end(); ++it){
        os<<      //IMPLEM MONOMIO
    }
}
