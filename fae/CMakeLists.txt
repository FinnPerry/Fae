# src files
file(GLOB_RECURSE FAE_SRC ./src/*.cpp ../external/glad/src/*.c)
add_library(fae ${FAE_SRC})
target_include_directories(fae PRIVATE ./include/fae/)

# glad
target_include_directories(fae PRIVATE ../external/glad/include/)

# glfw
if (WIN32)
    target_include_directories(fae PRIVATE "C:/Program Files (x86)/GLFW/include/")
    target_link_libraries(fae PRIVATE "C:/Program Files (x86)/GLFW/lib/glfw3.lib")
else()
    find_package(glfw3 REQUIRED)
    target_link_libraries(fae PRIVATE glfw3 dl pthread)
endif()
