/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
<<<<<<< HEAD
#include <smartp.h>
=======
#include "smartp.h"

>>>>>>> 46b30ea3792083fbb1cdb7d470279e54562f28df
using std::ostream;
using std::endl;

/*IN QUESTO CONTESTO POLYNOM E' UN CONTENITORE DI MONOMI (NODI), UNA SEMPLICE LISTA CONCATENATA*/

class polynomial{
    private:
        smartp first;
    public:
<<<<<<< HEAD
    class iterator {
    private:
        smartp index;
    public:
        /*notare la sottile differenza tra increment prefisso e postfisso*/
        iterator(smartp first);
        iterator operator++(int); //prefisso
        iterator& operator++(); //postfisso
        bool operator==(iterator it);
        bool operator!=(iterator it);
        iterator begin() const;
        iterator end() const;
        polynom operator[](iterator it);


    };
    /*COSTRUTTORI E DISTRUTTORI*/
    polynom(smartp =0); //costruttore standard e a 1 parametro
    polynom(const smartp&); //costruttore di copia
    polynom(int coef,int expo);
    ~polynom(); //distruttore
    /*METODI COSTANTI (NO SIDE EFFECT)*/
    bool operator==(const polynom&) const; //ridefinizione uguaglianza
    bool operator!=(const polynom&) const; //ridefinizione disuguaglianza
    bool operator<(const polynom&) const; //ridefinizione maggiore (?non sicuro su segnatura)
    bool operator>(const polynom&) const; //ridefinizione minore
    /*METODI NON COSTANTI (POSSIBILE SIDE EFFECT)*/
    smartp& operator=(const smartp&);
    /*FUNZIONI ESTERNE FRIEND*/
    friend polynom operator*(const polynom&, const polynom&); //ridefinizione operatore di moltiplicazione tra polinomi (?serve)
    friend polynom operator+(const polynom&, const polynom &); //ridefinizione operatore di somma tra polinomi (?serve)
    friend ostream& operator<<(ostream&, const polynom&); //ridefinizione ostream
=======
        class iterator {
            private:
                smartp index;
            public:
                /*notare la sottile differenza tra increment prefisso e postfisso*/
                iterator operator++(int); //prefisso
                iterator& operator++(); //postfisso
                bool operator==(iterator it);
                bool operator!=(iterator it);
                iterator begin() const;
                iterator end() const;
                polynomial operator[](iterator it);
            };
        /*COSTRUTTORI E DISTRUTTORI*/
        polynomial(smartp =0); //costruttore standard e a 1 parametro
        polynomial(const int x);
        polynomial(const smartp&); //costruttore di copia
        polynomial( int coef,int expo); 
        ~polynomial(); //distruttore


        /* Mathematical operations */
        polynomial operator+(const polynomial& P);

        /*METODI COSTANTI (NO SIDE EFFECT)*/
        bool operator==(const polynomial&) const; //ridefinizione uguaglianza
        bool operator!=(const polynomial&) const; //ridefinizione disuguaglianza
        bool operator<(const polynomial&) const; //ridefinizione maggiore (?non sicuro su segnatura)
        bool operator>(const polynomial&) const; //ridefinizione minore
        /*METODI NON COSTANTI (POSSIBILE SIDE EFFECT)*/
        smartp& operator=(const smartp&);
        /*FUNZIONI ESTERNE FRIEND*/
        friend polynomial operator*(const polynomial&, const polynomial&); //ridefinizione operatore di moltiplicazione tra polinomi (?serve)
        friend polynomial operator+(const polynomial&, const polynomial &); //ridefinizione operatore di somma tra polinomi (?serve)
        friend ostream& operator<<(ostream&, const polynomial&); //ridefinizione ostream
>>>>>>> 46b30ea3792083fbb1cdb7d470279e54562f28df
};
