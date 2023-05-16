#include "shape.h"
#include "Circle.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Line.h"
#include "Sqr.h"
#include <iostream>

int main()
{
	Line line(3, 4, 5, 6);
	std::cout << "Line:\n";
	std::cout << "X1 = " << line.x1 << " ";
	std::cout << "Y1 = " << line.y1 << " ";
	std::cout << "X2 = " << line.x2 << " ";
	std::cout << "Y2 = " << line.y2 << "\n";
	line.scaleX(2);
	std::cout << "Line after scaleX:\n";
	std::cout << "X1 = " << line.x1 << " ";
	std::cout << "Y1 = " << line.y1 << " ";
	std::cout << "X2 = " << line.x2 << " ";
	std::cout << "Y2 = " << line.y2 << "\n";
	line.scale(2);
	std::cout << "Line after scale:\n";
	std::cout << "X1 = " << line.x1 << " ";
	std::cout << "Y1 = " << line.y1 << " ";
	std::cout << "X2 = " << line.x2 << " ";
	std::cout << "Y2 = " << line.y2 << "\n";
	Sqr sqr(2, 2, 4, 3, 4, 5, 6, 7);
	std::cout << "Sqr:\nSquare = " << sqr.square << "\n";
	Cube cube(2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 3, 4, 5, 6);
	std::cout << "Cube:\nSquare = " << cube.square << "\n";
	std::cout << "Volume = " << cube.volume << "\n";
	Circle circle(1, 2, 4);
	std::cout << "Circle:\nSquare = " << circle.square << "\n";
	Cylinder cylinder(1, 2, 4, 3);
	std::cout << "Cylinder:\nSquare = " << cylinder.square << "\n";
	return 0;
}

