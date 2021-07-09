#include "logger.hpp"

#include <chrono>
#include <fstream>
#include <iostream>

namespace
{

#if false
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

char const * get_color_code(fae::log_type type)
{
    switch (type)
    {
        case fae::log_type::warning:
        {
            return "\033[33m";
        }
        case fae::log_type::error:
        {
            return "\033[31m";
        }
        default:
        {
            return "\033[0m";
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

    void log(char const * str)
    {
        double time{get_elapsed()};

        static auto normal{get_color_code(fae::log_type::message)};
        auto color{get_color_code(type)};
        std::cout << normal << '[' << time << "] " << color << str << '\n';

        if (file_.is_open())
        {
            auto typestr{get_type_string(type)};
            file_ << '[' << time << ' ' << typestr << "] " << str << '\n';
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
#endif

}

namespace fae
{

}
