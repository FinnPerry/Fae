file(GLOB_RECURSE FAE_TESTS_SRC ./src/*.cpp)
add_executable(fae-tests ${FAE_TESTS_SRC})
target_include_directories(fae-tests PRIVATE ./include/fae-tests/)

target_include_directories(fae-tests PRIVATE ../fae/include/)
target_include_directories(fae-tests PRIVATE ../external/cppunit/)

target_link_libraries(fae-tests PRIVATE fae)
