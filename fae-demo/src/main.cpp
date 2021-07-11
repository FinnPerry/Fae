#include <memory>

#include <fae/fae.hpp>

#include "root_entity.hpp"

int main()
{
    fae::log("========== fae demo start ==========");

    fae_demo::root_entity root;
    fae::run(1280, 720, "fae demo", &root);

    fae::log("========== fae demo end ==========");
}
