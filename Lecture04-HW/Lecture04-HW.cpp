#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

bool isRightMouseDown = false;
bool isLeftMouseDown = false;
bool isDraggingRight = false;
bool isDraggingLeft = false;
float originalColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; // 기본 색상을 저장할 배열

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW 오류: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			isRightMouseDown = true;
			glGetFloatv(GL_COLOR_CLEAR_VALUE, originalColor); // 현재 색상을 저장
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨간색 설정
		}
		else if (action == GLFW_RELEASE)
		{
			isRightMouseDown = false;
			isDraggingRight = false;
			glClearColor(originalColor[0], originalColor[1], originalColor[2], originalColor[3]); // 저장된 색상으로 복구
		}
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			isLeftMouseDown = true;
			glGetFloatv(GL_COLOR_CLEAR_VALUE, originalColor); // 현재 색상을 저장
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색 설정
		}
		else if (action == GLFW_RELEASE)
		{
			isLeftMouseDown = false;
			isDraggingLeft = false;
			glClearColor(originalColor[0], originalColor[1], originalColor[2], originalColor[3]); // 저장된 색상으로 복구
		}
	}
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	static double lastX = xpos;
	static double lastY = ypos;

	if (isRightMouseDown)
	{
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{
			isDraggingRight = true;
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파란색 설정
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
		{
			isDraggingRight = false;
			glClearColor(originalColor[0], originalColor[1], originalColor[2], originalColor[3]); // 저장된 색상으로 복구
		}
	}
	else if (isLeftMouseDown)
	{
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			isDraggingLeft = true;
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색 설정
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			isDraggingLeft = false;
			glClearColor(originalColor[0], originalColor[1], originalColor[2], originalColor[3]); // 저장된 색상으로 복구
		}
	}
}

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetCursorPosCallback(window, cursorPosCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT); // 화면을 지우기 전에 호출되어야 합니다.
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}