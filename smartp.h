#ifndef SMARTP
#define SMARTP

class Monomial;

class smartp {
private:
    Monomial* pMonomial;
public:

    smartp(Monomial* p=0);
    smartp(const smartp&); 
    smartp(const Monomial*); 

    ~smartp(); 

    smartp& operator=(const smartp&); //assegnazione

    Monomial& operator*() const; //dereferenziazione
    Monomial* operator->() const; //selezione di membro
    bool operator==(const smartp&) const; //uguaglianza
    bool operator!=(const smartp&) const; //disuguaglianza

    //we do not implement the safe bool idiom.  http://www.artima.com/cppsource/safebool.html
    bool is_valid();

};

#endif // SMARTP

