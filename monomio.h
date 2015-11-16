#ifndef  __MONOMIO_H__
#define  __MONOMIO_H__

#include "coefficiente.h"

class monomio
{
    private:
        Coefficiente coefficient;
        Exponent exponent;
    public:
        monomio(int,int);
};

#endif     // __MONOMIO_H__
