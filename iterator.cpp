#include "poly.h"

/*IMPLEMENTO METODI RELATIVI ALLA CLASSE ITERATOR SULL'OGGETTO POLYNOM********************************************************************/

polynom::iterator::iterator(smartp first) : index(first) {};

polynom::iterator polynom::iterator::operator++(int)   //it++
{
    iterator aux=this;
    ++this;
    return aux;
}

iterator& polynom::iterator::operator++(){ //++it
    if (index) index = index->next; //non sicuro
    return *this;
}

bool polynomial::iterator::operator==(iterator it){
    return first == it.index;  //non sicuro
}

bool polynomial::iterator::operator!=(iterator it){
    return !(first == it.index);
}

iterator polynomial::iterator::begin() const{
    iterator aux;
    aux.index = first;
    return aux;
}

iterator polynomial::iterator::end() const{
    iterator aux;
    aux.index = 0;
    return aux;
}

polynomial polynomial::iterator::operator[](iterator it){
    return it.index->info; //non conosco l'interfaccia di Monomio ????????????????????????????????????????????
}
