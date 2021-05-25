#include "window.hpp"

#include <GLFW/glfw3.h>

namespace fae
{

int window::count_{0};

window::window():
    window_{nullptr},
    title_{""}
{
}

window::window(std::string title, int width, int height):
    window()
{
    open(title, width, height);
}

window::~window()
{
    close();
}

void window::poll_events()
{
    if (count_ == 0)
    {
        return;
    }

    glfwPollEvents();
}

void window::open(std::string title, int width, int height)
{
    ++count_;
    if (count_ == 1)
    {
        glfwInit();
    }

    title_ = std::move(title);
    window_ = glfwCreateWindow(width, height, title_.c_str(), nullptr, nullptr);
}

void window::close()
{
    if (!is_open())
    {
        return;
    }

    window_ = nullptr;
    title_ = "";

    --count_;
    if (count_ == 0)
    {
        glfwTerminate();
    }
}

bool window::is_open()
{
    return window_ != nullptr;
}

bool window::should_close()
{
    if (!is_open())
    {
        return false;
    }

    return glfwWindowShouldClose(window_);
}

}
