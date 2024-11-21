#include "finwindow.h"

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
}