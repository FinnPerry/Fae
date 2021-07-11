#include "entity.hpp"

namespace fae
{

void entity::load_rec()
{
    load();
    for (std::unique_ptr<entity> & i : children_)
    {
        i->load_rec();
    }
}

void entity::unload_rec()
{
    for (std::unique_ptr<entity> & i : children_)
    {
        i->unload_rec();
    }
    unload();
}

void entity::update_rec()
{
    update();
    for (std::unique_ptr<entity> & i : children_)
    {
        i->update_rec();
    }
}

void entity::render_rec() const
{
    render();
    for (std::unique_ptr<entity> const & i : children_)
    {
        i->render_rec();
    }
}

}
