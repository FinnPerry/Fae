#include "triangle_entity.hpp"

namespace
{

void window_size_callback(int w, int h)
{
    fae::log(w, h);
}
int window_size_callback_id;
    
}

namespace fae_demo
{

void triangle_entity::load(update_args const & args)
{
    shader_ = std::make_unique<fae::shader>();

    mesh_ = std::make_unique<fae::mesh>();
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
    
    window_size_callback_id = args.window_ptr->on_resize.add_callback(window_size_callback);
}

void triangle_entity::unload(update_args const & args)
{
    args.window_ptr->on_resize.remove_callback(window_size_callback_id);
    mesh_.reset();
    shader_.reset();
}

void triangle_entity::render(render_args const & args) const
{
    shader_->bind();
    args.renderer_ptr->draw_mesh(*mesh_.get());
}

}
