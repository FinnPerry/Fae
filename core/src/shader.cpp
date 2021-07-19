#include "shader.hpp"

#include "glad_context.hpp"

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

shader::shader(glad_context * context, char const * vert, char const * frag):
    m_gl_context{context},
    m_id{0}
{
    if (!vert)
    {
        vert = default_vert;
    }
    auto full_vert{vert_start + vert + vert_end};
    auto vert_ptr{full_vert.c_str()};
    auto vs{m_gl_context->create_shader(glad_context::gldef_vertex_shader())};
    m_gl_context->shader_source(vs, 1, &vert_ptr, nullptr);
    m_gl_context->compile_shader(vs);

    if (!frag)
    {
        frag = default_frag;
    }
    auto full_frag{frag_start + frag + frag_end};
    auto frag_ptr{full_frag.c_str()};
    auto fs{m_gl_context->create_shader(glad_context::gldef_fragment_shader())};
    m_gl_context->shader_source(fs, 1, &frag_ptr, nullptr);
    m_gl_context->compile_shader(fs);

    m_id = m_gl_context->create_program();
    m_gl_context->attach_shader(m_id, vs);
    m_gl_context->attach_shader(m_id, fs);
    m_gl_context->link_program(m_id);

    m_gl_context->delete_shader(fs);
    m_gl_context->delete_shader(vs);
}

shader::~shader()
{
    m_gl_context->delete_program(m_id);
}

void shader::bind()
{
    m_gl_context->use_program(m_id);
}

}
