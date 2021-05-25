#include <string>

#include <GLFW/glfw3.h>

namespace fae
{

class window
{
public:
    window();

    window(std::string title, int width, int height);

    ~window();

    void open(std::string title, int width, int height);

    void close();

    bool is_open();

private:
    void * window_;
    std::string title_;
};

}
