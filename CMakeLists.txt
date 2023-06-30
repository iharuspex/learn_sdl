cmake_minimum_required(VERSION 3.7)
project(learn_sdl)

set(CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)

find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/imgui-1.89.6
        ${CMAKE_SOURCE_DIR}/imgui-1.89.6/backends
)

file(GLOB SOURCES "*.cpp")

message(STATUS "${SDL2_LIBRARIES}")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
