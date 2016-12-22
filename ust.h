#ifndef UST
#define UST

#include "exust.h"
#include <typeinfo> //

class Ust
{
    void*           ptr;
    std::string     name_type;//
public:

    Ust             ();
    template<typename Type>
    Ust             (Type) throw(ExUst);
    ~Ust            ();
    std::string     get_name_type();//
    template<typename Type>
    void            set_var(Type)throw(ExUst) ;
    template<typename Type>
    Type            get_var() throw(ExUst);

};


#endif // UST


Ust::Ust()
    :ptr(nullptr),name_type("empyt")
{

}

template<typename Type>
Ust::Ust(Type t) throw(ExUst)
{
    try
    {
        ptr = new Type(t);
        name_type=typeid(t).name();
    }
    catch(std::bad_alloc &ba)
    {
        throw ExUst("bad alloc");
    }

}


Ust::~Ust()
{
    delete ptr;
}

std::string Ust::get_name_type()
{
    return name_type;
}

template<typename Type>
void Ust::set_var(Type t) throw(ExUst)
{
    try
    {
        delete ptr;
        ptr = new Type(t);
        name_type=typeid(t).name();

    }
    catch(std::bad_alloc &ba)
    {
        throw ExUst("bad alloc");
    }
}

template<typename Type>
Type Ust::get_var() throw(ExUst)
{
    if(name_type==typeid(Type).name())
    {
    return *static_cast<Type*>(ptr);
    }
    else
    {
        throw ExUst("Wrong type");
    }
}




