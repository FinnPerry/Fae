#ifndef FAE_INDEX_BUFFER_GUARD
#define FAE_INDEX_BUFFER_GUARD

namespace fae
{

struct triangle
{
    unsigned int indices[3];
};

class index_buffer
{
public:
    index_buffer();

    index_buffer(int size, triangle const * data);

    ~index_buffer();

    void bind() const;

    void set_data(int size, triangle const * data);

    void set_data_partial(int start, int size, triangle const * data);

    inline int size() const { return size_; }

private:
    unsigned int id_;
    int size_;
};

}

#endif
