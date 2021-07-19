#include "entity.hpp"

namespace fae
{

entity::entity():
    m_parent{nullptr},
    m_children{}
{
}

void entity::set_parent(entity * parent)
{
    if (m_parent)
    {
        auto i{std::find(m_parent->m_children.begin(), m_parent->m_children.end(), this)};
        m_parent->m_children.erase(i);
    }
    m_parent = parent;
    if (m_parent)
    {
        m_parent->m_children.push_back(this);
    }
}

void entity::load_rec(update_args const & args)
{
    load(args);
    for (auto i : m_children)
    {
        i->load_rec(args);
    }
}

void entity::unload_rec(update_args const & args)
{
    for (auto i : m_children)
    {
        i->unload_rec(args);
    }
    unload(args);
}

void entity::update_rec(update_args const & args)
{
    update(args);
    for (auto i : m_children)
    {
        i->update_rec(args);
    }
}

void entity::render_rec(render_args const & args) const
{
    render(args);
    for (auto i : m_children)
    {
        i->render_rec(args);
    }
}

}
