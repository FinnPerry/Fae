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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    window_.reset(glfwCreateWindow(width, height, title_.c_str(), nullptr, nullptr));
    // log(("Created window \"" + title_ + "\".").c_str());
}

window::~window()
{
    // log(("Destroyed window \"" + title_ + "\".").c_str());
}

bool window::should_close()
{
    return glfwWindowShouldClose(window_.get());
}

void window::bind()
{
    glfwMakeContextCurrent(window_.get());
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    // log(("Initialized glad for window \"" + title_ + "\".").c_str());
    // log(reinterpret_cast<char const *>(glGetString(GL_RENDERER)));
    // log(reinterpret_cast<char const *>(glGetString(GL_VERSION)));
}

void window::update_screen()
{
    glfwSwapBuffers(window_.get());
}

}
