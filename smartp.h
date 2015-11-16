#ifndef SMARTP
#define SMARTP

class smartp {
private:
    monomio *punt;
public:
    /*COSTRUTTORI && DISTRUTTORE*/
    smartp(monomio *p=0); //costruttore a un parametro
    smartp(const smartp&); //costruttore di copia
    smartp(const monomio*); //costruttore di copia
    ~smartp(); //distruttore
    /*METODI CHE FANNO SIDE EFFECT*/
    smartp& operator=(const smartp&); //assegnazione
    /*METODI CHE NON FANNO SIDE EFFECT*/
    nonomio& operator*() const; //dereferenziazione
    monomio* operator->() const; //selezione di membro
    bool operator==(const smartp&) const; //uguaglianza
    bool operator!=(const smartp&) const; //disuguaglianza
};

#endif // SMARTP

