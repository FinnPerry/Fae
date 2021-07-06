#ifndef FAE_WINDOW_GUARD
#define FAE_WINDOW_GUARD

#include <string>
#include <memory>

struct GLFWwindow;

namespace fae
{

class window
{
public:
    window(int width, int height, std::string title);

    ~window();

    bool should_close();

    void bind();

    void update_screen();

private:
    using win_ptr = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow *)>;

    win_ptr window_;
    std::string title_;
};

}

#endif
