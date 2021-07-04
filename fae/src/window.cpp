#include "window.hpp"

#include "logger.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>

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
    std::stringstream ss{};
    ss << "Opened window ";
    ss << reinterpret_cast<void *>(window_);
    logger::instance().log(ss.str().c_str());

    glfwMakeContextCurrent(window_);
}

void window::close()
{
    if (!is_open())
    {
        return;
    }

    std::stringstream ss{};
    ss << "Closed window ";
    ss << reinterpret_cast<void *>(window_);
    logger::instance().log(ss.str().c_str());

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

void window::bind()
{
    if (is_open())
    {
        gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    }
}

void window::update()
{
    if (is_open())
    {
        glfwSwapBuffers(window_);
    }
}

void window::clear()
{
    if (is_open())
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

}
