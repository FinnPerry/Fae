#include "logger.hpp"

#include <chrono>
#include <fstream>
#include <iostream>

namespace
{

char const * get_type_string(fae::log_type type)
{
    switch (type)
    {
        case fae::log_type::warning:
        {
            return "warning";
        }
        case fae::log_type::error:
        {
            return "error";
        }
        default:
        {
            return "message";
        }
    }
}

class logger
{
public:
    logger(char const * path):
        file_{path, std::ios::trunc | std::ios::out},
        start_{std::chrono::high_resolution_clock::now()}
    {
    }

    ~logger()
    {
        if (file_.is_open())
        {
            file_.flush();
            file_.close();
        }
    }

    void log(char const * str, fae::log_type type)
    {
        double timestamp{get_elapsed()};
        std::stringstream ss;
        ss << '[' << timestamp << ' ' << get_type_string(type) << ']';
        ss << ' ' << str << '\n';

        std::cout << ss.str();
        if (file_.is_open())
        {
            file_ << ss.str();
        }
    }

    double get_elapsed()
    {
        auto now{std::chrono::high_resolution_clock::now()};
        std::chrono::duration<double> dur{now - start_};
        return dur.count();
    }

private:
    std::ofstream file_;
    std::chrono::high_resolution_clock::time_point start_;
};

logger instance{"log.txt"};

}

namespace fae
{

void log(char const * str, log_type type)
{
    instance.log(str, type);
}

}
