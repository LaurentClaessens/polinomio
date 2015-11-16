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
                iterator(smartp);
                iterator& operator++(int);
        }
        iterator begin();
        iterator end();
}

#endif      // __POLY_H__
