#ifndef FAE_LOGGER_GUARD
#define FAE_LOGGER_GUARD

#include <string>
#include <sstream>

namespace fae
{

void log(char const * str);

inline void log(std::string const & str) { log(str.c_str()); }

inline void log(std::stringstream const & str) { log(str.str()); }

}

#endif
