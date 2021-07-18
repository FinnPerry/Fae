#include "mesh.hpp"

#include "glad_context.hpp"

namespace fae
{

mesh::mesh(glad_context * context):
    context_{context},
    vao_{0},
    vbo_{0},
    vb_size_{0},
    ibo_{0},
    ib_size_{0}
{
    context_->gen_vertex_arrays(1, &vao_);
    bind();

    context_->gen_buffers(1, &vbo_);
    context_->bind_buffer(gl_array_buffer, vbo_);
    auto off{offsetof(vertex, position)};
    context_->vertex_attrib_pointer(0, 3, gl_float, false, 0, reinterpret_cast<void *>(off));
    context_->enable_vertex_attrib_array(0);

    context_->gen_buffers(1, &ibo_);
    context_->bind_buffer(gl_element_array_buffer, ibo_);
}

mesh::~mesh()
{
    context_->delete_buffers(1, &ibo_);
    context_->delete_buffers(1, &vbo_);
    context_->delete_vertex_arrays(1, &vao_);
}

void mesh::bind() const
{
    context_->bind_vertex_array(vao_);
}

void mesh::set_verts(vertex const * data, int size)
{
    bind();
    vb_size_ = size;
    context_->buffer_data(gl_array_buffer, vb_size_ * sizeof(vertex), data, gl_dynamic_draw);
}

void mesh::set_verts_partial(vertex const * data, int start, int size)
{
    bind();
    context_->buffer_sub_data(gl_array_buffer, start * sizeof(vertex), size * sizeof(vertex), data);
}

void mesh::set_tris(triangle const * data, int size)
{
    bind();
    ib_size_ = size;
    context_->buffer_data(gl_element_array_buffer, ib_size_ * sizeof(triangle), data, gl_dynamic_draw);
}

void mesh::set_tris_partial(triangle const * data, int start, int size)
{
    bind();
    context_->buffer_sub_data(gl_element_array_buffer, start * sizeof(triangle), size * sizeof(triangle), data);
}

}
