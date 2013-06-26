#ifndef VECT3D_HPP_INCLUDED
#define VECT3D_HPP_INCLUDED

#include <cmath>

template<typename T>

class Vect3D
{
	public:
	Vect3D()					{set();}
	Vect3D(T X, T Y=0, T Z=0)	{set(X, Y, Z);}

	void set(const Vect3D &Vect)    					{x=Vect.x;	y=Vect.y;	z=Vect.z;}
	void set(const T &X=0, const T &Y=0, const T &Z=0)	{x=X;	y=Y;	z=Z;}

	T x;
	T y;
	T z;



	T GetSquareLength()		{return x*x+y*y+z*z;}
	double GetLength()		{return sqrt( GetSquareLength()*1.0 );}
};



#endif // VECT3D_HPP_INCLUDED
