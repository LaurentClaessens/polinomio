#include <iostream>

#include "coefficiente.h"

int main(int argc, char *argv[])
{
    Coefficient c1=Coefficient(4);
    Coefficient c2=Coefficient(5);

    Coefficient d=c1+c2;
    std::cout<<c1<<std::endl;   
    std::cout<<c2<<std::endl;   
    std::cout<<d<<std::endl;   
}
