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

renderer::renderer()
{
    glDebugMessageCallback(gl_error_callback, nullptr);

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
    glDrawArrays(GL_TRIANGLES, 0, tris.size() * 3);
}

}
