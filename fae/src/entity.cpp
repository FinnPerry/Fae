#include "entity.hpp"

#include <algorithm>

namespace fae
{

entity::entity():
    parent_{nullptr},
    children_{}
{
}

void entity::set_parent(entity * parent)
{
    if (parent_)
    {
        auto i{std::find(parent_->children_.begin(), parent_->children_.end(), this)};
        parent_->children_.erase(i);
    }
    parent_ = parent;
    if (parent_)
    {
        parent_->children_.push_back(this);
    }
}

void entity::load_rec(update_args const & args)
{
    load(args);
    for (auto i : children_)
    {
        i->load_rec(args);
    }
}

void entity::unload_rec(update_args const & args)
{
    for (auto i : children_)
    {
        i->unload_rec(args);
    }
    unload(args);
}

void entity::update_rec(update_args const & args)
{
    update(args);
    for (auto i : children_)
    {
        i->update_rec(args);
    }
}

void entity::render_rec(render_args const & args) const
{
    render(args);
    for (auto i : children_)
    {
        i->render_rec(args);
    }
}

}
