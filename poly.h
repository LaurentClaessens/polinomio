/*INCLUSIONE DELLA CLASSE DERIVATA IOSTREAM: IOS -> ISTREAM, OSTREAM -> IOSTREAM*/
#include <iostream>
using std::ostream;
using std::endl;

/*IN QUESTO CONTESTO POLYNOM E' UN CONTENITORE DI MONOMI (NODI), UNA SEMPLICE LISTA CONCATENATA*/

class polynom{
    private:
        smartp first;
    public:
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
        polynom operator[](iterator it);


    };
    /*COSTRUTTORI E DISTRUTTORI*/
    polynom(smartp =0); //costruttore standard e a 1 parametro
    polynom(const smartp&); //costruttore di copia
    polynom( int coef,int expo); 
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


};
