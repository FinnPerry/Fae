#ifndef FAE_SHADER_GUARD
#define FAE_SHADER_GUARD

namespace fae
{

class shader
{
public:
    shader(char const * vert, char const * frag);

    ~shader();

    void bind();

private:
    unsigned int id_;
};

}

#endif
