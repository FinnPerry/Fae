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
};

int main()
{
    fae::logger::instance().log("start");

    test_app app{};
    app.run(1280, 720, "test app");

    fae::logger::instance().log("end");
}
