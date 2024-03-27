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

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        (1.0f, 0.0f, 0.0f, 1.0f);
    }
}


int main(void)
{
    GLFWwindow* window;

    /* glfw���̺귯�� �ʱ�ȭ */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "Hi", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
   

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}