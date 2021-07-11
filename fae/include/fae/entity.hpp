#ifndef FAE_ENTITY_GUARD
#define FAE_ENTITY_GUARD

#include <memory>
#include <vector>

namespace fae
{

class window;
class renderer;

class entity
{
public:
    struct update_args
    {
        window * window_ptr;
    };

    struct render_args
    {
        renderer * renderer_ptr;
    };

    entity() = default;

    virtual ~entity() = default;

    virtual void load(update_args & args) {}

    virtual void unload(update_args & args) {}

    virtual void update(update_args & args) {}

    virtual void render(render_args & args) const {}

    inline std::vector<std::unique_ptr<entity>> const get_children() const
    { return children_; }

    void load_rec(update_args & args);

    void unload_rec(update_args & args);

    void update_rec(update_args & args);

    void render_rec(render_args & args) const;

private:
    std::vector<std::unique_ptr<entity>> children_;
};

}

#endif
