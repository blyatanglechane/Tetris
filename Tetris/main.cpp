//#include <iostream>
//#include <time.h>
//#include <GLFW/glfw3.h>
//
//
//using namespace std;
//
//float x = 0;
//float y = 1.4;
//int currentShape = 0; // Переменная для хранения текущей фигуры
//float rotationAngle = 0.0;
//
//// Функция для генерации новой случайной фигуры
//void generateNewShape() {
//    currentShape = rand() % (2 - 1 + 1) + 1; // Генерируем случайное число от 1 до 2
//    y = 1.4f; // Сбрасываем значение y обратно на начальную позицию
//}
//
//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_D && action == GLFW_PRESS)
//    {
//        if (x + 0.1 < 0.5)
//        x += 0.1f; // Учитываем текущий масштаб при изменении координат
//    }
//    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
//    {
//        if (y - 0.1 > -0.6)
//        y -= 0.1f; // Учитываем текущий масштаб при изменении координат
//    }
//    else if (key == GLFW_KEY_A && action == GLFW_PRESS)
//    {
//        if (x - 0.1 > -0.5)
//        x -= 0.1f; // Учитываем текущий масштаб при изменении координат
//    }
//    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
//    {
//        rotationAngle += 90.0f; // Поворот против часовой стрелки на 5 градусов
//    }
//}
////rand() % (7 - 1 + 1) + 1
//
//// Рисуем все фигуры
//void drawShapes()
//{
//    switch (currentShape)
//    {
//    case 1:
//        // 1-ая фигура вертикальная в 4-е кубика
//        glPushMatrix();
//        glTranslatef(0.05f, y - 0.25f, 0.0f); // Перемещаем центр фигуры в начало координат
//        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Поворачиваем фигуру
//        glTranslatef(-0.05f, -(y - 0.25f), 0.0f); // Возвращаем центр фигуры обратно на место
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
//        // 2-ая фигура зиг-зак левый верхний квадрат
//        glPushMatrix();
//        glTranslatef(0.05f, y - 0.2f, 0.0f); // Перемещаем центр фигуры в начало координат
//        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Поворачиваем фигуру
//        glTranslatef(-0.05f, -(y - 0.2f), 0.0f); // Возвращаем центр фигуры обратно на место
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
//// Рисуем поле для игры 20x10
//void drawAxesWithGrid()
//{
//    /* Рисуем сетку*/
//    glColor3f(0.5f, 0.5f, 0.5f); // Серый цвет для сетки
//    glBegin(GL_LINES);
//    /* Рисуем горизонтальные линии сетки*/
//    for (float y = -1.0f; y <= 1.0f; y += 0.1f)
//    {
//        glVertex2f(-0.5f, y);
//        glVertex2f(0.5f, y);
//    }
//    /* Рисуем вертикальные линии сетки*/
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
//    /* Инициализация библиотеки GLFW, в случае ошибки мы выходим из программы */
//    if (!glfwInit())
//    {
//        cout << "glfwInit вызвала аварийное сообщение!\n";
//        return -1;
//    }
//        
//    // Опции для создания контекста OpenGL, указываем версию OpenGL, которую мы хотим использовать в программе
//    // Если версия меньше 4.6, то мы не сможем создать окно, это нужно для уверенности, что мы сможем использовать все возможности
//    // данной версии.
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
//
//    //// Core profile - это определённое подмножество всех функций OpenGL куда не включены все функции нужные для обратной совместимости
//    //// различных версий OpenGL, которые нам не нужны
//    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    /* Создание окна и его контекста OpenGL */
//    GLFWwindow* pWindow = glfwCreateWindow(900, 900, "Tetris", NULL, NULL);
//
//    // Проверяем успешно ли открыто окно
//    if (!pWindow)
//    {
//        cout << "Ошибка создания окна!\n";
//        glfwTerminate();
//        return -1;
//    }
//
//    srand(time(0));
//
//    /* Установка текущего контекста для окна */
//    glfwMakeContextCurrent(pWindow);
//
//    glfwSetKeyCallback(pWindow, keyCallback);
//
//    cout << "OpenGL " << glGetString(GL_VERSION) << "\n";
//
//    // Генерируем новую случайную фигуру перед началом цикла
//    generateNewShape();
//
//    /* Цикл до закрытия окна */
//    while (!glfwWindowShouldClose(pWindow))
//    {
//        /* Отрисовка здесь */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Рисуем игровое поле
//        drawAxesWithGrid();
//
//        /*  Сохраняем текущую матрицу*/
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
//        // Перемещаем фигуру по оси y каждую секунду
//        if (glfwGetTime() >= 1.0) {
//            y -= 0.1f;
//            glfwSetTime(0.0); // Сбрасываем таймер
//        }
//
//        // Перемещаем фигуру
//        glTranslatef(x, 0.0f, 0.0f);
//
//        // Рисуем фигуру
//        drawShapes();
//
//        /* Восстанавливаем предыдущую матрицу*/
//        glPopMatrix();
//
//        /* Переключение переднего и заднего буферов */
//        glfwSwapBuffers(pWindow);
//
//        /* Проверка событий и их обработка */
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
int currentShape = 0; // Переменная для хранения текущей фигуры

void generateNewShape() {
	    currentShape = rand() % (2 - 1 + 1) + 1; // Генерируем случайное число от 1 до 2
	    y = 1.4f; // Сбрасываем значение y обратно на начальную позицию
	}


int main()
{
	vector<vector<int>> matrix(20, vector<int>(10, 0));
	srand(time(0));
	generateNewShape();


	while (true) {

		if (glfwGetTime() >= 1.0) {
			y -= 0.1f;
			glfwSetTime(0.0); // Сбрасываем таймер
		}

	}


	return 0;
}