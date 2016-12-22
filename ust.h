#ifndef UST
#define UST

#include "exust.h"

class Ust
{
    void*           ptr;
public:

    Ust             ();
    template<typename Type>
    Ust             (Type) ;
    Ust             (const Ust&) throw(ExUst) ;
    ~Ust            ();
    template<typename Type>
    void            set_var(Type)throw(ExUst) ;
    template<typename Type>
    Type            get_var();

};


#endif // UST


Ust::Ust()
    :ptr(nullptr)
{

}

template<typename Type>
Ust::Ust(Type t) throw(ExUst)
{
    try
    {
        ptr = new Type(t);
    }
    catch(std::bad_alloc &ba)
    {
        throw ExUst("bad alloc");
    }

}

Ust::Ust(const Ust & u)
    :ptr(u.ptr)
{}

Ust::~Ust()
{
    delete ptr;
}

template<typename Type>
void Ust::set_var(Type t) throw(ExUst)
{
    try
    {
        delete ptr;
        ptr = new Type(t);
    }
    catch(std::bad_alloc &ba)
    {
        throw ExUst("bad alloc");
    }
}

template<typename Type>
Type Ust::get_var()
{
    return *static_cast<Type*>(ptr);
}




