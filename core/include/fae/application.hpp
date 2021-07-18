#ifndef FAE_APPLICATION_GUARD
#define FAE_APPLICATION_GUARD

namespace fae
{

class window;
class renderer;
class entity;

class application
{
public:
    application(window * win, renderer * ren, entity * root);

    ~application();
    
    void run();

private:
    window * win_;
    renderer * ren_;
    entity * root_;
};

}

#endif
