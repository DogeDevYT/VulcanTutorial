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
#include <optional>

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
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);


    //add reference to our glfw dinwo
    GLFWwindow* window;
    //add handle to our vulkan instance
    VkInstance instance;
    //add handle for the debug messenger instance
    VkDebugUtilsMessengerEXT debugMessenger;
    //Add a handle to our physical device - implicitly destroyed when VkInstance is destroyed
    // therefore we dont need to do anything to cleanup()
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};


#endif //VULKANTUTORIAL_HELLOTRIANGLEAPPLICATION_H