cmake_minimum_required(VERSION 3.5.0)
project(lighting VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")


add_executable(lighting ${SOURCES})

target_include_directories(lighting PRIVATE /Users/jaymalone/programming/cpp-libs/raylib-5.0_macos/include )
target_include_directories(lighting PRIVATE /Users/jaymalone/programming/cpp-libs/FastNoise2-master/include)


target_link_directories(lighting PRIVATE /Users/jaymalone/programming/cpp-libs/raylib-5.0_macos/lib)
target_link_directories(lighting PRIVATE /Users/jaymalone/programming/cpp-libs/FastNoise2-master/build/lib)


target_link_libraries(lighting raylib FastNoise)