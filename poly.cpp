
polynom::iterator& operator++()  // ++itr 
{
    if (mono_ptr) mono_ptr=mono_ptr->next;
    return *this;
}


polynom::iterator operator++(int)   //itr++
{
}

polynom::polynom(int c)
{

}<++>
