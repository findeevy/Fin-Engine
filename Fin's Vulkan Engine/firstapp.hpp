#pragma once

#include "finwindow.hpp"
#include "finpipeline.hpp"

namespace finengine {
	class firstapp {
	public:
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;
		void run();
	private:
		finwindow finWindow{ WIDTH, HEIGHT, "Hello world!" };
		findevice finDevice{ finWindow };
		//Make sure that Visual Studio is set to the proper working directory, can cause crashes if compiled without proper setting.
		finpipeline finPipeline{ 
			finDevice, 
			"shaders/basicshader.vert.spv", 
			"shaders/basicshader.frag.spv", 
			finpipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
		};
	};
}