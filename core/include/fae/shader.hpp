#ifndef FAE_SHADER_GUARD
#define FAE_SHADER_GUARD

namespace fae
{

class glad_context;

class shader
{
public:
    // vertex shader must provide a definition to the following function:
    // vec4 vert();
    // this function should return the final vertex position
    // a vec3 position variable is provided containing the mesh vertex position
    // fragment shader must provide a definition to the following function:
    // vec4 frag();
    // this function should return the final fragment color
    shader(glad_context * context, char const * vert = nullptr, char const * frag = nullptr);

    ~shader();

    void bind();

private:
    glad_context * m_gl_context;
    unsigned int m_id;
};

}

#endif
