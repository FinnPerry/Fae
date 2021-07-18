#include "window.hpp"

#include <GLFW/glfw3.h>

#include "glad_context.hpp"
#include "logger.hpp"

namespace
{

fae::window * get_user_ptr(GLFWwindow * win)
{
    return reinterpret_cast<::fae::window *>(glfwGetWindowUserPointer(win));
}

void glfw_error_callback(int error, char const * message)
{
    fae::log(fae::log_type::error, "GLFW error", error, ':', message);
}

void window_close_callback(GLFWwindow * glfw_win)
{
    auto window{get_user_ptr(glfw_win)};
    window->on_close();
}

void window_resize_callback(GLFWwindow * glfw_win, int width, int height)
{
    auto window{get_user_ptr(glfw_win)};
    window->get_context()->viewport(0, 0, width, height);
    window->on_resize(width, height);
}

}

namespace fae
{

int window::instance_count_{0};

window::window(glad_context * context, int width, int height, std::string title):
    on_close{},
    on_resize{},
    context_{context},
    window_{nullptr, glfwDestroyWindow},
    width_{width},
    height_{height},
    title_{std::move(title)}
{
}

window::~window()
{
    close();
    log("Destroyed window", '"' + title_ + "\".");
}

void window::open()
{
    init_glfw();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    window_.reset(glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr));
    log("Created window", '"' + title_ + "\".");

    glfwSetWindowUserPointer(window_.get(), this);
    glfwSetWindowCloseCallback(window_.get(), window_close_callback);
    glfwSetWindowSizeCallback(window_.get(), window_resize_callback);
}

void window::close()
{
    window_.reset();
    terminate_glfw();
}

void window::update()
{
    glfwPollEvents();
}

bool window::should_close()
{
    return glfwWindowShouldClose(window_.get());
}

void window::bind()
{
    glfwMakeContextCurrent(window_.get());
    context_->load_gl_loader(reinterpret_cast<void(*)(char const *)>(glfwGetProcAddress));
    log("Initialized OpenGL context for window", '"' + title_ + "\".");
    log("OpenGL version:", context_->get_string(glad_context::gldef_version()));
    log("OpenGL renderer:", context_->get_string(glad_context::gldef_renderer()));
}

void window::update_screen()
{
    glfwSwapBuffers(window_.get());
}

void window::init_glfw()
{
    ++instance_count_;
    if (instance_count_ == 1)
    {
        glfwSetErrorCallback(glfw_error_callback);
        glfwInit();
        log("Initialized GLFW.");
    }
}

void window::terminate_glfw()
{
    --instance_count_;
    if (instance_count_ == 0)
    {
        glfwTerminate();
        log("Terminated GLFW.");
    }
}

}
