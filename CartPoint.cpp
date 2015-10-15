#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include <cmath>
using namespace std;



CartPoint::CartPoint(double in_x,double in_y)
{
	x = in_x;
	y = in_y;
}
CartPoint::CartPoint( )
{
	x = 0;
	y = 0;
}
double cart_distance(CartPoint p1, CartPoint p2)
{
	double temp;
	temp = sqrt((pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2)));
	return temp;
}

ostream &operator<<(ostream & out, const CartPoint & d)
{
	out << "(" << d.x << "," << d.y << ")";
	return out;
}

const CartPoint operator+(const CartPoint &x, const CartPoint &y)
{
	return CartPoint(x.x+y.x,x.y+y.y);
}

const CartPoint operator+(const CartPoint &x, const CartVector &y)
{
	return CartPoint(x.x+y.x,x.y+y.y);
}
 
const CartVector operator-(const CartPoint&x, const CartPoint &y)
{
	return CartVector(x.x - y.x,x.y - y.y);
}