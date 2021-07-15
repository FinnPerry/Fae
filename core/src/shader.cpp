#include "shader.hpp"

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

char const * default_vert
{
    "vec4 vert()\n"
    "{\n"
    "   return vec4(position, 1.0f);\n"
    "}"
};

std::string frag_start
{
    "#version 430\n"
    "out vec4 color;\n"
};

char const * frag_end
{
    "void main()\n"
    "{\n"
    "   color = frag();\n"
    "}"
};

char const * default_frag
{
    "vec4 frag()\n"
    "{\n"
    "   return vec4(1.0f);\n"
    "}"
};

}

namespace fae
{

shader::shader(char const * vert, char const * frag):
    id_{0}
{
    if (!vert)
    {
        vert = default_vert;
    }
    auto full_vert{vert_start + vert + vert_end};
    auto vert_ptr{full_vert.c_str()};
    auto vs{glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vs, 1, &vert_ptr, nullptr);
    glCompileShader(vs);

    if (!frag)
    {
        frag = default_frag;
    }
    auto full_frag{frag_start + frag + frag_end};
    auto frag_ptr{full_frag.c_str()};
    auto fs{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fs, 1, &frag_ptr, nullptr);
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
