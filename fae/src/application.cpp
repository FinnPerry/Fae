#include "application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <sstream>

#include "logger.hpp"

namespace
{

void glfw_error_callback(int error, char const * message)
{
    fae::log(fae::log_type::error, "GLFW error", error, ':', message);
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
    log("Initialized GLFW.");
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
    log("Terminated GLFW.");
}

}
