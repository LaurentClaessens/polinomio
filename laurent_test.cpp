#include <iostream>

#include "Polynomial.h"



int main(int argc, char *argv[])
{
    Polynomial P = Polynomial(3,2);
    for (Polynomial::iterator itr=P.begin();itr!=P.end();itr++)
    {
        std::cout<<P[itr]<<std::endl;
    }
}
