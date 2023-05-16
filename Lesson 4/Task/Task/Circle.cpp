#define _USE_MATH_DEFINES
#include "Circle.h"

Circle::Circle(int _x1, int _y1, double R) {
	x1 = _x1; y1 = _y1;
	radius = R;
	square = M_PI * radius * radius;
}