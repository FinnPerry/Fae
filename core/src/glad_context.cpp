#include "glad_context.hpp"

#include <stdexcept>

#include <glad/glad.h>

namespace fae
{

int glad_context::gldef_array_buffer()
{
    return GL_ARRAY_BUFFER;
}

int glad_context::gldef_float()
{
    return GL_FLOAT;
}

int glad_context::gldef_element_array_buffer()
{
    return GL_ELEMENT_ARRAY_BUFFER;
}

int glad_context::gldef_dynamic_draw()
{
    return GL_DYNAMIC_DRAW;
}

int glad_context::gldef_debug_severity_notification()
{
    return GL_DEBUG_SEVERITY_NOTIFICATION;
}

int glad_context::gldef_depth_test()
{
    return GL_DEPTH_TEST;
}

int glad_context::gldef_less()
{
    return GL_LESS;
}

int glad_context::gldef_color_buffer_bit()
{
    return GL_COLOR_BUFFER_BIT;
}

int glad_context::gldef_depth_buffer_bit()
{
    return GL_DEPTH_BUFFER_BIT;
}

int glad_context::gldef_triangles()
{
    return GL_TRIANGLES;
}

int glad_context::gldef_unsigned_int()
{
    return GL_UNSIGNED_INT;
}

int glad_context::gldef_vertex_shader()
{
    return GL_VERTEX_SHADER;
}

int glad_context::gldef_fragment_shader()
{
    return GL_FRAGMENT_SHADER;
}

int glad_context::gldef_version()
{
    return GL_VERSION;
}

int glad_context::gldef_renderer()
{
    return GL_RENDERER;
}

void glad_context::load_gl_loader(void(*load_proc)(char const *))
{
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(load_proc));
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

void glad_context::debug_message_callback(debug_proc callback, void const * user_param)
{
    auto ptr{reinterpret_cast<GLDEBUGPROC>(callback)};
    glDebugMessageCallback(ptr, user_param);
}

void glad_context::enable(int cap)
{
    glEnable(cap);
}

void glad_context::depth_func(int func)
{
    glDepthFunc(func);
}

void glad_context::clear(int mask)
{
    glClear(mask);
}

void glad_context::draw_elements(int mode, int count, int type, void const * indices)
{
    glDrawElements(mode, count, type, indices);
}

unsigned int glad_context::create_shader(int type)
{
    return glCreateShader(type);
}

void glad_context::shader_source(unsigned int shader, int count, char const ** string, int const * length)
{
    glShaderSource(shader, count, string, length);
}

void glad_context::compile_shader(unsigned int shader)
{
    glCompileShader(shader);
}

unsigned int glad_context::create_program()
{
    return glCreateProgram();
}

void glad_context::attach_shader(unsigned int program, unsigned int shader)
{
    glAttachShader(program, shader);
}

void glad_context::link_program(unsigned int program)
{
    glLinkProgram(program);
}

void glad_context::delete_shader(unsigned int shader)
{
    glDeleteShader(shader);
}

void glad_context::delete_program(unsigned int program)
{
    glDeleteProgram(program);
}

void glad_context::use_program(unsigned int program)
{
    glUseProgram(program);
}

char const * glad_context::get_string(int name)
{
    return reinterpret_cast<char const *>(glGetString(name));
}

void glad_context::viewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
}

}
