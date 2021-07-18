#include "triangle_entity.hpp"

namespace fae_demo
{

triangle_entity::triangle_entity(fae::glad_context * context):
    context_{context},
    shader_{nullptr},
    mesh_{nullptr},
    window_size_event_{0}
{
}

void triangle_entity::load(update_args const & args)
{
    shader_ = std::make_unique<fae::shader>();

    mesh_ = std::make_unique<fae::mesh>(context_);
    fae::vertex vert_data[3]
    {
        {0.0f, 0.5f},
        {0.5f, -0.5f},
        {-0.5f, -0.5f}
    };
    mesh_->set_verts(vert_data, 3);
    fae::triangle tri_data[1]
    {
        {0, 1, 2}
    };
    mesh_->set_tris(tri_data, 1);
    
    window_size_event_ = args.window_ptr->on_resize.add_callback([](int w, int h)->void
    {
        fae::log(w, h);
    });
}

void triangle_entity::unload(update_args const & args)
{
    args.window_ptr->on_resize.remove_callback(window_size_event_);
    mesh_.reset();
    shader_.reset();
}

void triangle_entity::render(render_args const & args) const
{
    shader_->bind();
    args.renderer_ptr->draw_mesh(*mesh_.get());
}

}
