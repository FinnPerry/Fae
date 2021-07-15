# src files
file(GLOB_RECURSE FAE_CORE_SRC ./src/*.cpp)
add_library(fae-core ${FAE_CORE_SRC})
target_include_directories(fae-core PRIVATE ./include/fae/)

# stl pch
target_precompile_headers(fae-core PRIVATE
    <algorithm>
    <cstddef>
    <fstream>
    <string>
    <sstream>
    <memory>
    <chrono>
)

# glad
target_include_directories(fae-core PRIVATE ../external/glad/include/)
target_link_libraries(fae-core PRIVATE glad)

# glfw
if (WIN32)
    target_include_directories(fae-core PRIVATE "C:/Program Files (x86)/GLFW/include/")
    target_link_libraries(fae-core PRIVATE "C:/Program Files (x86)/GLFW/lib/glfw3.lib")
else()
    find_package(glfw3 REQUIRED)
    target_link_libraries(fae-core PRIVATE glfw3 dl pthread)
endif()
