#include "Cube.hpp"

Cube::Cube()
{
	m_Type = CUBE;
}

Cube::Cube(double fSize)
{
	m_Type = CUBE;
	SetSize(fSize);
}

// TODO (crom#1#): add construct with position

void Cube::Render()
{
	double hs = m_fSize/2;

	glBegin(GL_QUADS);

		glColor3ub(255,0,0); //face rouge
		glVertex3d(hs,hs,hs);
		glVertex3d(hs,hs,-hs);
		glVertex3d(-hs,hs,-hs);
		glVertex3d(-hs,hs,hs);

		glColor3ub(0,255,0); //face verte
		glVertex3d(hs,-hs,hs);
		glVertex3d(hs,-hs,-hs);
		glVertex3d(hs,hs,-hs);
		glVertex3d(hs,hs,hs);

		glColor3ub(0,0,255); //face bleue
		glVertex3d(-hs,-hs,hs);
		glVertex3d(-hs,-hs,-hs);
		glVertex3d(hs,-hs,-hs);
		glVertex3d(hs,-hs,hs);

		glColor3ub(255,255,0); //face jaune
		glVertex3d(-hs,hs,hs);
		glVertex3d(-hs,hs,-hs);
		glVertex3d(-hs,-hs,-hs);
		glVertex3d(-hs,-hs,hs);

		glColor3ub(0,255,255); //face cyan
		glVertex3d(hs,hs,-hs);
		glVertex3d(hs,-hs,-hs);
		glVertex3d(-hs,-hs,-hs);
		glVertex3d(-hs,hs,-hs);

		glColor3ub(255,0,255); //face magenta
		glVertex3d(hs,-hs,hs);
		glVertex3d(hs,hs,hs);
		glVertex3d(-hs,hs,hs);
		glVertex3d(-hs,-hs,hs);

    glEnd();


}
