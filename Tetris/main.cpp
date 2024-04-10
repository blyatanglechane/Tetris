//#include <iostream>
//#include <time.h>
//#include <GLFW/glfw3.h>
//
//
//using namespace std;
//
//float x = 0;
//float y = 1.4;
//int currentShape = 0; // ���������� ��� �������� ������� ������
//float rotationAngle = 0.0;
//
//// ������� ��� ��������� ����� ��������� ������
//void generateNewShape() {
//    currentShape = rand() % (2 - 1 + 1) + 1; // ���������� ��������� ����� �� 1 �� 2
//    y = 1.4f; // ���������� �������� y ������� �� ��������� �������
//}
//
//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_D && action == GLFW_PRESS)
//    {
//        if (x + 0.1 < 0.5)
//        x += 0.1f; // ��������� ������� ������� ��� ��������� ���������
//    }
//    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
//    {
//        if (y - 0.1 > -0.6)
//        y -= 0.1f; // ��������� ������� ������� ��� ��������� ���������
//    }
//    else if (key == GLFW_KEY_A && action == GLFW_PRESS)
//    {
//        if (x - 0.1 > -0.5)
//        x -= 0.1f; // ��������� ������� ������� ��� ��������� ���������
//    }
//    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
//    {
//        rotationAngle += 90.0f; // ������� ������ ������� ������� �� 5 ��������
//    }
//}
////rand() % (7 - 1 + 1) + 1
//
//// ������ ��� ������
//void drawShapes()
//{
//    switch (currentShape)
//    {
//    case 1:
//        // 1-�� ������ ������������ � 4-� ������
//        glPushMatrix();
//        glTranslatef(0.05f, y - 0.25f, 0.0f); // ���������� ����� ������ � ������ ���������
//        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // ������������ ������
//        glTranslatef(-0.05f, -(y - 0.25f), 0.0f); // ���������� ����� ������ ������� �� �����
//        glBegin(GL_LINES);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex2f(0.0f, y - 0.1f);
//        glVertex2f(0.1f, y - 0.1f);
//
//        glVertex2f(0.1f, y - 0.1f);
//        glVertex2f(0.1f, y - 0.2f);
//
//        glVertex2f(0.1f, y - 0.2f);
//        glVertex2f(0.2f, y - 0.2f);
//
//        glVertex2f(0.2f, y - 0.2f);
//        glVertex2f(0.2f, y - 0.4f);
//
//        glVertex2f(0.2f, y - 0.4f);
//        glVertex2f(0.1f, y - 0.4f);
//
//        glVertex2f(0.1f, y - 0.4f);
//        glVertex2f(0.1f, y - 0.3f);
//
//        glVertex2f(0.1f, y - 0.3f);
//        glVertex2f(0.0f, y - 0.3f);
//
//        glVertex2f(0.0f, y - 0.3f);
//        glVertex2f(0.0f, y - 0.1f);
//
//        glEnd();
//        glPopMatrix();
//        break;
//    case 2:
//        // 2-�� ������ ���-��� ����� ������� �������
//        glPushMatrix();
//        glTranslatef(0.05f, y - 0.2f, 0.0f); // ���������� ����� ������ � ������ ���������
//        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // ������������ ������
//        glTranslatef(-0.05f, -(y - 0.2f), 0.0f); // ���������� ����� ������ ������� �� �����
//        glBegin(GL_LINES);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex2f(0.0f, y);
//        glVertex2f(0.1f, y);
//
//        glVertex2f(0.1f, y);
//        glVertex2f(0.1f, y - 0.4f);
//
//        glVertex2f(0.1f, y - 0.4f);
//        glVertex2f(0.0f, y - 0.4f);
//
//        glVertex2f(0.0f, y - 0.4f);
//        glVertex2f(0.0f, y);
//        glEnd();
//        glPopMatrix();
//        break;
//    }
//}
//
//
//// ������ ���� ��� ���� 20x10
//void drawAxesWithGrid()
//{
//    /* ������ �����*/
//    glColor3f(0.5f, 0.5f, 0.5f); // ����� ���� ��� �����
//    glBegin(GL_LINES);
//    /* ������ �������������� ����� �����*/
//    for (float y = -1.0f; y <= 1.0f; y += 0.1f)
//    {
//        glVertex2f(-0.5f, y);
//        glVertex2f(0.5f, y);
//    }
//    /* ������ ������������ ����� �����*/
//    for (float x = -0.5f; x <= 0.5f; x += 0.1f)
//    {
//        glVertex2f(x, -1.0f);
//        glVertex2f(x, 1.0f);
//    }
//    glEnd();
//}
//
//
//int main(void)
//{
//    setlocale(LC_ALL, "Russian");
//
//    /* ������������� ���������� GLFW, � ������ ������ �� ������� �� ��������� */
//    if (!glfwInit())
//    {
//        cout << "glfwInit ������� ��������� ���������!\n";
//        return -1;
//    }
//        
//    // ����� ��� �������� ��������� OpenGL, ��������� ������ OpenGL, ������� �� ����� ������������ � ���������
//    // ���� ������ ������ 4.6, �� �� �� ������ ������� ����, ��� ����� ��� �����������, ��� �� ������ ������������ ��� �����������
//    // ������ ������.
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
//
//    //// Core profile - ��� ����������� ������������ ���� ������� OpenGL ���� �� �������� ��� ������� ������ ��� �������� �������������
//    //// ��������� ������ OpenGL, ������� ��� �� �����
//    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    /* �������� ���� � ��� ��������� OpenGL */
//    GLFWwindow* pWindow = glfwCreateWindow(900, 900, "Tetris", NULL, NULL);
//
//    // ��������� ������� �� ������� ����
//    if (!pWindow)
//    {
//        cout << "������ �������� ����!\n";
//        glfwTerminate();
//        return -1;
//    }
//
//    srand(time(0));
//
//    /* ��������� �������� ��������� ��� ���� */
//    glfwMakeContextCurrent(pWindow);
//
//    glfwSetKeyCallback(pWindow, keyCallback);
//
//    cout << "OpenGL " << glGetString(GL_VERSION) << "\n";
//
//    // ���������� ����� ��������� ������ ����� ������� �����
//    generateNewShape();
//
//    /* ���� �� �������� ���� */
//    while (!glfwWindowShouldClose(pWindow))
//    {
//        /* ��������� ����� */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // ������ ������� ����
//        drawAxesWithGrid();
//
//        /*  ��������� ������� �������*/
//        glPushMatrix();
//
//        if (y <= -0.7f && currentShape == 1) generateNewShape();
//        else if (y <= -0.8f && currentShape == 2) generateNewShape();
//        else if (y <= -0.8f && currentShape == 3) generateNewShape();
//        else if (y <= -0.8f && currentShape == 4) generateNewShape();
//        else if (y <= -0.8f && currentShape == 5) generateNewShape();
//        else if (y <= -0.8f && currentShape == 6) generateNewShape();
//        else if (y <= -0.9f && currentShape == 7) generateNewShape();
//
//        // ���������� ������ �� ��� y ������ �������
//        if (glfwGetTime() >= 1.0) {
//            y -= 0.1f;
//            glfwSetTime(0.0); // ���������� ������
//        }
//
//        // ���������� ������
//        glTranslatef(x, 0.0f, 0.0f);
//
//        // ������ ������
//        drawShapes();
//
//        /* ��������������� ���������� �������*/
//        glPopMatrix();
//
//        /* ������������ ��������� � ������� ������� */
//        glfwSwapBuffers(pWindow);
//
//        /* �������� ������� � �� ��������� */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}


#include <iostream>
#include <time.h>
#include <vector>
#include <GLFW/glfw3.h>

using namespace std;


float y = 1.4;
int currentShape = 0; // ���������� ��� �������� ������� ������

void generateNewShape() {
	    currentShape = rand() % (2 - 1 + 1) + 1; // ���������� ��������� ����� �� 1 �� 2
	    y = 1.4f; // ���������� �������� y ������� �� ��������� �������
	}


int main()
{
	vector<vector<int>> matrix(20, vector<int>(10, 0));
	srand(time(0));
	generateNewShape();


	while (true) {

		if (glfwGetTime() >= 1.0) {
			y -= 0.1f;
			glfwSetTime(0.0); // ���������� ������
		}

	}


	return 0;
}