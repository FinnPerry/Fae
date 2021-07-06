#include "application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <sstream>

#include "logger.hpp"

namespace
{

void glfw_error_callback(int error, char const * message)
{
    std::string str{"glfw error "};
    str += std::to_string(error);
    str += ": ";
    str += message;
    fae::logger::instance().log(str.c_str());
}

}

namespace fae
{

application::application():
    window_{nullptr},
    renderer_{nullptr}
{
}

void application::run(int width, int height, std::string title)
{
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();
    logger::instance().log("Initialized glfw.");
    window_ = std::make_unique<window>(width, height, std::move(title));
    window_->bind();
    renderer_ = std::make_unique<renderer>();

    load();
    while (!window_->should_close())
    {
        glfwPollEvents();
        renderer_->clear();
        update();
        window_->update_screen();
    }
    unload();

    renderer_.reset();
    window_.reset();
    glfwTerminate();
    logger::instance().log("Terminated glfw.");
}

}
