#include "renderer.hpp"

#include <glad/glad.h>

namespace fae
{

void renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

}
