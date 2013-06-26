#ifndef DRAWABLE_HPP_INCLUDED
#define DRAWABLE_HPP_INCLUDED


#include <GL/gl.h>
#include <GL/glu.h>


#include "Vect3D.hpp"

enum DrawableType
{
	INVALID,
	HEIGHTMAP,
	CUBE
};

class Drawable
{
	public:

	Drawable()							{m_bVisible=true; m_nTexture=-1;}


	virtual void Render()=0;


	virtual bool GetIsVisible()				{return m_bVisible;}
	virtual void SetVisible(bool bVisible)	{m_bVisible = bVisible;}

	virtual enum DrawableType GetType()	{return m_Type;}

	virtual Vect3D<double> GetPosition()					{return m_Pos;}
    virtual void SetPosition(Vect3D<double> Pos)			{m_Pos.set(Pos);}
    virtual void SetPosition(double x, double y, double z)	{m_Pos.set(x, y, z);}

	virtual double GetFacing()				{return m_Facing;}
    virtual void SetFacing(double Facing)	{m_Facing = Facing;}

	virtual double GetPitch()				{return m_Pitch;}
    virtual void SetPitch(double Pitch)		{m_Pitch = Pitch;}

    protected:
    bool m_bVisible;
    enum DrawableType m_Type;

    //-1 if no texture, otherwise the ID of the texture
    int m_nTexture;

    Vect3D<double> m_Pos;
    double m_Facing;
    double m_Pitch;



};

#endif // DRAWABLE_HPP_INCLUDED
