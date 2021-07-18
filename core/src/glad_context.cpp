#include "glad_context.hpp"

#include <stdexcept>

#include <glad/glad.h>

namespace fae
{

int glad_context::glenum_array_buffer()
{
    return GL_ARRAY_BUFFER;
}

int glad_context::glenum_float()
{
    return GL_FLOAT;
}

int glad_context::glenum_element_array_buffer()
{
    return GL_ELEMENT_ARRAY_BUFFER;
}

int glad_context::glenum_dynamic_draw()
{
    return GL_DYNAMIC_DRAW;
}

void glad_context::gen_vertex_arrays(int n, unsigned int * arrays)
{
    glGenVertexArrays(n, arrays);
}

void glad_context::gen_buffers(int n, unsigned int * buffers)
{
    glGenBuffers(n, buffers);
}

void glad_context::bind_buffer(int target, unsigned int buffer)
{
    glBindBuffer(target, buffer);
}

void glad_context::vertex_attrib_pointer(unsigned int index, int size, int type, bool normalized, int stride, void const * pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void glad_context::enable_vertex_attrib_array(unsigned int index)
{
    glEnableVertexAttribArray(index);
}

void glad_context::delete_buffers(int n, unsigned int const * buffers)
{
    glDeleteBuffers(n, buffers);
}

void glad_context::delete_vertex_arrays(int n, unsigned int const * arrays)
{
    glDeleteVertexArrays(n, arrays);
}

void glad_context::bind_vertex_array(unsigned int array)
{
    glBindVertexArray(array);
}

void glad_context::buffer_data(int target, long size, void const * data, int usage)
{
    glBufferData(target, size, data, usage);
}

void glad_context::buffer_sub_data(int target, long offset, long size, void const * data)
{
    glBufferSubData(target, offset, size, data);
}

}
