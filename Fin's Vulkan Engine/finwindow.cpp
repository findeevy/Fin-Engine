#include "finwindow.hpp"
#include <stdexcept>

namespace finengine {
	finwindow::finwindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name }{
		initWindow();
	}

	finwindow::~finwindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void finwindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void finwindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface.");
		}
	}
}