#pragma once
#include "shape.h"

class Line : public Shape {
public:
	Line() = default;
	Line(int _x1, int _y1, int _x2, int _y2);
	int x1 = 0, y1 = 0,
		x2 = 0, y2 = 0;
	double volume;
	double square;
	void shift(int m, int n, int k);
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);
};