#include "poly.h"


int main(int argc, char *argv[])
{
    polynom P = polynom(3,2);
    for (Polynomial::iterator itr=P.begin();itr!=P.end();itr++)
    {
        cout<<itr;
    }
}