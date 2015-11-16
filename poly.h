class polynom
{
    private :
        smartp   first;

    public :
    class iterator
    {
        private : 
            smartp  mono_ptr;
        public 
            polynom::iterator& operator++(int);
    }
}
