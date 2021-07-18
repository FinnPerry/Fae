#ifndef FAE_RENDERER_GUARD
#define FAE_RENDERER_GUARD

#include "mesh.hpp"

namespace fae
{

class renderer
{
public:
    renderer() = default;

    ~renderer() = default;
    
    void init();

    void clear();

    void draw_mesh(mesh const & m);
};

}

#endif
