file(GLOB_RECURSE FAE_DEMO_SRC ./src/*.cpp)
add_executable(fae-demo ${FAE_DEMO_SRC})
target_include_directories(fae-demo PRIVATE ./include/fae-demo/)

target_include_directories(fae-demo PRIVATE ../core/include/)

target_link_libraries(fae-demo PRIVATE fae-core)
