#include "WindowManager.h"
#include <stdio.h>
namespace Engine
{
	WindowManager::WindowManager(int width, int height, const char* name)
	{
		//Init GLFW
		glfwInit();
		// uncomment for (borderless) fullscreen mode 
		//GLFWmonitor* primary = glfwGetPrimaryMonitor(); 
		//const GLFWvidmode* mode = glfwGetVideoMode(primary);
		//
		//glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		//glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		//glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		//glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
		//
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Use core profile
		//Create window
		//GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "OpenGLgamin", primary, NULL);
		m_window = glfwCreateWindow(width, height, name, NULL, NULL);
	
		if (m_window == NULL)
		{
			printf("Failed to create GLFW window \n");
			glfwTerminate();
			//return -1;
		}
		glfwMakeContextCurrent(m_window);

		// set callbacks
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		glfwSwapInterval(0);
	}
	void WindowManager::Terminate()
	{
		glfwTerminate();
		glfwDestroyWindow(m_window);
	}

	// Callbacks
	void WindowManager::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

		glViewport(0, 0, width, height);
		glfwSetWindowAspectRatio(window, width, height);
	}
}
