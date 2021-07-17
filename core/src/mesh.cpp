#include "mesh.hpp"

#include <glad/glad.h>

namespace fae
{

mesh::mesh():
    vao_{0},
    vbo_{0},
    vb_size_{0},
    ibo_{0},
    ib_size_{0}
{
    glGenVertexArrays(1, &vao_);
    bind();

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    auto off{offsetof(vertex, position)};
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(off));
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &ibo_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
}

mesh::~mesh()
{
    glDeleteBuffers(1, &ibo_);
    glDeleteBuffers(1, &vbo_);
    glDeleteVertexArrays(1, &vao_);
}

void mesh::bind() const
{
    glBindVertexArray(vao_);
}

void mesh::set_verts(vertex const * data, int size)
{
    bind();
    vb_size_ = size;
    glBufferData(GL_ARRAY_BUFFER, vb_size_ * sizeof(vertex), data, GL_DYNAMIC_DRAW);
}

void mesh::set_verts_partial(vertex const * data, int start, int size)
{
    bind();
    glBufferSubData(GL_ARRAY_BUFFER, start * sizeof(vertex), size * sizeof(vertex), data);
}

void mesh::set_tris(triangle const * data, int size)
{
    bind();
    ib_size_ = size;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_ * sizeof(triangle), data, GL_DYNAMIC_DRAW);
}

void mesh::set_tris_partial(triangle const * data, int start, int size)
{
    bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, start * sizeof(triangle), size * sizeof(triangle), data);
}

}
