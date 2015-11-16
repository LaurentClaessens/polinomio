#include "poly.h"

/*IMPLEMENTO METODI RELATIVI ALLA CLASSE ITERATOR SULL'OGGETTO POLYNOM*/

iterator operator++(int);
iterator& operator++(); //postfisso



bool polynomial::iterator::operator==(iterator it){
    return
}

bool polynomial::iterator::operator!=(iterator it){

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
