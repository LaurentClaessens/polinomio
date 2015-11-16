#include "smartp.h"

/*DEFINIZIONE METODI E COSTRUTTORI DI SMARTP***********************************************************************************************/

/*COSTRUTTORE*/
smartp::smartp(Monomio *p) : punt(p) {
    if (punt) //se ho assegnato a punt un Monomio/nodo valido:
        punt->riferimenti++; //incremento riferimenti a nodo
    //altrimenti ho inizializzato uno smartp nullo
}

/*COSTRUTTORE DI COPIA*/
smartp::smartp(const smartp &s) : punt(s.punt){
    if (punt) //se ho inizializzato uno smartp con uno smartp con punt non nullo
        punt->riferimenti++; //incremento i riferimenti che puntano a quel punt
}

/*DISTRUTTORE*/
smartp::~smartp(){
    if (punt) { //se lo smartp punta a un punt non nullo
        punt->riferimenti--; //decrementa i riferimenti a quel punt
        if (punt->riferimenti==0) //se i riferimenti sono 0 non punta nessuno al punt
            delete punt; //cancellalo
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
    return *punt; //*smartp = *punt ora;
}

/*OPERATORE DI SELEZIONE DI MEMBRO*/
Monomio* smartp::operator->() const{
    return punt; //smartp->membro = punt->membro ora;
}

/*OPERATORE DI UGUAGLIANZA*/
bool smartp::operator==(const smartp& p) const{
    return punt==p.punt; //true se i due punt confrontati hanno lo stesso indirizzo in memoria;
}

/*OPERATORE DI DISUGUAGLIANZA*/
bool smartp::operator!=(const smartp& p) const{
    return punt != p.punt; //true se i due punt confrontati hanno diversi indirizzi in memoria;
}
