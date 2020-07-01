// ������ �� ����: "2D �����" 
// ������ "������ �� 5 ����!!!! ���� ���� �������� �� VPN!!!!!!!!!!"
// ������� 2

#include<gl\glut.h>
#include <math.h>
#include "Ball.h"
#include "Vars.h"




//���������� ��������, ���������� ������� move() ��� ������ Ball
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

//������� ����
int const width = 300;
int const height = 300;

//���������� � ������� ���������
float r_x = 50.0, r_y = 290.0, r_w = 80, r_h = 8.0;


//������ ������ ������ Ball � �������� �� y � �������� 8
Ball ball(r_y, 6);


void Draw()
{
	//
	glClear(GL_COLOR_BUFFER_BIT);
	
	//���� ���������	
	glColor3f(0.0, 0.0, 1.0);
	
	//������ ������������� (���������)
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h);
	
	//���� ����
	glColor3f(1.0, 0.0, 0.0);
	
	//���������� �������, ������ ������� ������ ������� ���������
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//������ ���
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	//��� ���� ����
	glutSwapBuffers();
}

void Timer(int)
{
	//������ �������� � ������ ������ �������
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
	//������ ���� ����
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - ���-�� ���������� � ��������� ������
	//argv - �������� � ���� ���������� �� ������
{
	//���������� �������������
	glutInit(&argc, argv);
	
	//�������� ��� ����� ��������, GLUT_DOUBLE - ���������� ����� ��������� � ����� ���������� GLUT_RGB - ����� ��������� �� RGB
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	
	//������������� �������� ����
	glutInitWindowSize(width, height);
	
	//������������� ������� ����
	glutInitWindowPosition(100, 200);
	
	//�������� ����
	glutCreateWindow("Arkanoid 2D");
	
	//���������
	glutDisplayFunc(Draw);

	glutTimerFunc(33, Timer, 0);
	glutKeyboardFunc(Keyboard);
	
	
	
	//�������������
	Initialize();
	
	//������� ����
	glutMainLoop();
	return 0;
}


