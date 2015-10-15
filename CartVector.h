#ifndef CARTVECTOR_H
#define CARTVECTOR_H
#include <iostream>
using namespace std;

class CartVector
{
	public:
		double x;
		double y;

		CartVector( );
		CartVector(double in_x, double in_y);

};

const CartVector operator/(const CartVector &x, const double d);
const CartVector operator*(const CartVector &x, const double d);
ostream &operator<<(ostream & out, const CartVector & vector);

#endif