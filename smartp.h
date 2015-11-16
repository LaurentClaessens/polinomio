#ifndef SMARTP
#define SMARTP
/*DICHIARAZIONE INCOMPLETA DI MONOMIO PER POTER USARE PUNTATORI E RIFERIMENTI A ESSO*/
class Monomio;

class smartp {
private:
    Monomio *punt;
public:
    /*COSTRUTTORI && DISTRUTTORE*/
    smartp(Monomio *p=0); //costruttore a un parametro
    smartp(const smartp&); //costruttore di copia
    ~smartp(); //distruttore
    /*METODI CHE FANNO SIDE EFFECT*/
    smartp& operator=(const smartp&); //assegnazione
    /*METODI CHE NON FANNO SIDE EFFECT*/
    Monomio& operator*() const; //dereferenziazione
    Monomio* operator->() const; //selezione di membro
    bool operator==(const smartp&) const; //uguaglianza
    bool operator!=(const smartp&) const; //disuguaglianza
};

#endif // SMARTP

