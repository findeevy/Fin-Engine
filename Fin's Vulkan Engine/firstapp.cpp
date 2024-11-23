#include "firstapp.hpp"

namespace finengine {
	void firstapp::run() {
		while (!finwindow.shouldClose()) {
			glfwPollEvents();
		}
	}

}