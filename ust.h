#ifndef UST
#define UST

#include<string>


class Ust
{
    void*           ptr;
public:

    Ust             ();
    Ust             (void*);
    Ust             (const Ust&);
    ~Ust            ();
    template<typename Type>
    void            set_var(Type);
    template<typename Type>
    Type            get_var();

};


#endif // UST


Ust::Ust()
    :ptr(nullptr)
{

}

Ust::Ust(void *_ptr)
    :ptr(_ptr)
{

}

Ust::Ust(const Ust & u)
    :ptr(u.ptr)
{

}

Ust::~Ust()
{
    delete ptr;
}

template<typename Type>
void Ust::set_var(Type t)
{
    delete ptr;
    ptr = new Type(t);
}

template<typename Type>
Type Ust::get_var()
{
    return *static_cast<Type*>(ptr);
}


