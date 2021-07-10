#include "shader.hpp"

#include <string>

#include <glad/glad.h>

namespace
{

std::string vert_start
{
    "#version 430\n"
    "in vec3 position;\n"
};

char const * vert_end
{
    "void main()\n"
    "{\n"
    "   gl_Position = vert();\n"
    "}"
};

}

namespace fae
{

shader::shader(char const * vert, char const * frag):
    id_{0}
{
    auto full_vert{vert_start + vert + vert_end};
    auto vert_ptr{full_vert.c_str()};
    auto vs{glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vs, 1, &vert_ptr, nullptr);
    glCompileShader(vs);

    auto fs{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fs, 1, &frag, nullptr);
    glCompileShader(fs);

    id_ = glad_glCreateProgram();
    glAttachShader(id_, vs);
    glAttachShader(id_, fs);
    glLinkProgram(id_);

    glDeleteShader(fs);
    glDeleteShader(vs);
}

shader::~shader()
{
    glDeleteProgram(id_);
}

void shader::bind()
{
    glUseProgram(id_);
}

}
