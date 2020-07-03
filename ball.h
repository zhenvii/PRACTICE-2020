//препроцессорная директива, которая отвечает за подключение данного исходного файла при компиляции строго один раз
#pragma once

class Ball
{
public:
	float x, y, dx, dy, r;
	bool active;
	Ball(float y_, float r_): x(), y(y_), r(r_), dx(), dy(), active(false){}
	void move();
};