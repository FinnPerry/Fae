#ifndef FAE_APPLICATION_GUARD
#define FAE_APPLICATION_GUARD

#include <string>
#include <memory>

#include "window.hpp"
#include "renderer.hpp"

namespace fae
{

class application
{
public:
    application();

    virtual ~application() = default;

    void run(int width, int height, std::string title);

    virtual void load() {}

    virtual void unload() {}

    virtual void update() {}

    inline window * get_window()
    { return window_.get(); }

    renderer * get_renderer()
    { return renderer_.get(); }

private:
    std::unique_ptr<window> window_;
    std::unique_ptr<renderer> renderer_;
};

}

#endif
