
polynom::iterator& operator++(int)
{
 if (mono_ptr) mono_ptr=mono_ptr.next;
}
