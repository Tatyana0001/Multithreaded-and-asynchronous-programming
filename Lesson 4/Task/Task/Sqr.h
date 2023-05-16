#pragma once
#include "shape.h"

class Sqr : public Shape {
public:
	Sqr() = default;
	Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
	int x1 = 0, y1 = 0,
		x2 = 0, y2 = 0,
		x3 = 0, y3 = 0,
		x4 = 0, y4 = 0;
	double volume;
	double square;
	void shift(int m, int n, int k);
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);
};