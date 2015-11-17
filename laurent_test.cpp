#include <iostream>

#include "Polynomial.h"



int main(int argc, char *argv[])
{
    Polynomial P = Polynomial(3,2);
    for (Polynomial::iterator itr=P.begin();itr!=P.end();itr++)
    {
        std::cout<<"Coefficient : "<<P[itr].getCoefficient()<<std::endl;
        std::cout<<"Degree : "<<P[itr].getDegree()<<std::endl;
    }
}
