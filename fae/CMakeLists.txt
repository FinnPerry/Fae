file(GLOB FAE_SRC ./src/*.cpp)
add_library(fae ${FAE_SRC})
target_include_directories(fae PRIVATE ./include/fae/)
