/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
#include "Coefficient.h"
#include "Degree.h"

using std::ostream;
using std::endl;


class Polynomial{
    private:

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

                Monomial& operator*() const;
                Monomial* operator->() const;
                bool operator==(const smartp&) const;
                bool operator!=(const smartp&) const; 

                // we do not implement the safe bool idiom.  
                // http://www.artima.com/cppsource/safebool.html
                bool is_valid();
                void make_zero();           // set pMonomial to NULL;
        };

        class Monomial {
            Coefficient coefficient;   // was c
            Degree degree;   // was g

            public:
                int riferimenti;
                smartp next;

                Monomial(int, int );
                Monomial(Coefficient, Degree);
                Monomial(const Monomial&);
                Monomial& operator=(const Monomial&);
                Monomial operator*(const Monomial&) const;

                int getCoefficient() const;
                int getDegree() const;
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

        // No destructor for Polynomial because the default destructor deletes 
        // the 'first' field which is a smart pointer which will delete the next.
        //~Polynomial();


        /*About iterator*/
        iterator begin() const;
        iterator end() const;
        Monomial& operator[](const iterator it) const; 

        /* Mathematical operations */
        int degree();   // return the degree of the polynomial
        Polynomial operator+(const Polynomial& P);

        bool operator==(const Polynomial&) const;
        bool operator!=(const Polynomial&) const; 
        bool operator<(const Polynomial&) const; 
        bool operator>(const Polynomial&) const;

        smartp& operator=(const smartp&);

    private :
        smartp first;       // 'first' is the highest degree monomial.
};
