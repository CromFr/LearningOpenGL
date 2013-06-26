#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED
/*

z = vertical
x, y = hrz

x=facing(0)
y=facing(PI/2)





*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <iostream>

#include "Vect3D.hpp"

#include "utils/sdlglutils.h"

#include "Drawable.hpp"
	#include "Cube.hpp"
	#include "HeightMap.hpp"



using namespace std;

class Engine
{
	public:
	Engine();
	~Engine();

	///Draws the entire scene
	void RenderAll();


	int LoadTexture(string sPath);


	Cube* CreateCube(double fSize, Vect3D<double> Pos=Vect3D<double>(), double Facing=0.0, double Pitch=0.0);
	HeightMap* CreateHeightMap(string sPath, Vect3D<double> Pos=Vect3D<double>(), double Facing=0.0, double Pitch=0.0);



	// TODO (crom#1#): placer dans les allocs statiques
	void AddDrawable(Drawable* oDraw);


	private:
	vector<Drawable*> DyDrawableList;

	//Camera

};



#endif // ENGINE_HPP_INCLUDED
