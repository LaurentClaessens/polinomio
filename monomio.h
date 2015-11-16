#ifndef  __MONOMIO_H__
#define  __MONOMIO_H__

#include "coefficiente.h"
#include "grado.h"

class monomio
{
    private:
        Coefficiente coefficient;
        Grado grado;
    public:
        monomio(const int,const int);
};

#endif     // __MONOMIO_H__
