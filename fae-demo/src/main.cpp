#include <memory>

#include <fae/application.hpp>
#include <fae/index_buffer.hpp>
#include <fae/logger.hpp>
#include <fae/shader.hpp>
#include <fae/vertex_buffer.hpp>

char const * vert_shader
{
    "#version 430\n"
    "in vec3 position;\n"
    "void main() {\n"
    "   gl_Position = vec4(position, 1.0f);\n"
    "}"
};

char const * frag_shader
{
    "#version 430\n"
    "out vec4 color;\n"
    "void main() {\n"
    "   color = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
    "}"
};

class test_app : public fae::application
{
public:
    test_app():
        fae::application()
    {
    }

    virtual ~test_app() = default;

    virtual void load() override
    {
        shader = std::make_unique<fae::shader>(vert_shader, frag_shader);

        fae::vertex vert_data[3]
        {
            {0.0f, 0.5f},
            {0.5f, -0.5f},
            {-0.5f, -0.5f}
        };
        vertices = std::make_unique<fae::vertex_buffer>(3, vert_data);

        fae::triangle tri_data[1]
        {
            {0, 1, 2}
        };
        indices = std::make_unique<fae::index_buffer>(1, tri_data);
    }

    virtual void unload() override
    {
        indices.reset();
        vertices.reset();
        shader.reset();
    }

    virtual void update() override
    {
        shader->bind();
        renderer_->draw_buffers(*vertices.get(), *indices.get());
    }

private:
    std::unique_ptr<fae::shader> shader;
    std::unique_ptr<fae::vertex_buffer> vertices;
    std::unique_ptr<fae::index_buffer> indices;
};

int main()
{
    test_app app{};
    app.run(1280, 720, "fae demo");
}
