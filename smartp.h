#ifndef SMARTP
#define SMARTP

#include "Monomial.h"

class smartp {
private:
    Monomial *punt;
public:
    /*COSTRUTTORI && DISTRUTTORE*/
    smartp(Monomial* p=0); //costruttore a un parametro
    smartp(const smartp&); //costruttore di copia
    smartp(const Monomial*); //costruttore di copia
    ~smartp(); //distruttore
    /*METODI CHE FANNO SIDE EFFECT*/
    smartp& operator=(const smartp&); //assegnazione
    /*METODI CHE NON FANNO SIDE EFFECT*/
    Monomial& operator*() const; //dereferenziazione
    Monomial* operator->() const; //selezione di membro
    bool operator==(const smartp&) const; //uguaglianza
    bool operator!=(const smartp&) const; //disuguaglianza
};

#endif // SMARTP

