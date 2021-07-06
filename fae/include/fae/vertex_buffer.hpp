#ifndef FAE_VERTEX_BUFFER_GUARD
#define FAE_VERTEX_BUFFER_GUARD

namespace fae
{

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

class vertex_buffer
{
public:
    vertex_buffer();

    vertex_buffer(int size, vertex const * data);

    ~vertex_buffer();

    void bind();

    void set_data(int size, vertex const * data);

    void set_data_partial(int start, int size, vertex const * data);

private:
    unsigned int id_;
    int size_;
};

}

#endif
