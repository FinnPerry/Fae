#include "mesh.hpp"

#include "glad_context.hpp"

namespace fae
{

mesh::mesh(glad_context * context):
    m_gl_context{context},
    m_vao{0},
    m_vbo{0},
    m_vb_size{0},
    m_ibo{0},
    m_ib_size{0}
{
    m_gl_context->gen_vertex_arrays(1, &m_vao);
    bind();

    m_gl_context->gen_buffers(1, &m_vbo);
    m_gl_context->bind_buffer(glad_context::gldef_array_buffer(), m_vbo);
    auto off{offsetof(vertex, position)};
    m_gl_context->vertex_attrib_pointer(0, 3, glad_context::gldef_float(), false, 0, reinterpret_cast<void *>(off));
    m_gl_context->enable_vertex_attrib_array(0);

    m_gl_context->gen_buffers(1, &m_ibo);
    m_gl_context->bind_buffer(glad_context::gldef_element_array_buffer(), m_ibo);
}

mesh::~mesh()
{
    m_gl_context->delete_buffers(1, &m_ibo);
    m_gl_context->delete_buffers(1, &m_vbo);
    m_gl_context->delete_vertex_arrays(1, &m_vao);
}

void mesh::bind() const
{
    m_gl_context->bind_vertex_array(m_vao);
}

void mesh::set_verts(vertex const * data, int size)
{
    bind();
    m_vb_size = size;
    m_gl_context->buffer_data(glad_context::gldef_array_buffer(), m_vb_size * sizeof(vertex), data, glad_context::gldef_dynamic_draw());
}

void mesh::set_verts_partial(vertex const * data, int start, int size)
{
    bind();
    m_gl_context->buffer_sub_data(glad_context::gldef_array_buffer(), start * sizeof(vertex), size * sizeof(vertex), data);
}

void mesh::set_tris(triangle const * data, int size)
{
    bind();
    m_ib_size = size;
    m_gl_context->buffer_data(glad_context::gldef_element_array_buffer(), m_ib_size * sizeof(triangle), data, glad_context::gldef_dynamic_draw());
}

void mesh::set_tris_partial(triangle const * data, int start, int size)
{
    bind();
    m_gl_context->buffer_sub_data(glad_context::gldef_element_array_buffer(), start * sizeof(triangle), size * sizeof(triangle), data);
}

}
