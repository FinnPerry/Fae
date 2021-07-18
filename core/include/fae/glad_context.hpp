#ifndef FAE_GLAD_CONTEXT_GUARD
#define FAE_GLAD_CONTEXT_GUARD

namespace fae
{

class glad_context
{
public:
    using debug_proc = void(*)(int, int, unsigned int, int, int, char const *, void const *);

    glad_context() = default;

    ~glad_context() = default;

    static int glenum_array_buffer();

    static int glenum_float();

    static int glenum_element_array_buffer();

    static int glenum_dynamic_draw();

    void gen_vertex_arrays(int n, unsigned int * arrays);

    void gen_buffers(int n, unsigned int * buffers);

    void bind_buffer(int target, unsigned int buffer);

    void vertex_attrib_pointer(unsigned int index, int size, int type, bool normalized, int stride, void const * pointer);

    void enable_vertex_attrib_array(unsigned int index);

    void delete_buffers(int n, unsigned int const * buffers);

    void delete_vertex_arrays(int n, unsigned int const * arrays);

    void bind_vertex_array(unsigned int array);

    void buffer_data(int target, long size, void const * data, int usage);

    void buffer_sub_data(int target, long offset, long size, void const * data);
    
    void debug_message_callback(debug_proc, void const * user_param);
};

}

#endif
