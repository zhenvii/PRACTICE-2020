// Ïðîåêò ïî òåìå: "2D ðîáîò" 
// ãðóïïû "Óñïåòü çà 5 äíåé!!!! Ïîêà åñòü ïîäïèñêà íà VPN!!!!!!!!!!"
// Âàðèàíò 2

#include<gl\glut.h>
#include <math.h>
#include <cstdlib>
#include "ball.h"
#include "vars.h"


//ðàçìåðû ïîëÿ
int const width = 300;
int const height = 300;

float r_x = 110.0, r_y = 280.0, r_w = 80, r_h = 10.0; //êîîðäèíàòû è ðàçìåðû ïëàòôîðìû
Ball ball(r_y, 8); //ñîçäàí îáúåêò êëàññà Ball ñ ïîçèöèåé ïî y è ðàäèóñîì 

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glColor3f(1.0, 1.0, 1.0);  //öâåò ïëàòôîðìû	
	glRectf(r_x, r_y, r_x+r_w, r_y+r_h); //ðèñóåì ïðÿìîóãîëüíèê (ïëàòôîðìó)
	glColor3f(1.0, 0.0, 0.0);  //öâåò ìÿ÷à
	
	//îïðåäåëÿåì ãðàíèöû, âíóòðè êîòîðûõ çàäàíû âåðøèíû ïðèìèòèâà
	glBegin(GL_POLYGON);
		for(float i = 0; i < 2*3.14; i += 3.14/4)
		{
			//ðèñóåì ìÿ÷
			glVertex2f(ball.x+ball.r*sin(i), ball.y+ball.r*cos(i));
		}
	glEnd();
	
	glutSwapBuffers(); //äëÿ ãëóò äàáë
}

void Timer(int)
{
	//ðèñóåì êàðòèíêó â êàæäûé ìîìåíò âðåìåíè
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
	//çàäàåì öâåò ïîëÿ
	glClearColor(0.3, 0.2, 0.4, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, 1.0, 0.0);
}

int main(int argc, char** argv)
	//argc - êîë-âî àðãóìåíòîâ â êîìàíäíîé ñòðîêå
	//argv - îïèñàíèå â âèäå óêàçàòåëåé íà ññûëêó
{
	glutInit(&argc, argv); 	//ãëîáàëüíàÿ èíèöèàëèçàöèÿ	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); //ñîîáùàåì êàê áóäåì ðèñîâàòü, GLUT_DOUBLE - èñïîëüçóåì áóôåð ðèñîâàíèÿ è áóôåð âû÷èñëåíèÿ GLUT_RGB - öâåòà îïèðàþòñÿ íà RGB
	glutInitWindowSize(width, height); //èíèöèàëèçàöèÿ ðàçìåðîâ îêíà	
	glutInitWindowPosition(100, 200); 	//èíèöèàëèçàöèÿ ïîçèöèè îêíà
	glutCreateWindow("Arkanoid 2D"); //ñîçäàíèå îêíà
	glutDisplayFunc(Draw); //ðèñîâàíèå
	glutTimerFunc(33, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	Initialize(); //èíèöèàëèçàöèÿ
	glutMainLoop();  //ãëàâíûé öèêë
	return 0;
}
