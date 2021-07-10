#include <memory>

#include <fae/application.hpp>
#include <fae/event.hpp>
#include <fae/logger.hpp>
#include <fae/mesh.hpp>
#include <fae/shader.hpp>

namespace
{

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
        shader = std::make_unique<fae::shader>();

        mesh = std::make_unique<fae::mesh>();
        fae::vertex vert_data[3]
        {
            {0.0f, 0.5f},
            {0.5f, -0.5f},
            {-0.5f, -0.5f}
        };
        mesh->set_verts(vert_data, 3);
        fae::triangle tri_data[1]
        {
            {0, 1, 2}
        };
        mesh->set_tris(tri_data, 1);

        fae::log("test", "log", "message");
        fae::log(fae::log_type::warning, "test", "log", "warning");
        fae::log(fae::log_type::error, "test", "log", "error");

        get_window()->on_resize.add_callback([](int width, int height)->void
        {
            fae::log("window resize", width, height);
        });
    }

    virtual void unload() override
    {
        mesh.reset();
        shader.reset();
    }

    virtual void update() override
    {
        shader->bind();
        get_renderer()->draw_mesh(*mesh.get());
    }

private:
    std::unique_ptr<fae::shader> shader;
    std::unique_ptr<fae::mesh> mesh;
};

}

int main()
{
    fae::log("========== fae demo start ==========");

    test_app app{};
    app.run(1280, 720, "fae demo");

    fae::log("========== fae demo end ==========");
}
