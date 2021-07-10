#ifndef FAE_SHADER_GUARD
#define FAE_SHADER_GUARD

namespace fae
{

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
    shader(char const * vert = nullptr, char const * frag = nullptr);

    ~shader();

    void bind();

private:
    unsigned int id_;
};

}

#endif
