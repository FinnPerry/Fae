#include "glad_context.hpp"

#include <stdexcept>

#include <glad/glad.h>

namespace fae
{

void glad_context::gen_vertex_arrays(int n, unsigned int * arrays)
{
    glGenVertexArrays(n, arrays);
}

void glad_context::gen_buffers(int n, unsigned int * buffers)
{
    glGenBuffers(n, buffers);
}

void glad_context::bind_buffer(gl_enum target, unsigned int buffer)
{
    glBindBuffer(convert_enum(target), buffer);
}

void glad_context::vertex_attrib_pointer(unsigned int index, int size, gl_enum type, bool normalized, int stride, void const * pointer)
{
    glVertexAttribPointer(index, size, convert_enum(type), normalized, stride, pointer);
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

void glad_context::buffer_data(gl_enum target, long size, void const * data, gl_enum usage)
{
    glBufferData(convert_enum(target), size, data, convert_enum(usage));
}

void glad_context::buffer_sub_data(gl_enum target, long offset, long size, void const * data)
{
    glBufferSubData(convert_enum(target), offset, size, data);
}

int glad_context::convert_enum(gl_enum e)
{
    switch (e)
    {
        case gl_array_buffer:
        {
            return GL_ARRAY_BUFFER;
        }
        case gl_element_array_buffer:
        {
            return GL_ELEMENT_ARRAY_BUFFER;
        }
        case gl_float:
        {
            return GL_FLOAT;
        }
        case gl_dynamic_draw:
        {
            return GL_DYNAMIC_DRAW;
        }
        default:
        {
            throw std::invalid_argument{"Unsupported gl_enum."};
        }
    }
}

}
