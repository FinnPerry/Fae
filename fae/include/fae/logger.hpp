#ifndef FAE_LOGGER_GUARD
#define FAE_LOGGER_GUARD

#include <string>
#include <sstream>

namespace fae
{

enum class log_type
{
    message,
    warning,
    error
};

void log(char const * str, log_type type = log_type::message);

inline void log(std::string const & str, log_type type = log_type::message)
{ log(str.c_str(), type); }

inline void log(std::stringstream const & str, log_type type = log_type::message)
{ log(str.str(), type); }

}

#endif
