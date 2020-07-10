// 2D Robot
// Dutov, Okhrimenko, Konkova; group 221B
// Version 2

#include<gl\glut.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include "Ball.h"
#include "Vars.h"

using namespace std;

//size of field
int const width = 300;
int const height = 300;
bool control = true;

float r_x = 110.0, r_y = 280.0, r_w = 80, r_h = 10.0; //coordinates and dimensions of the platform
Ball ball(r_y, 8); //created an object of class Ball with a position in y and radius

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glColor3f(1.0, 1.0, 1.0);  //colour of platform	
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h); //draw platform 
	glColor3f(1.0, 0.0, 0.0);  //colour of ball
	
	//define the boundaries within which the vertices of the primitive are given
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//draw ball
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	glutSwapBuffers(); 
}



void Pick_system()
{
	int a;
	cout << "Choose your system:" << endl;
	cout << "1) Bot" << endl;
	cout << "2) Manual control" << endl;
	cout << "Press 1 or 2 and then press 's' or 'down' for start game" << endl;
	cin >> a;
	
	if (a == 1)
		control = true;
		else if (a == 2) control = false;
}



void Bot()
{
	//if the unit is equipped with x, the unit is equipped with a box for completing the process 
	if (ball.active)
	{
	if (r_x <= 220)	
		if (ball.x > r_x)
			r_x = r_x+10;
				
	
	if (r_x >= 0)
		if (ball.x < r_x)
				r_x = r_x-10;			
	}
}



void Timer(int)
{
	//draw picture at every moment in time
	Draw();
	
	if(ball.active){
		if (control == true) 
			Bot();
		ball.move();
		
	}	
	glutTimerFunc(33, Timer, 0);
}



void Keyboard(unsigned char key, int x, int y)
{
	
	switch(key)
	{
		if (control == false)
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
		}
	    case 's':
	    	if(!ball.active){
	    		ball.active = true;
	    		ball.dx = 6;
				ball.dy = -6;
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
		if (control == false)
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
		}
	    case GLUT_KEY_DOWN:
	    	if(!ball.active){
	    		ball.active = true;
	    		ball.dx = 6;
				ball.dy = -6;
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
	//colour of field
	glClearColor(0.3, 0.2, 0.4, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - number of accessories in a commercially available key
	//argv - description in full on the page
{
	Pick_system();
	glutInit(&argc, argv); 	//global initialization	
	
	
		
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); //tell how we will draw, GLUT_DOUBLE - use the drawing buffer and the calculation buffer GLUT_RGB - the colors are based on RGB
	glutInitWindowSize(width, height); //window size initialization	
	glutInitWindowPosition(100, 200); 	//window position initialization
	glutCreateWindow("Arkanoid 2D"); //window creation
	glutDisplayFunc(Draw); //draw
	glutTimerFunc(33, Timer, 0);
	
	//if ( == false)
	
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	
	
	Initialize(); //initialization
	glutMainLoop();  //main cycle
	return 0;
}
