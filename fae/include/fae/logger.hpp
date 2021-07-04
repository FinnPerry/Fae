#ifndef FAE_LOGGER_GUARD
#define FAE_LOGGER_GUARD

#include <chrono>
#include <fstream>
#include <string>

namespace fae
{

class logger
{
public:
    logger(std::string const & path);

    ~logger();

    void log(char const * str);

    static logger & instance();

private:
    double get_elapsed();

    std::chrono::high_resolution_clock::time_point start_;
    std::ofstream file_;
};

}

#endif
