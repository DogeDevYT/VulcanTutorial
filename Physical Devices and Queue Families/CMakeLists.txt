cmake_minimum_required(VERSION 3.10)
project(VulkanTutorial)

include(FetchContent)
FETCHCONTENT_DECLARE(GLFW GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.4)
FETCHCONTENT_MAKEAVAILABLE(GLFW)

find_package(Vulkan REQUIRED)
if (Vulkan_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    link_directories(${Vulkan_LIBRARY_DIRS})
endif()

include_directories(
        "/glm-1.0.2"
)

set(CMAKE_CXX_STANDARD 20)

add_executable(VulkanTutorial main.cpp
        HelloTriangleApplication.cpp
        HelloTriangleApplication.h)

target_link_libraries(VulkanTutorial glfw ${Vulkan_LIBRARIES})
