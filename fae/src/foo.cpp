#include <thread>
#include <chrono>

#include <GLFW/glfw3.h>

#include "foo.hpp"

using namespace std::chrono_literals;

namespace fae
{
void foo()
{
    glfwInit();
    auto window = glfwCreateWindow(1280, 720, "test window", nullptr, nullptr);
    std::this_thread::sleep_for(2s);
    glfwDestroyWindow(window);
    glfwTerminate();
}
}
