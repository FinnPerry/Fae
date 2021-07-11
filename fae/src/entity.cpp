#include "entity.hpp"

namespace fae
{

void entity::load_rec(update_args & args)
{
    load(args);
    for (std::unique_ptr<entity> & i : children_)
    {
        i->load_rec(args);
    }
}

void entity::unload_rec(update_args & args)
{
    for (std::unique_ptr<entity> & i : children_)
    {
        i->unload_rec(args);
    }
    unload(args);
}

void entity::update_rec(update_args & args)
{
    update(args);
    for (std::unique_ptr<entity> & i : children_)
    {
        i->update_rec(args);
    }
}

void entity::render_rec(render_args & args) const
{
    render(args);
    for (std::unique_ptr<entity> const & i : children_)
    {
        i->render_rec(args);
    }
}

}
