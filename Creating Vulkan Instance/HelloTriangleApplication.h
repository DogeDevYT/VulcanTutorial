//
// Created by ragha on 12/15/2025.
//

#ifndef VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H
#define VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H

#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;


class HelloTriangleApplication {
public:
    void run();
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();

    //add reference to our glfw dinwo
    GLFWwindow* window;
    //add handle to our vulkan instance
    VkInstance instance;
};


#endif //VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H