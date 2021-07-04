#include "logger.hpp"

#include <iostream>

namespace fae
{

logger::logger(std::string const & path):
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

logger & logger::operator <<(char const * right)
{
    std::cout << right;
    if (file_.is_open())
    {
        file_ << right;
    }
    return *this;
}

logger & logger::operator <<(std::string const & right)
{
    return *this << right.c_str();
}

logger & logger::operator <<(char right)
{
    std::cout << right;
    if (file_.is_open())
    {
        file_ << right;
    }
    return *this;
}

logger & logger::operator <<(int right)
{
    return *this << std::to_string(right).c_str();
}

logger & logger::operator <<(float right)
{
    return *this << std::to_string(right).c_str();
}

}
