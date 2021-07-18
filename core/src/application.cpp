#include "application.hpp"

#include <glad/glad.h>

#include "entity.hpp"
#include "logger.hpp"
#include "renderer.hpp"
#include "window.hpp"

namespace fae
{

application::application(window * win, renderer * ren, entity * root):
    win_{win},
    ren_{ren},
    root_{root}
{
}

application::~application()
{
}

void application::run()
{
    win_->open();
    win_->bind();
    ren_->init();

    entity::update_args u_args
    {
        win_,
        root_
    };

    entity::render_args r_args
    {
        ren_
    };

    root_->load_rec(u_args);
    while (!win_->should_close())
    {
        win_->update();
        root_->update_rec(u_args);

        ren_->clear();
        root_->render_rec(r_args);
        win_->update_screen();
    }
    root_->unload_rec(u_args);

    win_->close();
}

}
