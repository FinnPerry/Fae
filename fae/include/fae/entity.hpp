#ifndef FAE_ENTITY_GUARD
#define FAE_ENTITY_GUARD

#include <memory>
#include <vector>

namespace fae
{

class entity
{
public:
    entity() = default;

    virtual ~entity() = default;

    virtual void load() {}

    virtual void unload() {}

    virtual void update() {}

    virtual void render() const {}

    inline std::vector<std::unique_ptr<entity>> const get_children() const
    { return children_; }

    void load_rec();

    void unload_rec();

    void update_rec();

    void render_rec() const;

private:
    std::vector<std::unique_ptr<entity>> children_;
};

}

#endif
