#pragma once
#include "Ball.h"
#include "Vars.h"

//implementation of movement, we define the function move () outside the class Ball
void Ball::move()
{	
		y = y + dy;
		x = x + dx - 3*dx/4;
	
	//if the ball touches the boundaries of the field or platform, then a rebound occurs
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
