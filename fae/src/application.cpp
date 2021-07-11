#include "application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <sstream>
#include <memory>

#include "entity.hpp"
#include "logger.hpp"
#include "renderer.hpp"
#include "window.hpp"

namespace
{

void glfw_error_callback(int error, char const * message)
{
    fae::log(fae::log_type::error, "GLFW error", error, ':', message);
}

}

namespace fae
{

void run(int width, int height, std::string title, entity * root)
{
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();
    log("Initialized GLFW.");
    auto window_ptr = std::make_unique<window>(width, height, std::move(title));
    window_ptr->bind();
    auto renderer_ptr = std::make_unique<renderer>();

    entity::update_args uargs
    {
        window_ptr.get(),
        root
    };

    entity::render_args rargs
    {
        renderer_ptr.get()
    };

    root->load_rec(uargs);
    while (!window_ptr->should_close())
    {
        glfwPollEvents();
        root->update_rec(uargs);

        renderer_ptr->clear();
        root->render_rec(rargs);
        window_ptr->update_screen();
    }
    root->unload_rec(uargs);

    renderer_ptr.reset();
    window_ptr.reset();
    glfwTerminate();
    log("Terminated GLFW.");
}

}
