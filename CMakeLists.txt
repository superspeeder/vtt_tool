cmake_minimum_required(VERSION 3.26)
project(vtt_tool)

find_package(glfw3 CONFIG REQUIRED)
find_package(glbinding CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(vtt_tool src/vtt/vtt.cpp src/vtt/vtt.hpp)
target_include_directories(vtt_tool PRIVATE src/)
target_link_libraries(vtt_tool glfw glbinding::glbinding spdlog::spdlog imgui::imgui glm::glm)