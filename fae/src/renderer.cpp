#include "renderer.hpp"

#include <glad/glad.h>

namespace fae
{

renderer::renderer()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

}
