#include "application.hpp"

#include "entity.hpp"
#include "logger.hpp"
#include "renderer.hpp"
#include "window.hpp"

namespace fae
{

application::application(window * win, renderer * ren, entity * root):
    m_win{win},
    m_ren{ren},
    m_root{root}
{
}

application::~application()
{
}

void application::run()
{
    m_win->open();
    m_win->bind();
    m_ren->init();

    entity::update_args u_args
    {
        m_win,
        m_root
    };

    entity::render_args r_args
    {
        m_ren
    };

    m_root->load_rec(u_args);
    while (!m_win->should_close())
    {
        m_win->update();
        m_root->update_rec(u_args);

        m_ren->clear();
        m_root->render_rec(r_args);
        m_win->update_screen();
    }
    m_root->unload_rec(u_args);

    m_win->close();
}

}
