#ifndef FAE_GLAD_CONTEXT_GUARD
#define FAE_GLAD_CONTEXT_GUARD

namespace fae
{

enum gl_enum
{
    gl_array_buffer,
    gl_element_array_buffer,
    gl_float,
    gl_dynamic_draw
};

class glad_context
{
public:
    glad_context() = default;

    ~glad_context() = default;

    void gen_vertex_arrays(int n, unsigned int * arrays);

    void gen_buffers(int n, unsigned int * buffers);

    void bind_buffer(gl_enum target, unsigned int buffer);

    void vertex_attrib_pointer(unsigned int index, int size, gl_enum type, bool normalized, int stride, void const * pointer);

    void enable_vertex_attrib_array(unsigned int index);

    void delete_buffers(int n, unsigned int const * buffers);

    void delete_vertex_arrays(int n, unsigned int const * arrays);

    void bind_vertex_array(unsigned int array);

    void buffer_data(gl_enum target, long size, void const * data, gl_enum usage);

    void buffer_sub_data(gl_enum target, long offset, long size, void const * data);

private:
    int convert_enum(gl_enum e);
};

}

#endif
