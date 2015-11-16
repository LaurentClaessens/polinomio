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

<<<<<<< HEAD
bool polynom::iterator::operator==(iterator it){
    return first == it.index;  //non sicuro
}

bool polynom::iterator::operator!=(iterator it){
    return !(first == it.index);
}


polynom::begin() const {
    return polynom::iterator(first);
=======
bool polynomial::iterator::operator==(iterator it){
    return
}

bool polynomial::iterator::operator!=(iterator it){

}


iterator polynomial::iterator::begin() const{
    iterator aux;
    aux.index = first;
    return aux;
>>>>>>> 46b30ea3792083fbb1cdb7d470279e54562f28df
}

iterator polynomial::iterator::end() const{
    iterator aux;
    aux.index = 0;
    return aux;
}

polynomial polynomial::iterator::operator[](iterator it){
    return it.index->info; //non conosco l'interfaccia di Monomio ????????????????????????????????????????????
}
