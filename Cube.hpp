#ifndef CUBE_H
#define CUBE_H

#include "Drawable.hpp"


class Cube : public Drawable
{
	public:
	Cube();
	Cube(double fSize);

	//Override
	void Render();


	double GetSize()					{return m_fSize;}
	void SetSize(const double &fSize)	{m_fSize = fSize;}



	private:
	float m_fSize;
};

#endif // CUBE_H
