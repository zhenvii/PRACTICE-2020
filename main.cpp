// ������ �� ����: "2D �����" 
// ������ "������ �� 5 ����!!!! ���� ���� �������� �� VPN!!!!!!!!!!"
// ������� 2

#include<gl\glut.h>
#include <math.h>
#include <cstdlib>
#include "Ball.h"
#include "Vars.h"
#include "ball_move.h"

//������� ����
int const width = 300;
int const height = 300;

float r_x = 110.0, r_y = 280.0, r_w = 80, r_h = 10.0; //���������� � ������� ���������
Ball ball(r_y, 8); //������ ������ ������ Ball � �������� �� y � �������� 

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glColor3f(1.0, 1.0, 1.0);  //���� ���������	
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h); //������ ������������� (���������)
	glColor3f(1.0, 0.0, 0.0);  //���� ����
	
	//���������� �������, ������ ������� ������ ������� ���������
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//������ ���
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	glutSwapBuffers(); //��� ���� ����
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
	//������ ���� ����
	glClearColor(0.3, 0.2, 0.4, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - ���-�� ���������� � ��������� ������
	//argv - �������� � ���� ���������� �� ������
{
	glutInit(&argc, argv); 	//���������� �������������	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); //�������� ��� ����� ��������, GLUT_DOUBLE - ���������� ����� ��������� � ����� ���������� GLUT_RGB - ����� ��������� �� RGB
	glutInitWindowSize(width, height); //������������� �������� ����	
	glutInitWindowPosition(100, 200); 	//������������� ������� ����
	glutCreateWindow("Arkanoid 2D"); //�������� ����
	glutDisplayFunc(Draw); //���������
	glutTimerFunc(33, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	Initialize(); //�������������
	glutMainLoop();  //������� ����
	return 0;
}
