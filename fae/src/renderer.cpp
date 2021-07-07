#include "renderer.hpp"

#include <string>

#include <glad/glad.h>

#include "logger.hpp"

namespace
{

void gl_error_callback(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, char const * message, void const * user_arg)
{
    if (severity == GL_DEBUG_SEVERITY_NOTIFICATION)
    {
        return;
    }

    std::string str{"opengl error "};
    str += std::to_string(id);
    str += ": ";
    str += message;
    fae::log(str.c_str(), fae::log_type::error);
}

}

namespace fae
{

renderer::renderer():
    vao_{0}
{
    glDebugMessageCallback(gl_error_callback, nullptr);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer::draw_mesh(mesh const & m)
{
    m.bind();
    glDrawElements(GL_TRIANGLES, 3 * m.get_ib_size(), GL_UNSIGNED_INT, nullptr);
}

}
