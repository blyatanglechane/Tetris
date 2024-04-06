#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

// Рисуем все фигуры
void drawShapes()
{

}


// Рисуем поле для игры 20x10
void drawAxesWithGrid()
{
    /* Рисуем сетку*/
    glColor3f(0.5f, 0.5f, 0.5f); // Серый цвет для сетки
    glBegin(GL_LINES);
    /* Рисуем горизонтальные линии сетки*/
    for (float y = -1.0f; y <= 1.0f; y += 0.1f)
    {
        glVertex2f(-0.5f, y);
        glVertex2f(0.5f, y);
    }
    /* Рисуем вертикальные линии сетки*/
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

    /* Инициализация библиотеки GLFW, в случае ошибки мы выходим из программы */
    if (!glfwInit())
    {
        cout << "glfwInit вызвала аварийное сообщение!\n";
        return -1;
    }
        
    // Опции для создания контекста OpenGL, указываем версию OpenGL, которую мы хотим использовать в программе
    // Если версия меньше 4.6, то мы не сможем создать окно, это нужно для уверенности, что мы сможем использовать все возможности
    // данной версии.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // Core profile - это определённое подмножество всех функций OpenGL куда не включены все функции нужные для обратной совместимости
    // различных версий OpenGL, которые нам не нужны
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Создание окна и его контекста OpenGL */
    GLFWwindow* pWindow = glfwCreateWindow(900, 900, "Tetris", NULL, NULL);

    // Проверяем успешно ли открыто окно
    if (!pWindow)
    {
        cout << "Ошибка создания окна!\n";
        glfwTerminate();
        return -1;
    }

    /* Установка текущего контекста для окна */
    glfwMakeContextCurrent(pWindow);

    cout << "OpenGL " << glGetString(GL_VERSION) << "\n";

    /* Цикл до закрытия окна */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Отрисовка здесь */
        glClear(GL_COLOR_BUFFER_BIT);

        // Рисуем игровое поле
        drawAxesWithGrid();

        /*  Сохраняем текущую матрицу*/
        glPushMatrix();

        /* Восстанавливаем предыдущую матрицу*/
        glPopMatrix();

        /* Переключение переднего и заднего буферов */
        glfwSwapBuffers(pWindow);

        /* Проверка событий и их обработка */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
