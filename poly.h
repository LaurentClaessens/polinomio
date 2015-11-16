#ifndef  __POLY_H__
#define  __POLY_H__


class polynom
{
    private :
        smartp   first;

    public :
        polynom(int);
        class iterator
        {
            private : 
                smartp  mono_ptr;
            public 
                iterator& operator++(int);
        }
        iterator

}

#endif      // __POLY_H__
