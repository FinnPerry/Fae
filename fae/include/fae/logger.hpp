#ifndef FAE_LOGGER_GUARD
#define FAE_LOGGER_GUARD

#include <iostream>
#include <sstream>

namespace fae
{

template<class type>
void log_variadic(std::stringstream & ss, type arg)
{
    ss << arg;
}

template<class type, class ... types>
void log_variadic(std::stringstream & ss, type arg, types ... args)
{
    log_variadic(ss, arg);
    ss << ' ';
    log_variadic(ss, args...);
}

template<class type, class ... types>
void log(type arg, types ... args)
{
    std::stringstream ss;
    log_variadic(ss, arg, args...);
    ss << '\n';
    std::cout << ss.str();
}

}

#endif
