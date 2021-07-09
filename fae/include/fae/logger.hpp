#ifndef FAE_LOGGER_GUARD
#define FAE_LOGGER_GUARD

#include <sstream>

namespace fae
{

enum class log_type
{
    message,
    warning,
    error
};

template<class t_type>
void log_variadic(std::stringstream & ss, t_type arg)
{
    ss << arg;
}

template<class t_type, class ... t_types>
void log_variadic(std::stringstream & ss, t_type arg, t_types ... args)
{
    log_variadic(ss, arg);
    ss << ' ';
    log_variadic(ss, args...);
}

void finish_log(log_type t_type, std::stringstream & ss);

// call this function for logging with a log type
template<class t_type, class ... t_types>
void log(log_type type, t_type arg, t_types ... args)
{
    std::stringstream ss;
    log_variadic(ss, arg, args...);
    finish_log(type, ss);
}

// call this function for logging without a log type
template<class t_type, class ... t_types>
void log(t_type arg, t_types ... args)
{
    log(log_type::message, arg, args...);
}

}

#endif
