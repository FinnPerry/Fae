#include <memory>

#include <fae/fae.hpp>

namespace
{

class root_entity : public fae::entity
{
public:
    virtual void load(update_args & args) override
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

    virtual void unload(update_args & args) override
    {
        mesh_.reset();
        shader_.reset();
    }

    virtual void update(update_args & args) override
    {
    }

    virtual void render(render_args & args) const override
    {
        shader_->bind();
        args.renderer_ptr->draw_mesh(*mesh_.get());
    }

private:
    std::unique_ptr<fae::shader> shader_;
    std::unique_ptr<fae::mesh> mesh_;
};

}

int main()
{
    fae::log("========== fae demo start ==========");

    root_entity root;
    fae::run(1280, 720, "fae demo", &root);

    fae::log("========== fae demo end ==========");
}
