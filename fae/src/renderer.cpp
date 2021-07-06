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
    fae::logger::instance().log(str.c_str());
}

}

namespace fae
{

renderer::renderer():
    vao_{0}
{
    glDebugMessageCallback(gl_error_callback, nullptr);

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer::draw_buffers(vertex_buffer const & verts, index_buffer const & tris)
{
    verts.bind();
    tris.bind();
    glDrawElements(GL_TRIANGLES, 3 * tris.size(), GL_UNSIGNED_INT, nullptr);
}

}
