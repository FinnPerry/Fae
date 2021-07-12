#include <memory>

#include <fae/fae.hpp>

#include "triangle_entity.hpp"

int main()
{
    fae::log("========== fae demo start ==========");

    // create entities
    fae::entity root;
    fae_demo::triangle_entity triangle;
    triangle.set_parent(&root);

    // run the app
    fae::run(1280, 720, "fae demo", &root);

    fae::log("========== fae demo end ==========");
}
