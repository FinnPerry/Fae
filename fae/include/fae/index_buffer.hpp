#ifndef FAE_INDEX_BUFFER_HPP
#define FAE_INDEX_BUFFER_HPP

namespace fae
{

struct triangle
{
    int indices[3];
};

class index_buffer
{
public:
    index_buffer();

    index_buffer(int size, triangle const * data);

    ~index_buffer();

    void bind();

    void set_data(int size, triangle const * data);

    void set_data_partial(int start, int size, triangle const * data);

private:
    unsigned int id_;
    int size_;
};

}

#endif
