// Проект по теме: "2D робот" 
// группы "Успеть за 5 дней!!!! Пока есть подписка на VPN!!!!!!!!!!"
// Вариант 2

#include<gl\glut.h>
#include <math.h>
#include <cstdlib>
#include "Ball.h"
#include "Vars.h"
#include "ball_move.h"

//размеры поля
int const width = 300;
int const height = 300;

float r_x = 110.0, r_y = 280.0, r_w = 80, r_h = 10.0; //координаты и размеры платформы
Ball ball(r_y, 8); //создан объект класса Ball с позицией по y и радиусом 

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glColor3f(1.0, 1.0, 1.0);  //цвет платформы	
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h); //рисуем прямоугольник (платформу)
	glColor3f(1.0, 0.0, 0.0);  //цвет мяча
	
	//определяем границы, внутри которых заданы вершины примитива
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//рисуем мяч
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	glutSwapBuffers(); //для глут дабл
}

void Timer(int)
{
	//рисуем картинку в каждый момент времени
	Draw();
	if(ball.active)
		ball.move();
	glutTimerFunc(33, Timer, 0);
}


void Keyboard(unsigned char key, int x, int y)
{
	
	switch(key)
	{
		case 'a':
		{
			if (r_x >= 0){
				for (int i = 0; i < 10; i++)
					--r_x;
				break;
			}
			else break;
		}
		case 'd':
		{
			if (r_x <= 220){
				for (int i = 0; i < 10; i++)
					++r_x;
				break;
			}
			else break;
	    }
	    case 's':
	    	if(!ball.active){
	    		ball.active = true;
	    		ball.dx = 7;
				ball.dy = -7;
			}
	}	

	if (!ball.active)
	{
		ball.x = rand() % width;
		ball.y = ball.r;
	}
  		
}

void SKeyboard(int key, int x, int y)
{
		switch(key)
	{
		case GLUT_KEY_LEFT:
		{
			if (r_x >= 0){
				for (int i = 0; i < 10; i++)
					--r_x;
				break;
			}
			else break;
		}
		case GLUT_KEY_RIGHT:
		{
			if (r_x <= 220){
				for (int i = 0; i < 10; i++)
					++r_x;
				break;
			}
			else break;
	    }
	    case GLUT_KEY_DOWN:
	    	if(!ball.active){
	    		ball.active = true;
	    		ball.dx = 7;
				ball.dy = -7;
			}
	}	
	if (!ball.active)
	{
		ball.x = rand() % width;
		ball.y = ball.r;
	}  		
}

void Initialize()
{	
	//задаем цвет поля
	glClearColor(0.3, 0.2, 0.4, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - кол-во аргументов в командной строке
	//argv - описание в виде указателей на ссылку
{
	glutInit(&argc, argv); 	//глобальная инициализация	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); //сообщаем как будем рисовать, GLUT_DOUBLE - используем буфер рисования и буфер вычисления GLUT_RGB - цвета опираются на RGB
	glutInitWindowSize(width, height); //инициализация размеров окна	
	glutInitWindowPosition(100, 200); 	//инициализация позиции окна
	glutCreateWindow("Arkanoid 2D"); //создание окна
	glutDisplayFunc(Draw); //рисование
	glutTimerFunc(33, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	Initialize(); //инициализация
	glutMainLoop();  //главный цикл
	return 0;
}
