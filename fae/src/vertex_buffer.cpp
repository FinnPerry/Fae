#include "vertex_buffer.hpp"

#include <glad/glad.h>

#include <cstddef>

namespace fae
{

vertex_buffer::vertex_buffer():
    id_{0},
    size_{0}
{
    glGenBuffers(1, &id_);
}

vertex_buffer::vertex_buffer(int size, vertex const * data):
    id_{0},
    size_{size}
{
    glGenBuffers(1, &id_);
    set_data(size_, data);
}

vertex_buffer::~vertex_buffer()
{
    glDeleteBuffers(1, &id_);
}

void vertex_buffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, offsetof(vertex, position));
}

void vertex_buffer::set_data(int size, vertex const * data)
{
    bind();
    size_ = size;
    glBufferData(GL_ARRAY_BUFFER, size_ * sizeof(vertex), data, GL_DYNAMIC_DRAW);
}

void vertex_buffer::set_data_partial(int start, int size, vertex const * data)
{
    bind();
    glBufferSubData(GL_ARRAY_BUFFER, start * sizeof(vertex), size * sizeof(vertex), data);
}

}
