#include "mObject.h"

class star : public mObject
{
	void update()
	{

	}

	void render()
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
	}
};