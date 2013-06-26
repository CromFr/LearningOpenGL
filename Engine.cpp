#include "Engine.hpp"



Engine::Engine()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)1024/768,1,1000);

    glEnable(GL_DEPTH_TEST);

    DyDrawableList.clear();


}

Engine::~Engine()
{
	for(unsigned int i=0 ; i<DyDrawableList.size() ; i++)
		delete DyDrawableList[i];

}


/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Engine::RenderAll()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();
	gluLookAt(7,7,5,0,0,0,0,0,1);


	for(unsigned int i=0 ; i<DyDrawableList.size() ; i++)
	{
		glPushMatrix();

		Vect3D<double> Pos = DyDrawableList[i]->GetPosition();
		glTranslated(Pos.x, Pos.y, Pos.z);


		double Fac = DyDrawableList[i]->GetFacing();
		glRotated(Fac, 0, 0, 1);
		double Pit = DyDrawableList[i]->GetPitch();
		glRotated(Pit, 0, 1, 0);


		DyDrawableList[i]->Render();


		glPopMatrix();

	}


	glFlush();
}
/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*
int Engine::LoadTexture(string sPath)
{

	return loadTexture(sPath.c_str(), false);
}


/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
Cube* Engine::CreateCube(double fSize, Vect3D<double> Pos, double Facing, double Pitch)
{
	Cube* New = new Cube(fSize);
	New->SetPosition(Pos);
	New->SetFacing(Facing);
	New->SetPitch(Pitch);
	DyDrawableList.push_back(New);

	return New;
}


/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
HeightMap* Engine::CreateHeightMap(string sPath, Vect3D<double> Pos, double Facing, double Pitch)
{
	HeightMap* New = new HeightMap(sPath);
	New->SetPosition(Pos);
	New->SetFacing(Facing);
	New->SetPitch(Pitch);
	DyDrawableList.push_back(New);

	return New;
}


/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Engine::AddDrawable(Drawable* oDraw)
{
	DyDrawableList.push_back(oDraw);


}


/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
