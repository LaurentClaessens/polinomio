#ifndef SMARTP
#define SMARTP
class Monomio;
class smartp {
private:
    Monomio *punt;
public:
    /*COSTRUTTORI && DISTRUTTORE*/
    smartp(Monomio *p=0);
    smartp(const smartp&);
    ~smartp();
    /*METODI CHE FANNO SIDE EFFECT*/
    smartp& operator=(const smartp&);
    /*METODI CHE NON FANNO SIDE EFFECT*/
    Monomio& operator*() const;
    Monomio* operator->() const;
    bool operator==(const smartp&) const;
    bool operator!=(const smartp&) const;
};

#endif // SMARTP

