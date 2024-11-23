#pragma once
#include "findevice.hpp"
#include <string>
#include <vector>

namespace finengine {

	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class finpipeline {
	public:
		finpipeline(findevice &device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		~finpipeline() {}

		finpipeline(const finpipeline&) = delete;
		void operator=(const finpipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
	
	private:
		static std::vector<char> readFile(const std::string& filepath);
		
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
		
		findevice& FinDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}