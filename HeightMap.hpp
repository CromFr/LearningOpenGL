#ifndef HEIGHMAP_HPP_INCLUDED
#define HEIGHMAP_HPP_INCLUDED

#include <GL/gl.h>
#include <GL/glu.h>

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Drawable.hpp"

using namespace std;

struct color
{
	char r;
	char v;
	char b;
};

class HeightMap : public Drawable
{
    public:
    HeightMap();
    HeightMap(string sPath);


    bool LoadFromFile(string sPath);

    void Render();

    private:
    int m_nWidth;
    int m_nHeight;
    double* m_pMap;
    struct color* m_pColors;

	void DrawVertex(int w, int h);
    double GetZValue(int w, int h);


};

#endif // HEIGHMAP_HPP_INCLUDED
