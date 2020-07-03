#pragma once
#include "Ball.h"
#include "Vars.h"

//реализация движения, определяем функцию move() вне класса Ball
void Ball::move()
{	
	//поведение траектории мяча в зависимости от попадания на разные области платформы

		y = y + dy;
		x = x + dx - 3*dx/4;
	
	//если мяч касается границ поля или платформы 
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
