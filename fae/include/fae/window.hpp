#ifndef FAE_WINDOW_GUARD
#define FAE_WINDOW_GUARD

#include <string>

struct GLFWwindow;

namespace fae
{

class window
{
public:
    window();

    window(std::string title, int width, int height);

    ~window();

    static void poll_events();

    void open(std::string title, int width, int height);

    void close();

    bool is_open();

    bool should_close();

    void bind();

    void update();

    void clear();

private:
    static int count_;

    GLFWwindow * window_;
    std::string title_;
};

}

#endif
