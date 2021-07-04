#include <fae/window.hpp>
#include <fae/logger.hpp>

int main()
{
    fae::logger log{"log.txt"};
    log.log("start");
    fae::window win{"Test Window", 1280, 720};
    log.log("created window");
    win.bind();
    while (!win.should_close())
    {
        fae::window::poll_events();
        win.clear();
        win.update();
    }
    log.log("end");
}
