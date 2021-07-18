#ifndef FAE_WINDOW_GUARD
#define FAE_WINDOW_GUARD

#include <string>
#include <memory>

#include "event.hpp"

struct GLFWwindow;

namespace fae
{

class window
{
public:
    window(int width, int height, std::string title);

    ~window();

    void open();
    
    void close();
    
    void update();

    bool should_close();
    
    void bind();

    void update_screen();

    event<> on_close;

    event<int, int> on_resize;

private:
    using win_ptr = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow *)>;
    
    void init_glfw();
    
    void terminate_glfw();
    
    static int instance_count_;

    win_ptr window_;
    int width_;
    int height_;
    std::string title_;
};

}

#endif
