#include <string>
#include <fstream>

namespace fae
{

class logger
{
public:
    logger(std::string const & path);

    ~logger();

    logger & operator <<(char const * right);

    logger & operator <<(std::string const & right);

    logger & operator <<(char right);

    logger & operator <<(int right);

    logger & operator <<(float right);

private:
    std::ofstream file_;
};

}
