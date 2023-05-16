#include "Sqr.h"

Sqr::Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) {
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	x3 = _x3; y3 = _y3;
	x4 = _x4; y4 = _y4;
	square = abs(x1 - x2) * abs(y1 - y2);
	volume = 0;
}
void Sqr::shift(int m, int n, int k) {
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;
}
void Sqr::scaleX(int a) {
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
}
void Sqr::scaleY(int d) {
	x1 *= d;
	x2 *= d;
	x3 *= d;
	x4 *= d;
}
void Sqr::scaleZ(int e) {
	x1 *= e;
	x2 *= e;
	x3 *= e;
	x4 *= e;
}
void Sqr::scale(int s) {
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}