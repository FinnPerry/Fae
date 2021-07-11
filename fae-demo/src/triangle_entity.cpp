#include "triangle_entity.hpp"

namespace fae_demo
{

void triangle_entity::load(update_args & args)
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
}

void triangle_entity::unload(update_args & args)
{
    mesh_.reset();
    shader_.reset();
}

void triangle_entity::render(render_args & args) const
{
    shader_->bind();
    args.renderer_ptr->draw_mesh(*mesh_.get());
}

}
