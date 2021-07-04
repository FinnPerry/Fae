#include <fae/window.hpp>
#include <fae/logger.hpp>

int main()
{
    fae::window win{"Test Window", 1280, 720};
    win.bind();
    while (!win.should_close())
    {
        fae::window::poll_events();
        win.clear();
        win.update();
    }
}
