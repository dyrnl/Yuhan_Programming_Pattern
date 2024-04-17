#include "stdafx.h"

void errorCallback(int error, const char* description)
{
    cerr << "GLFW Error : " << description <<  endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        (1.0f, 0.0f, 0.0f, 1.0f);
    }
}

mObjectTest* obj;

int initailize()
{
    return 0;
}

int realese()
{
    return 0;
}

int update()
{
    obj->print();
    return 0;
}

int render()
{
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    return 0;
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1280, 768, "Hi", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    initailize();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        update();
        render();
        glfwSwapBuffers(window);
    }

    realese();

    glfwTerminate();
    return 0;
}