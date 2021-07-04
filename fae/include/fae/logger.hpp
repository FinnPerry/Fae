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

private:
    double get_elapsed();

    std::chrono::high_resolution_clock::time_point start_;
    std::ofstream file_;
};

}
