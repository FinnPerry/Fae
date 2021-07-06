#include <memory>

#include <fae/application.hpp>
#include <fae/logger.hpp>
#include <fae/mesh.hpp>
#include <fae/shader.hpp>

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

        mesh = std::make_unique<fae::mesh>();
        fae::vertex vert_data[3]
        {
            {0.0f, 0.5f},
            {0.5f, -0.5f},
            {-0.5f, -0.5f}
        };
        mesh->set_vertices(vert_data, 3);
        fae::triangle tri_data[1]
        {
            {0, 1, 2}
        };
        mesh->set_triangles(tri_data, 1);
    }

    virtual void unload() override
    {
        mesh.reset();
        shader.reset();
    }

    virtual void update() override
    {
        shader->bind();
        renderer_->draw_mesh(*mesh.get());
    }

private:
    std::unique_ptr<fae::shader> shader;
    std::unique_ptr<fae::mesh> mesh;
};

int main()
{
    test_app app{};
    app.run(1280, 720, "fae demo");
}
