cmake_minimum_required(VERSION 3.14)
project(CompressorTool LANGUAGES CXX)

add_library(compressor
    source/Compressor.cpp
)

target_include_directories(compressor PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>
)


if (MSVC)
    target_compile_options(compressor PRIVATE /wd4244)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(compressor PRIVATE -Wno-narrowing)
endif()


add_executable(example example/example.cpp)
target_link_libraries(example PRIVATE compressor)

add_custom_target(run_example
    COMMAND example   
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS example
    COMMENT "
    Running example executable...
    "
)