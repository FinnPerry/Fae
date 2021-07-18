#include "window.hpp"

#include "logger.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GET_USER_PTR auto window{reinterpret_cast<::fae::window *>(glfwGetWindowUserPointer(glfw_win))}

namespace
{

void glfw_error_callback(int error, char const * message)
{
    fae::log(fae::log_type::error, "GLFW error", error, ':', message);
}

void window_close_callback(GLFWwindow * glfw_win)
{
    GET_USER_PTR;
    window->on_close();
}

void window_resize_callback(GLFWwindow * glfw_win, int width, int height)
{
    glViewport(0, 0, width, height);

    GET_USER_PTR;
    window->on_resize(width, height);
}

}

namespace fae
{

int window::instance_count_{0};

window::window(int width, int height, std::string title):
    on_close{},
    on_resize{},
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
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    log("Initialized Glad for window", '"' + title_ + "\".");
    log("OpenGL version:", reinterpret_cast<char const *>(glGetString(GL_VERSION)));
    log("OpenGL renderer:", reinterpret_cast<char const *>(glGetString(GL_RENDERER)));
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
