#ifndef CARTPOINT_H
#define CARTPOINT_H
#include "CartVector.h"
using namespace std;
class CartPoint
{
	public:
		double x;
		double y;

		CartPoint();
		CartPoint(double in_x, double in_y);
};

double cart_distance(CartPoint p1, CartPoint p2);

ostream &operator<<(ostream & out, const CartPoint & d);
const CartPoint operator+(const CartPoint &x, const CartPoint &y);
const CartPoint operator+(const CartPoint &x, const CartVector &y);
const CartVector operator-(const CartPoint&x, const CartPoint &y);

#endif