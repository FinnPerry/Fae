#ifndef FAE_RENDERER_GUARD
#define FAE_RENDERER_GUARD

#include "vertex_buffer.hpp"
#include "index_buffer.hpp"

namespace fae
{

class renderer
{
public:
    renderer();

    ~renderer() = default;

    void clear();

    void draw_buffers(vertex_buffer const & verts, index_buffer const & tris);

private:
    unsigned int vao_;
};

}

#endif
