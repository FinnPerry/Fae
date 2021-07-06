#include "shader.hpp"

#include <glad/glad.h>

namespace fae
{

shader::shader(char const * vert, char const * frag):
    id_{0}
{
    auto vs{glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vs, 1, &vert, nullptr);
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
