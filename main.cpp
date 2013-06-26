#include <SDL/SDL.h>
#include <cstdlib>
#include <vector>

#include "Engine.hpp"



int main(int argc, char *argv[])
{
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);

    Engine MyEngine;
    Cube* CubeA = MyEngine.CreateCube(2.0, Vect3D<double>(0.0,0.0,0.0), 45);
    Cube* CubeB = MyEngine.CreateCube(2.0, Vect3D<double>(4.0,0.0,0.0), 20, 90);

    HeightMap* HMapA = MyEngine.CreateHeightMap("test.map", Vect3D<double>(-3.0,-3.0,-3.0));


    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    Uint32 start_time;

    while(1)
    {
        start_time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_MOUSEBUTTONDOWN:

                break;
            }
        }
        current_time = SDL_GetTicks();
		ellapsed_time = current_time - last_time;
		last_time = current_time;

		CubeA->SetFacing(CubeA->GetFacing()+1);
		CubeA->SetPitch(CubeA->GetPitch()+1);

		HMapA->SetFacing(HMapA->GetFacing()-1);

        MyEngine.RenderAll();
        SDL_GL_SwapBuffers();

        ellapsed_time = SDL_GetTicks() - start_time;
        if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        }

    }

    return 0;
}
