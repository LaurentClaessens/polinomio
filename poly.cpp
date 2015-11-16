polynom::iterator(smartp ptr) mono_ptr(ptr) { }; 

polynom::iterator& operator++()  // ++itr 
{
    if (mono_ptr) mono_ptr=mono_ptr->next;
    return *this;
}


polynom::iterator operator++(int)   //itr++
{
    iterator aux=this;
    ++this;
    return aux;
}

polynom::polynom(int c)
{
    m=Monomio(c,0);
    first=smartp(m);
}

polynom::begin() {return polynom::iterator(first);}
