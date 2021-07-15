# src files
file(GLOB_RECURSE GLAD_SRC ./src/*.c)
add_library(glad ${GLAD_SRC})
target_include_directories(glad PRIVATE ./include/)
