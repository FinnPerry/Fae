#include <memory>

#include <fae/fae.hpp>

#include "triangle_entity.hpp"

int main()
{
    fae::log("========== fae demo start ==========");

    // create objects
    fae::window win{1280, 720, "fae demo"};
    fae::glad_context context;
    fae::renderer ren{&context};

    // create entities
    fae::entity root;
    fae_demo::triangle_entity triangle{&context};
    triangle.set_parent(&root);

    // run the app
    fae::application app{&win, &ren, &root};
    app.run();

    fae::log("========== fae demo end ==========");
}
