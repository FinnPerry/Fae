#include "logger.hpp"

#include <chrono>
#include <fstream>
#include <iostream>

namespace
{

#if false

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

namespace
{

char const * ansi_color_code(fae::log_type type)
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

char const * log_type_str(fae::log_type type)
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

class log_data
{
public:
    log_data():
        file{"fae-log.txt", std::ios::trunc | std::ios::out},
        start{std::chrono::high_resolution_clock::now()}
    {
    }

    ~log_data()
    {
        if (file.is_open())
        {
            file.flush();
            file.close();
        }
    }

    std::ofstream file;
    std::chrono::high_resolution_clock::time_point start;
};

log_data instance;

}

namespace fae
{

void finish_log(log_type type, std::stringstream & ss)
{
    auto str{ss.str()};

    auto now{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> dur{now - instance.start};
    double elapsed{dur.count()};

    std::cout << '[' << elapsed << "] " << ansi_color_code(type) << str << '\n';
    std::cout << ansi_color_code(log_type::message);
    instance.file << '[' << elapsed << ' ' << log_type_str(type) << "] " << str << '\n';
}

}
