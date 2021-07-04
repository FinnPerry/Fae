#include <fae/window.hpp>
#include <fae/logger.hpp>

int main()
{
    fae::logger log{"log.txt"};
    log << "start\n";
    fae::window win{"Test Window", 1280, 720};
    log << "created window " << 1280 << "*" << 720 << '\n';
    win.bind();
    while (!win.should_close())
    {
        fae::window::poll_events();
        win.clear();
        win.update();
    }
    log << "end\n";
}
