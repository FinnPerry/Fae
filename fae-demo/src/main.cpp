#include <fae/window.hpp>

int main()
{
    fae::window win{"Test Window", 1280, 720};
    while (!win.should_close())
    {
        fae::window::poll_events();
    }
}
