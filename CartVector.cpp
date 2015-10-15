#include <iostream>
#include <vector>
#include "CartVector.h"
#include "CartPoint.h"
using namespace std;

CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}
CartVector::CartVector( )
{
	x = 0;
	y = 0;
}

ostream &operator<<(ostream & out, const CartVector & vector)
{
	out << "<" << vector.x << ", " << vector.y << ">" << endl;
	return out;
}

const CartVector operator*(const CartVector &x, const double d)
{
	return CartVector(x.x*d,x.y*d);
}

const CartVector operator/(const CartVector &x, const double d)
{
	return CartVector(x.x/d,x.y/d);
}