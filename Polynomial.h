/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
#include "smartp.h"
#include "Monomial.h"
#include "Coefficient.h"
#include "Degree.h"

using std::ostream;
using std::endl;

/*IN QUESTO CONTESTO POLYNOM E' UN CONTENITORE DI MONOMI (NODI), UNA SEMPLICE LISTA CONCATENATA*/

class Polynomial{
    private:
        smartp first;               // 'first' points to the *lowest* degree monomial.
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
                void make_zero();           // set pMonomial to NULL;

        };

    public:
        class iterator {
            friend class Polynomial;
            private:
                smartp punt;
            public:
                iterator();
                iterator(smartp);       // No default value, see the 'sage bool idiom'
                iterator operator++(int);     // sp++
                iterator& operator++();         // ++sp
                bool operator==(const iterator it) const;
                bool operator!=(const iterator it);

            };
        /*COSTRUTTORI E DISTRUTTORI*/
        Polynomial(smartp); //costruttore standard e a 1 parametro
        Polynomial(const int x);
        Polynomial(const smartp&); //costruttore di copia
        Polynomial( int coef,int expo); 
        ~Polynomial(); //distruttore


        /*About iterator*/
        iterator begin() const;
        iterator end() const;
        Monomial& operator[](const iterator it) const; 

        /* Mathematical operations */
        int degree();   // return the degree of the polynomial
        Polynomial operator+(const Polynomial& P);

        bool operator==(const Polynomial&) const; //ridefinizione uguaglianza
        bool operator!=(const Polynomial&) const; //ridefinizione disuguaglianza
        bool operator<(const Polynomial&) const; 
        bool operator>(const Polynomial&) const; //ridefinizione minore


        smartp& operator=(const smartp&);

        //friend Polynomial operator*(const Polynomial&, const Polynomial&); 
        //friend Polynomial operator+(const Polynomial&, const Polynomial &);
        //friend ostream& operator<<(ostream&, const Polynomial&); 
};
