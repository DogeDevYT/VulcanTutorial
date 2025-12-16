//
// Created by ragha on 12/15/2025.
//

#ifndef VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H
#define VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H

#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif


class HelloTriangleApplication {
public:
    void run();
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();

    //add reference to our glfw dinwo
    GLFWwindow* window;
    //add handle to our vulkan instance
    VkInstance instance;
    //add handle for the debug messenger instance
    VkDebugUtilsMessengerEXT debugMessenger;
};


#endif //VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H