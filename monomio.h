#ifndef  __MONOMIO_H__
#define  __MONOMIO_H__

#include "coefficiente.h"
#include "grado.h"

class Monomio
{
    private:
        Coefficiente coefficient;
        Grado grado;
    public:
        Monomio(const int,const int);
};

#endif     // __MONOMIO_H__
