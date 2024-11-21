#pragma once

#include "finwindow.h"

namespace finengine {
	class firstapp {
		public:
			static constexpr int WIDTH = 1280;
			static constexpr int HEIGHT = 720;
			void run();
		private:
			finwindow finwindow{ WIDTH, HEIGHT, "Hello world!" };
	};
}