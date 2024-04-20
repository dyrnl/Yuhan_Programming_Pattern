#include <iostream>
#include <vector>
#include "stdafx.h"
#include <GLFW/glfw3.h>
#include "mObject.h"
#include "mList.h"

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}


mList<mObject*> list;

int initialize()
{

	//mObject* temp[4];
	//temp[0] = new Star();
	//temp[1] = new Star();
	//temp[2] = new Star();
	//temp[3] = new Star();

	//list.push_back(temp[0]);
	//list.push_back(temp[1]);
	//list.push_back(temp[2]);
	//list.push_back(temp[3]);


	return 0;
}
int release()
{

	return 0;
}

int update()
{

	return 0;
}

int render()
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 10; i++)
	{
		list[i] = new Star();
		mObject* a = list[i];
		a->render();
	}

	return 0;
}


int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}