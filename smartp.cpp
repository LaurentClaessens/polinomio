#include "smartp.h"

/*DEFINIZIONE METORI E COSTRUTTORI DI SMARTP***********************************************************************************************/

/*COSTRUTTORE*/
smartp::smartp(nodo *p) : punt(p) {
    if (punt)
        punt->riferimenti++;
}

/*COSTRUTTORE DI COPIA*/
smartp::smartp(const smartp &s) : punt(s.punt){
    if (punt)
        punt->riferimenti++;
}

/*DISTRUTTORE*/
smartp::~smartp(){
    if (punt) {
        punt->riferimenti--;
        if (punt->riferimenti==0)
            delete punt;
    }
}

/*ASSEGNAZIONE*/
smartp& smartp::operator=(const smartp& s){
    if (this != &s) {
        Monomio *t = punt;
        punt = s.punt;
        if (punt) punt->riferimenti++;
        if (t) {
            t->riferimenti--;
            if (t->riferimenti == 0) delete t;
        }
    }
    return *this;
}

/*OPERATORE DI DEREFERENZIAZIONE*/
Monomio& smartp::operator*() const{
    return *punt;
}

/*OPERATORE DI SELEZIONE DI MEMBRO*/
Monomio* smartp::operator->() const{
    return punt;
}

/*OPERATORE DI UGUAGLIANZA*/
bool smartp::operator==(const smartp& p) const{
    return punt==p.punt;
}

/*OPERATORE DI DISUGUAGLIANZA*/
bool smartp::operator!=(const smartp& p) const{
    return punt != p.punt;
}
