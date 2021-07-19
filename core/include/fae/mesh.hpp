#ifndef FAE_MESH_GUARD
#define FAE_MESH_GUARD

namespace fae
{

class glad_context;

struct vector3
{
    float x;
    float y;
    float z;
};

struct vertex
{
    vector3 position;
};

struct triangle
{
    unsigned int indices[3];
};

class mesh
{
public:
    mesh(glad_context * context);

    ~mesh();

    void bind() const;

    void set_verts(vertex const * data, int size);

    void set_verts_partial(vertex const * data, int start, int size);

    void set_tris(triangle const * data, int size);

    void set_tris_partial(triangle const * data, int start, int size);

    inline int get_vb_size() const { return m_vb_size; }

    inline int get_ib_size() const { return m_ib_size; }

private:
    glad_context * m_gl_context;

    unsigned int m_vao;

    unsigned int m_vbo;
    int m_vb_size;

    unsigned int m_ibo;
    int m_ib_size;
};

}

#endif
