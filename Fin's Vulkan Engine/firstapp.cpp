#include "firstapp.h"

namespace finengine {
	void firstapp::run() {
		while (!finwindow.shouldClose()) {
			glfwPollEvents();
		}
	}

}