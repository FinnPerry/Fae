#ifndef FAE_DEMO_TRIANGLE_ENTITY_GUARD
#define FAE_DEMO_TRIANGLE_ENTITY_GUARD

#include <fae/fae.hpp>

namespace fae_demo
{

class triangle_entity : public fae::entity
{
public:
    triangle_entity() = default;

    virtual ~triangle_entity() = default;

protected:
    virtual void load(update_args & args) override;

    virtual void unload(update_args & args) override;

    virtual void render(render_args & args) const override;

private:
    std::unique_ptr<fae::shader> shader_;
    std::unique_ptr<fae::mesh> mesh_;
};

}

#endif
