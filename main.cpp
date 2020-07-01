// Проект по теме: "2D робот" 
// группы "Успеть за 5 дней!!!! Пока есть подписка на VPN!!!!!!!!!!"
// Вариант 2

#include<gl\glut.h>
#include <math.h>
#include "Ball.h"
#include "Vars.h"




//реализация движения, определяем функцию move() вне класса Ball
void Ball::move()
{
	y += dy;
	if(x-r <= 0)
	{
		x = r;
		dx *= -1;
	}
	else if(y-r <= 0)
	{
		y = r;
		dy *= -1;
	}
	else if(x+r >= 300)
	{
		x = 300-r;
		dx *= -1;
	}
	else if(y+r >= r_y && y+r <= r_y+r_h && x > r_x && x < r_x+r_w)
	{
		dy *= -1;
	}
	else if(y > 300)
		active = false;
}

//размеры поля
int const width = 300;
int const height = 300;

//координаты и размеры платформы
float r_x = 50.0, r_y = 290.0, r_w = 80, r_h = 8.0;


//создан объект класса Ball с позицией по y и радиусом 8
Ball ball(r_y, 6);


void Draw()
{
	//
	glClear(GL_COLOR_BUFFER_BIT);
	
	//цвет платформы	
	glColor3f(0.0, 0.0, 1.0);
	
	//рисуем прямоугольник (платформу)
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h);
	
	//цвет мяча
	glColor3f(1.0, 0.0, 0.0);
	
	//определяет границы, внутри которых заданы вершины примитива
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//рисуем мяч
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	//для глут дабл
	glutSwapBuffers();
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
				--r_x;
				--r_x;
				--r_x;
				--r_x;
				--r_x;
				--r_x;	
				--r_x;
				--r_x;
				--r_x;
				break;
			}
			else break;
		}
		case 'd':
		{
			if (r_x <= 220){
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				++r_x;
				break;
			}
			else break;
	    }
	    case 's':
	    	if(!ball.active){
	    		ball.active = true;
	    		ball.dx = 4;
				ball.dy = -4;
			}
	}	

	if (!ball.active)
	{
		ball.x = width/2;
		ball.y = ball.r;
	}
  		
}


void Initialize()
{	
	//задаем цвет поля
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - кол-во аргументов в командной строке
	//argv - описание в виде указателей на ссылку
{
	//глобальная инициализация
	glutInit(&argc, argv);
	
	//сообщаем как будем рисовать, GLUT_DOUBLE - используем буфер рисования и буфер вычисления GLUT_RGB - цвета опираются на RGB
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	
	//инициализация размеров окна
	glutInitWindowSize(width, height);
	
	//инициализация позиции окна
	glutInitWindowPosition(100, 200);
	
	//создание окна
	glutCreateWindow("Arkanoid 2D");
	
	//рисование
	glutDisplayFunc(Draw);

	glutTimerFunc(33, Timer, 0);
	glutKeyboardFunc(Keyboard);
	
	
	
	//инициализация
	Initialize();
	
	//главный цикл
	glutMainLoop();
	return 0;
}


