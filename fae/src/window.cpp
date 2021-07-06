#include "window.hpp"

#include "logger.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace fae
{

window::window(int width, int height, std::string title):
    window_{nullptr, glfwDestroyWindow},
    title_{std::move(title)}
{
    window_.reset(glfwCreateWindow(width, height, title_.c_str(), nullptr, nullptr));
    logger::instance().log(("Created window \"" + title_ + "\".").c_str());
}

window::~window()
{
    logger::instance().log(("Destroyed window \"" + title_ + "\".").c_str());
}

bool window::should_close()
{
    return glfwWindowShouldClose(window_.get());
}

void window::bind()
{
    glfwMakeContextCurrent(window_.get());
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    logger::instance().log(("Initialized glad for window \"" + title_ + "\".").c_str());
}

void window::update_screen()
{
    glfwSwapBuffers(window_.get());
}

}
