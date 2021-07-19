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

void m_windowclose_callback(GLFWwindow * glfw_win)
{
    auto window{get_user_ptr(glfw_win)};
    window->on_close();
}

void m_windowresize_callback(GLFWwindow * glfw_win, int width, int height)
{
    auto window{get_user_ptr(glfw_win)};
    window->get_context()->viewport(0, 0, width, height);
    window->on_resize(width, height);
}

}

namespace fae
{

int window::m_instance_count{0};

window::window(glad_context * context, int width, int height, std::string title):
    on_close{},
    on_resize{},
    m_gl_context{context},
    m_window{nullptr, glfwDestroyWindow},
    m_width{width},
    m_height{height},
    m_title{std::move(title)}
{
}

window::~window()
{
    close();
    log("Destroyed window", '"' + m_title + "\".");
}

void window::open()
{
    init_glfw();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    m_window.reset(glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr));
    log("Created window", '"' + m_title + "\".");

    glfwSetWindowUserPointer(m_window.get(), this);
    glfwSetWindowCloseCallback(m_window.get(), m_windowclose_callback);
    glfwSetWindowSizeCallback(m_window.get(), m_windowresize_callback);
}

void window::close()
{
    m_window.reset();
    terminate_glfw();
}

void window::update()
{
    glfwPollEvents();
}

bool window::should_close()
{
    return glfwWindowShouldClose(m_window.get());
}

void window::bind()
{
    glfwMakeContextCurrent(m_window.get());
    m_gl_context->load_gl_loader(reinterpret_cast<void(*)(char const *)>(glfwGetProcAddress));
    log("Initialized OpenGL context for window", '"' + m_title + "\".");
    log("OpenGL version:", m_gl_context->get_string(glad_context::gldef_version()));
    log("OpenGL renderer:", m_gl_context->get_string(glad_context::gldef_renderer()));
}

void window::update_screen()
{
    glfwSwapBuffers(m_window.get());
}

void window::init_glfw()
{
    ++m_instance_count;
    if (m_instance_count == 1)
    {
        glfwSetErrorCallback(glfw_error_callback);
        glfwInit();
        log("Initialized GLFW.");
    }
}

void window::terminate_glfw()
{
    --m_instance_count;
    if (m_instance_count == 0)
    {
        glfwTerminate();
        log("Terminated GLFW.");
    }
}

}
