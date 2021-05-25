#include "window.hpp"

#include <iostream>

namespace fae
{

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

void window::open(std::string title, int width, int height)
{
    title_ = std::move(title);
    window_ = glfwCreateWindow(width, height, title_.c_str(), nullptr, nullptr);
    std::cout << "open\n";
}

void window::close()
{
    if (!is_open())
    {
        return;
    }

    window_ = nullptr;
    title_ = "";
    std::cout << "close\n";
}

bool window::is_open()
{
    return window_ != nullptr;
}

}
