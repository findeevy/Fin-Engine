#include "firstapp.hpp"

namespace finengine {
	void firstapp::run() {
		while (!finWindow.shouldClose()) {
			glfwPollEvents();
		}
	}

}