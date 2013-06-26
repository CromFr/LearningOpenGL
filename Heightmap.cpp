#include "HeightMap.hpp"


HeightMap::HeightMap()
{
	m_Type = HEIGHTMAP;
    m_nWidth = -1;
    m_nHeight = -1;
    m_pMap = 0;
}


HeightMap::HeightMap(string sPath)
{
	m_Type = HEIGHTMAP;
    LoadFromFile(sPath);
}


bool HeightMap::LoadFromFile(string sPath)
{
    ifstream Map(sPath.c_str());
    if(!Map)
    {
        cout<<"\aErreur Map introuvable : "<<sPath<<endl;
        return false;
    }

    Map>>m_nWidth;
    Map>>m_nHeight;

    m_pMap = new (double[m_nWidth*m_nHeight]);
    m_pColors = new (struct color[m_nWidth*m_nHeight]);

    //Chargement de la map en mémoire vive
    for(int i=0 ; i<m_nWidth*m_nHeight ; i++)
    {
    	Map>>*(m_pMap+i);
    	m_pColors[i].r = rand()%255;
    	m_pColors[i].v = rand()%255;
    	m_pColors[i].b = rand()%255;
    }





    return true;

}



void HeightMap::Render()
{

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    for(int h=0 ; h<m_nHeight-1 ; h++)
    {
        for(int w=0 ; w<m_nWidth-1 ; w++)
        {
        	glColor3ub((m_pColors+w+h*m_nHeight)->r, (m_pColors+w+h*m_nHeight)->v, (m_pColors+w+h*m_nHeight)->b);

            DrawVertex(w, h);
            DrawVertex(w+1, h);
            DrawVertex(w+1, h+1);
            DrawVertex(w, h+1);
        }
    }
    glEnd();
}

void HeightMap::DrawVertex(int w, int h)
{
	//glColor3ub((m_pColors+w+(h)*m_nHeight)->r, (m_pColors+w+(h)*m_nHeight)->v, (m_pColors+w+(h)*m_nHeight)->b);
	glVertex3d(w, h, *(m_pMap + w + h*m_nWidth));
}

double HeightMap::GetZValue(int w, int h)
{
	return *(m_pMap + w + h*m_nWidth);
}
