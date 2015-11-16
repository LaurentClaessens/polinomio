#include "poly.h"

/*IMPLEMENTO METODI RELATIVI ALLA CLASSE ITERATOR SULL'OGGETTO POLYNOM*/

iterator operator++(int);
iterator& operator++(); //postfisso



bool polynom::iterator::operator==(iterator it){
    return
}

bool polynom::iterator::operator!=(iterator it){

}


iterator polynom::iterator::begin() const{
    iterator aux;
    aux.index = first;
    return aux;
}

iterator polynom::iterator::end() const{
    iterator aux;
    aux.index = 0;
    return aux;
}

polynom polynom::iterator::operator[](iterator it){
    return it.index->info; //non conosco l'interfaccia di Monomio ????????????????????????????????????????????
}
