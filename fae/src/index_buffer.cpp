#include "index_buffer.hpp"

#include <glad/glad.h>

namespace fae
{

index_buffer::index_buffer():
    id_{0},
    size_{0}
{
    glGenBuffers(1, &id_);
}

index_buffer::index_buffer(int size, triangle const * data):
    id_{0},
    size_{size}
{
    glGenBuffers(1, &id_);
    set_data(size_, data);
}

index_buffer::~index_buffer()
{
    glDeleteBuffers(1, &id_);
}

void index_buffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
}

void index_buffer::set_data(int size, triangle const * data)
{
    bind();
    size_ = size;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_ * sizeof(triangle), data, GL_DYNAMIC_DRAW);
}

void index_buffer::set_data_partial(int start, int size, triangle const * data)
{
    bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, start * sizeof(triangle), size * sizeof(triangle), data);
}

}
