#ifndef EXUST
#define EXUST

#include  <stdexcept>
#include  <exception>

class ExUst:public std::exception
{
    std::string error_name;
public:
    ExUst();
    ExUst(std::string _name);
    std::string message();
};


ExUst::ExUst()
    :error_name ("no except")
{

}

ExUst::ExUst(std::string _name)
    :error_name(_name)
{

}

std::string ExUst::message()
{
    return error_name;
}
#endif // EXUST

