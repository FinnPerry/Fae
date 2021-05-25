#include <chrono>
#include <thread>

#include <fae/window.hpp>

using namespace std::chrono_literals;

int main()
{
    fae::window window{"Test Window", 1280, 720};
    std::this_thread::sleep_for(2s);
}
