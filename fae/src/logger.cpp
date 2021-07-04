#include "logger.hpp"

#include <iostream>

namespace fae
{

logger::logger(std::string const & path):
    start_{std::chrono::high_resolution_clock::now()},
    file_{path, std::ios::out | std::ios::trunc}
{
}

logger::~logger()
{
    if (file_.is_open())
    {
        file_.flush();
        file_.close();
    }
}

double logger::get_elapsed()
{
    auto now{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> dur{now - start_};
    return dur.count();
}

void logger::log(char const * str)
{
    double timestamp{get_elapsed()};
    std::cout << '[' << timestamp << "] " << str << '\n';
    if (file_.is_open())
    {
        file_ << '[' << timestamp << "] " << str << '\n';
    }
}

}
