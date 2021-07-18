#include "renderer.hpp"

#include "glad_context.hpp"
#include "logger.hpp"
#include "mesh.hpp"

namespace
{

void gl_error_callback(int source, int type, unsigned int id, int severity, int length, char const * message, void const * user_arg)
{
    if (severity != fae::glad_context::gldef_debug_severity_notification())
    {
        fae::log(fae::log_type::error, "OpenGL error", id, ':', message);
    }
}

}

namespace fae
{

renderer::renderer(glad_context * context):
    context_{context}
{
}

void renderer::init()
{
    context_->debug_message_callback(gl_error_callback, nullptr);

    context_->enable(glad_context::gldef_depth_test());
    context_->depth_func(glad_context::gldef_less());
}

void renderer::clear()
{
    context_->clear(glad_context::gldef_color_buffer_bit() | glad_context::gldef_depth_buffer_bit());
}

void renderer::draw_mesh(mesh const & m)
{
    m.bind();
    context_->draw_elements(glad_context::gldef_triangles(), 3 * m.get_ib_size(), glad_context::gldef_unsigned_int(), nullptr);
}

}
