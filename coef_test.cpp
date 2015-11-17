#include <iostream>

#include "coefficiente.h"

int main(int argc, char *argv[])
{
    Coefficiente c1=Coefficiente(4);
    Coefficiente c2=Coefficiente(5);

    Coefficiente d=c1+c2;
    std::cout<<c1<<std::endl;   
    std::cout<<c2<<std::endl;   
    std::cout<<d<<std::endl;   
}
