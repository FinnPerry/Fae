#ifndef FAE_GLAD_CONTEXT_GUARD
#define FAE_GLAD_CONTEXT_GUARD

namespace fae
{

class glad_context
{
public:
    using debug_proc = void(*)(int source, int type, unsigned int id, int severity, int length, char const * message, void const * user_arg);

    glad_context() = default;

    ~glad_context() = default;

    static int gldef_array_buffer();

    static int gldef_float();

    static int gldef_element_array_buffer();

    static int gldef_dynamic_draw();

    static int gldef_debug_severity_notification();

    static int gldef_depth_test();

    static int gldef_less();

    static int gldef_color_buffer_bit();

    static int gldef_depth_buffer_bit();

    static int gldef_triangles();

    static int gldef_unsigned_int();
    
    static int gldef_vertex_shader();

    static int gldef_fragment_shader();
    
    static int gldef_version();

    static int gldef_renderer();
    
    void load_gl_loader(void(*load_proc)(char const *));

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

    void debug_message_callback(debug_proc callback, void const * user_param);

    void enable(int cap);

    void depth_func(int func);

    void clear(int mask);

    void draw_elements(int mode, int count, int type, void const * indices);

    unsigned int create_shader(int type);

    void shader_source(unsigned int shader, int count, char const ** string, int const * length);

    void compile_shader(unsigned int shader);

    unsigned int create_program();

    void attach_shader(unsigned int program, unsigned int shader);

    void link_program(unsigned int program);

    void delete_shader(unsigned int shader);

    void delete_program(unsigned int program);

    void use_program(unsigned int program);
    
    char const * get_string(int name);
    
    void viewport(int x, int y, int width, int height);
};

}

#endif
