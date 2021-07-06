#include "renderer.hpp"

#include <glad/glad.h>

namespace fae
{

renderer::renderer()
{
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
