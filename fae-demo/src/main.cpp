#include <fae/application.hpp>
#include <fae/logger.hpp>

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
        fae::logger::instance().log("load");

        count = 0;
    }

    virtual void unload() override
    {
        fae::logger::instance().log("unload");
    }

    virtual void update() override
    {
        ++count;
        if (count == 100)
        {
            count = 0;
            fae::logger::instance().log("update");
        }
    }

private:
    int count;
};

int main()
{
    test_app app{};
    app.run(1280, 720, "test app");
}
