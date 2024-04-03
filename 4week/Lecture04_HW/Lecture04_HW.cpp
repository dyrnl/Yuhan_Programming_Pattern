// ������ ������Ʈ�� : Lecture04_HW
// idel : ȭ��� ���������� Ŭ����
// ���콺 ������ KeyDown : ������
// ���콺 ������ KeyUp : ���󺹱�
// ���콺 ���� KeyDown : ���
// ���콺 ���� KeyUp : ���󺹱�
// ���콺 ������ KeyDown �巡�� : �Ķ���
// ���콺 ���� KeyDown �巡�� : ����Ÿ

#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

bool isLeftMouseButtonPressed = false;
bool isRightMouseButtonPressed = false;
double xpos = 0.0, ypos = 0.0;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error : " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void cursorPositionCallback(GLFWwindow* window, double dxpos, double dypos)
{
    dxpos -= xpos;
    dypos -= ypos;
    if (isLeftMouseButtonPressed)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    }
    else if (isRightMouseButtonPressed)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
    }

    xpos = dxpos;
    ypos = dypos;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        isLeftMouseButtonPressed = true;
        isRightMouseButtonPressed = false;
        glfwGetCursorPos(window, &xpos, &ypos);
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        isRightMouseButtonPressed = true;
        isLeftMouseButtonPressed = false; 
        glfwGetCursorPos(window, &xpos, &ypos);
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        isLeftMouseButtonPressed = false;
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        isRightMouseButtonPressed = false;
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
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

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}