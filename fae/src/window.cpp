#include "window.hpp"

#include "logger.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>

namespace fae
{

window::window(int width, int height, std::string title):
    window_{nullptr, glfwDestroyWindow}
{
    title_ = std::move(title);
    window_.reset(glfwCreateWindow(width, height, title_.c_str(), nullptr, nullptr));
    logger::instance().log(("Created window " + window_ptr_str() + '.').c_str());
}

window::~window()
{
    logger::instance().log(("Destroyed window " + window_ptr_str() + '.').c_str());
}

bool window::should_close()
{
    return glfwWindowShouldClose(window_.get());
}

std::string window::window_ptr_str()
{
    std::stringstream ss{};
    ss << reinterpret_cast<void *>(window_.get());
    return ss.str();
}

void window::bind()
{
    glfwMakeContextCurrent(window_.get());
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    logger::instance().log(("Initialized glad for window " + window_ptr_str() + '.').c_str());
}

void window::update_screen()
{
    glfwSwapBuffers(window_.get());
}

void window::clear()
{
    // this should be moved to a renderer class
    glClear(GL_COLOR_BUFFER_BIT);
}

}
