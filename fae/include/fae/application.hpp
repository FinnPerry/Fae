#ifndef FAE_APPLICATION_GUARD
#define FAE_APPLICATION_GUARD

#include <string>
#include <memory>

#include "window.hpp"

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

private:
    std::unique_ptr<window> window_;
};

}

#endif
