
/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
using std::ostream;
using std::endl;

class polynom{
    private:
        smartp first;
    public:
    class iterator {
        private:
            smartp mono_ptr;
        public:
            polynom::iterator& operator++(int);
    };
    /*COSTRUTTORI E DISTRUTTORI*/
    polynom(smartp f=0); //costruttore standard e a 1 parametro
    polynom(const smartp &); //costruttore di copia
    ~polynom(); //distruttore
    /*METODI COSTANTI (NO SIDE EFFECT)*/
    polynom& operator*() const; //

    bool operator==(const polynom&) const;
    bool operator!=(const polynom&) const;
    /*METODI NON COSTANTI (POSSIBILE SIDE EFFECT)*/
    smartp& operator=(const smartp&);
    /*FUNZIONI ESTERNE FRIEND*/
    friend  polynom& operator*(const polynom&, const polynom&);
    friend polynom operator+(const polynom&, const polynom &);
    friend ostream& operator<<(ostream&, const polynom&);


};



