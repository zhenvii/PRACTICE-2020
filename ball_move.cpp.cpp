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
