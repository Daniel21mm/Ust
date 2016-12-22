#include <iostream>
#include <typeinfo>


#include "ust.h"

struct Int
{
    int i;
};

int main()
{
    int i(8);
    Ust u(i);


    std::cout<<u.get_var<int>() << std::endl;

    float f(2.3);
    u.set_var(f);
    std::cout<< f << std::endl;
    std::cout << u.get_var<float>() << std::endl;


    Int m;
    m.i=3;
    u.set_var(m);
    std::cout<< m.i << std::endl;
    std::cout<< u.get_var<Int>().i << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
