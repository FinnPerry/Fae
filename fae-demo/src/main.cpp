#include <fae/window.hpp>
#include <fae/logger.hpp>

int main()
{
    fae::logger::instance().log("start");
    fae::window win{"Test Window", 1280, 720};
    fae::logger::instance().log("created window");
    win.bind();
    while (!win.should_close())
    {
        fae::window::poll_events();
        win.clear();
        win.update();
    }
    fae::logger::instance().log("end");
}
