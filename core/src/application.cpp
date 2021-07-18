#include "application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

application::application(window * win, renderer * ren, entity * root):
    win_{win},
    ren_{ren},
    root_{root}
{
}

application::~application()
{
}

void application::run()
{
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();
    log("Initialized GLFW.");
    win_->open();
    win_->bind();
    ren_->init();

    entity::update_args u_args
    {
        win_,
        root_
    };

    entity::render_args r_args
    {
        ren_
    };

    root_->load_rec(u_args);
    while (!win_->should_close())
    {
        glfwPollEvents();
        root_->update_rec(u_args);

        ren_->clear();
        root_->render_rec(r_args);
        win_->update_screen();
    }
    root_->unload_rec(u_args);

    win_->close();
    glfwTerminate();
    log("Terminated GLFW.");
}

}
