/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
#include "smartp.h"

using std::ostream;
using std::endl;

/*IN QUESTO CONTESTO POLYNOM E' UN CONTENITORE DI MONOMI (NODI), UNA SEMPLICE LISTA CONCATENATA*/

class Polynomial{
    private:
        smartp first;               // 'first' points to the *highest* degree monomial.
    public:
        class iterator {
            private:
                smartp punt;
            public:
                /*notare la sottile differenza tra increment prefisso e postfisso*/
                iterator(smartp first);
                iterator operator++(int); //prefisso
                iterator& operator++(); //postfisso
                bool operator==(iterator it);
                bool operator!=(iterator it);
                iterator begin() const;
                iterator end() const;
                Polynomial operator[](iterator it);
            };
        /*COSTRUTTORI E DISTRUTTORI*/
        Polynomial(smartp); //costruttore standard e a 1 parametro
        Polynomial(const int x);
        Polynomial(const smartp&); //costruttore di copia
        Polynomial( int coef,int expo); 
        ~Polynomial(); //distruttore


        /* Mathematical operations */
        int degree();   // return the degree of the polynomial
        Polynomial operator+(const Polynomial& P);

        /*METODI COSTANTI (NO SIDE EFFECT)*/
        bool operator==(const Polynomial&) const; //ridefinizione uguaglianza
        bool operator!=(const Polynomial&) const; //ridefinizione disuguaglianza
        bool operator<(const Polynomial&) const; //ridefinizione maggiore (?non sicuro su segnatura)
        bool operator>(const Polynomial&) const; //ridefinizione minore
        /*METODI NON COSTANTI (POSSIBILE SIDE EFFECT)*/
        smartp& operator=(const smartp&);
        /*FUNZIONI ESTERNE FRIEND*/
        friend Polynomial operator*(const Polynomial&, const Polynomial&); //ridefinizione operatore di moltiplicazione tra polinomi (?serve)
        friend Polynomial operator+(const Polynomial&, const Polynomial &); //ridefinizione operatore di somma tra polinomi (?serve)
        friend ostream& operator<<(ostream&, const Polynomial&); //ridefinizione ostream
};
