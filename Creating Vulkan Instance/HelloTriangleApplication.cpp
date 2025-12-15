//
// Created by ragha on 12/15/2025.
//

#include "HelloTriangleApplication.h"

void HelloTriangleApplication::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void HelloTriangleApplication::initVulkan()
{
    //intialize Vulkan library by creating instance
    createInstance();
}

void HelloTriangleApplication::mainLoop()
{
    //keep the application open until window closed or error
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void HelloTriangleApplication::cleanup()
{
    //VkInstance should only be destroyed right before program exit
    vkDestroyInstance(instance, nullptr);

    //cleanup resources by destroying window and terminating GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}

void HelloTriangleApplication::createInstance()
{
    //Initialize struct to store information about application
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //tell Vulkan which global extensions and validation layers
    // we want to use
    VkInstanceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    //create extension to interface with window system (using GLFW)
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    //leave global validation layers as blank
    createInfo.enabledLayerCount = 0;

    //iterate through supported vulkan extensions and print them out

    uint32_t extension_count = 0;
    //allocate space to store our extensions
    std::vector<VkExtensionProperties> extensions;
    vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, extensions.data());

    std::cout << "Availible extensions: \n";

    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << "\n";
    }

    //create vulkan instance and check to make sure its success
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Vulkan Instance!");
    }

}

void HelloTriangleApplication::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //for spcifying vulkan specificlally
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //disable resizing windows

    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Triangle", nullptr, nullptr);
}
