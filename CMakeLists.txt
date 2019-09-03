cmake_minimum_required(VERSION 3.10)
project(utils)

set(CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Build unit tests" ON)

include(TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)


# 将 <input> 文件里面的内容全部复制到 <output> 文件中；
configure_file(
        "${PROJECT_SOURCE_DIR}/port_config.h.in"
        "${PROJECT_BINARY_DIR}/include/port_config.h"
)

# 设置头文件目录
include_directories(
        "${PROJECT_BINARY_DIR}/include"
        "${PROJECT_SOURCE_DIR}"
)

add_library(utils "" )
target_sources(utils
        PRIVATE
            "${PROJECT_SOURCE_DIR}/crc32c.cpp"
        PUBLIC
            "${PROJECT_SOURCE_DIR}/crc32c.h")



if(BUILD_TESTS)
    enable_testing()
    add_executable(crc32c_test "" test/testharness.h test/testharness.cpp)
    target_sources(crc32c_test
            PRIVATE
                "crc32c_test.cpp")
    target_link_libraries(crc32c_test utils)

endif(BUILD_TESTS)