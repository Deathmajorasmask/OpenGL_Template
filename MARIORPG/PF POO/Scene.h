#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "TerrainEx.h"
#include "Model.h"
#include "Camera.h"
#include <time.h>
#include "OpenMove.h"


class Scene : public Camera
{
public:
	SkyDome* skyDay;
	TerrainEx* terrainEx;

	EDXFramework::Model* marprin;
	Scene(HWND hWnd)
	{

		GLfloat AmbMat[] = { 1, 1, 1, 1 };
		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		GLfloat diffuse[] = { 1.0f, 0.5f, 0.0f, 0.5f };
		GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);
		glEnable(GL_COLOR_MATERIAL);

		skyDay = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//Skymario.jpg");
		terrainEx = new TerrainEx(hWnd, L"Imagenes//terrenoplano.bmp", L"Imagenes//cuadricula.jpg", L"Imagenes//texterr.jpg", 400, 400);
		marprin = new EDXFramework::Model("Modelos//Characters//MarioPrin1.obj", "Modelos//Characters//mario_main.bmp", 1);

		cameraInitialize();
	}

	void render(HDC hDC, HWND hWnd)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);

		cameraUpdate();

		glPushMatrix();
		OpenMove::traslate(0, -10, 0);
		//OpenMove::scale(.5, .5, .5);
		terrainEx->Draw();
		glPopMatrix();
		
		glPushMatrix();
		OpenMove::traslate(0,0,0);
		marprin->Draw();
		glPopMatrix();

		SwapBuffers(hDC);
	}

};
#endif
