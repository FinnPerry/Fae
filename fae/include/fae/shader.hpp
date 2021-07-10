#ifndef FAE_SHADER_GUARD
#define FAE_SHADER_GUARD

namespace fae
{

class shader
{
public:
    // vert and frag shader strings must contain function with the following signatures:
    // vec4 vert()
    // vec4 frag()
    shader(char const * vert, char const * frag);

    ~shader();

    void bind();

private:
    unsigned int id_;
};

}

#endif
