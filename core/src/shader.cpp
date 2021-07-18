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
    context_{context},
    id_{0}
{
    if (!vert)
    {
        vert = default_vert;
    }
    auto full_vert{vert_start + vert + vert_end};
    auto vert_ptr{full_vert.c_str()};
    auto vs{context_->create_shader(glad_context::gldef_vertex_shader())};
    context_->shader_source(vs, 1, &vert_ptr, nullptr);
    context_->compile_shader(vs);

    if (!frag)
    {
        frag = default_frag;
    }
    auto full_frag{frag_start + frag + frag_end};
    auto frag_ptr{full_frag.c_str()};
    auto fs{context_->create_shader(glad_context::gldef_fragment_shader())};
    context_->shader_source(fs, 1, &frag_ptr, nullptr);
    context_->compile_shader(fs);

    id_ = context_->create_program();
    context_->attach_shader(id_, vs);
    context_->attach_shader(id_, fs);
    context_->link_program(id_);

    context_->delete_shader(fs);
    context_->delete_shader(vs);
}

shader::~shader()
{
    context_->delete_program(id_);
}

void shader::bind()
{
    context_->use_program(id_);
}

}
