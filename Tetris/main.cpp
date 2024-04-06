#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

// ������ ��� ������
void drawShapes()
{

}


// ������ ���� ��� ���� 20x10
void drawAxesWithGrid()
{
    /* ������ �����*/
    glColor3f(0.5f, 0.5f, 0.5f); // ����� ���� ��� �����
    glBegin(GL_LINES);
    /* ������ �������������� ����� �����*/
    for (float y = -1.0f; y <= 1.0f; y += 0.1f)
    {
        glVertex2f(-0.5f, y);
        glVertex2f(0.5f, y);
    }
    /* ������ ������������ ����� �����*/
    for (float x = -0.5f; x <= 0.5f; x += 0.1f)
    {
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }
    glEnd();
}


int main(void)
{
    setlocale(LC_ALL, "Russian");

    /* ������������� ���������� GLFW, � ������ ������ �� ������� �� ��������� */
    if (!glfwInit())
    {
        cout << "glfwInit ������� ��������� ���������!\n";
        return -1;
    }
        
    // ����� ��� �������� ��������� OpenGL, ��������� ������ OpenGL, ������� �� ����� ������������ � ���������
    // ���� ������ ������ 4.6, �� �� �� ������ ������� ����, ��� ����� ��� �����������, ��� �� ������ ������������ ��� �����������
    // ������ ������.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // Core profile - ��� ����������� ������������ ���� ������� OpenGL ���� �� �������� ��� ������� ������ ��� �������� �������������
    // ��������� ������ OpenGL, ������� ��� �� �����
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* �������� ���� � ��� ��������� OpenGL */
    GLFWwindow* pWindow = glfwCreateWindow(900, 900, "Tetris", NULL, NULL);

    // ��������� ������� �� ������� ����
    if (!pWindow)
    {
        cout << "������ �������� ����!\n";
        glfwTerminate();
        return -1;
    }

    /* ��������� �������� ��������� ��� ���� */
    glfwMakeContextCurrent(pWindow);

    cout << "OpenGL " << glGetString(GL_VERSION) << "\n";

    /* ���� �� �������� ���� */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* ��������� ����� */
        glClear(GL_COLOR_BUFFER_BIT);

        // ������ ������� ����
        drawAxesWithGrid();

        /*  ��������� ������� �������*/
        glPushMatrix();

        /* ��������������� ���������� �������*/
        glPopMatrix();

        /* ������������ ��������� � ������� ������� */
        glfwSwapBuffers(pWindow);

        /* �������� ������� � �� ��������� */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
