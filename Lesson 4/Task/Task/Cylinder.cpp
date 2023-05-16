#define _USE_MATH_DEFINES
#include "Cylinder.h"

Cylinder::Cylinder(int _x1, int _y1, double R, double H) {
	x1 = _x1; y1 = _y1;
	radius = R;
	height = H;
	square = M_PI * radius * radius + 2 * radius * height;
}