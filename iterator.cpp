#include "poly.h"

/*IMPLEMENTO METODI RELATIVI ALLA CLASSE ITERATOR SULL'OGGETTO POLYNOM********************************************************************/

Polynomial::iterator::iterator(smartp first) : index(first) {};

polynomila::iterator Polynomial::iterator::operator++(int)   //it++
{
    iterator aux=this;
    ++this;
    return aux;
}

iterator& Polynomial::iterator::operator++(){ //++it
    if (index) index = index->next; //non sicuro
    return *this;
}

bool Polynomial::iterator::operator==(iterator it){
    return first == it.index;  //non sicuro
}

bool Polynomial::iterator::operator!=(iterator it){
    return !(first == it.index);
}

iterator Polynomial::iterator::begin() const{
    iterator aux;
    aux.index = first;
    return aux;
}

iterator Polynomial::iterator::end() const{
    iterator aux;
    aux.index = 0;
    return aux;
}

Polynomial Polynomial::iterator::operator[](iterator it){
    return it.index->info; //non conosco l'interfaccia di monomio ???????
}
