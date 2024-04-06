#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;



int main(void)
{
    setlocale(LC_ALL, "Russian");

    /* ������������� ���������� GLFW */
    if (!glfwInit())
        return -1;

    /* �������� ���� � ��� ��������� OpenGL */
    GLFWwindow* window = glfwCreateWindow(900, 900, "Tetris", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* ��������� �������� ��������� ��� ���� */
    glfwMakeContextCurrent(window);

    /* ���� �� �������� ���� */
    while (!glfwWindowShouldClose(window))
    {
        /* ��������� ����� */
        glClear(GL_COLOR_BUFFER_BIT);

        /*  ��������� ������� �������*/
        glPushMatrix();

        /* ��������������� ���������� �������*/
        glPopMatrix();

        /* ������������ ��������� � ������� ������� */
        glfwSwapBuffers(window);

        /* �������� ������� � �� ��������� */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
