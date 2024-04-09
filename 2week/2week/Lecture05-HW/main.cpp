#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

float verticalMoveFactor = 0.0f;
float horizontalMoveFactor = 0.0f;
float scaleFactor = 1.0f;

bool isLeftMouseButtonPressed = false;
bool isRightMouseButtonPressed = false;

double lastXPos = 0.0, lastYPos = 0.0;

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
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        verticalMoveFactor += 0.01f;
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    double dx = xpos - lastXPos;
    double dy = ypos - lastYPos;
    if (isLeftMouseButtonPressed)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    }
    else if (isRightMouseButtonPressed)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    }

    if (isRightMouseButtonPressed)
    {
        scaleFactor += dx / 1000.0f;
    }

    if (isLeftMouseButtonPressed)
    {
        horizontalMoveFactor += dx / 1000.0f;
        verticalMoveFactor -= dy / 1000.0f;
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        isLeftMouseButtonPressed = true;
        isRightMouseButtonPressed = false;
        glfwGetCursorPos(window, &lastXPos, &lastYPos);
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        isRightMouseButtonPressed = true;
        isLeftMouseButtonPressed = false;
        glfwGetCursorPos(window, &lastXPos, &lastYPos);
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

int Render()
{
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.5f + horizontalMoveFactor) * scaleFactor, (0.3f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.5f + horizontalMoveFactor) * scaleFactor, (0.3f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (-0.2f + verticalMoveFactor) * scaleFactor);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (0.7f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.2f + horizontalMoveFactor) * scaleFactor, (-0.1f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.4f + horizontalMoveFactor) * scaleFactor, (-0.5f + verticalMoveFactor) * scaleFactor);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (0.7f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((0.4f + horizontalMoveFactor) * scaleFactor, (-0.5f + verticalMoveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((-0.2f + horizontalMoveFactor) * scaleFactor, (-0.1f + verticalMoveFactor) * scaleFactor);

    glEnd();

    return 0;
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1980, 1020, "Hi", NULL, NULL);
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

        Render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
