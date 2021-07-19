#ifndef FAE_RENDERER_GUARD
#define FAE_RENDERER_GUARD

namespace fae
{

class glad_context;
class mesh;

class renderer
{
public:
    renderer(glad_context * context);

    ~renderer() = default;
    
    void init();

    void clear();

    void draw_mesh(mesh const & m);

private:
    glad_context * m_gl_context;
};

}

#endif
