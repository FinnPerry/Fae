file(GLOB_RECURSE FAE_SRC ./src/*.cpp ../external/glad/src/*.c)
add_library(fae ${FAE_SRC})

target_include_directories(fae PRIVATE ./include/fae/)
target_include_directories(fae PRIVATE ../external/glad/include/)

find_package(glfw3 REQUIRED)
target_link_libraries(fae PRIVATE glfw3 dl pthread)
