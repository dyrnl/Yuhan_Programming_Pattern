#include "mObject.h"
#include <GLFW/glfw3.h>

class Star : public mObject
{
	void update() override
	{

	}
	void render() override
	{
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.5f), (0.3f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((-0.5f), (0.3f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.0f), (-0.2f));
        glEnd();

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.0f), (0.7f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.2f), (-0.1f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((-0.4f), (-0.5f));

        glEnd();

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.0f), (0.7f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((0.4f), (-0.5f));

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f((-0.2f), (-0.1f));

        glEnd();
	}
};