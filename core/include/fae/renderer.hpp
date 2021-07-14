#ifndef FAE_RENDERER_GUARD
#define FAE_RENDERER_GUARD

#include "mesh.hpp"

namespace fae
{

class renderer
{
public:
    renderer();

    ~renderer() = default;

    void clear();

    void draw_mesh(mesh const & m);

private:
    unsigned int vao_;
};

}

#endif
