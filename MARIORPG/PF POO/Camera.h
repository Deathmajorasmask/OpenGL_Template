#ifndef __Camera
#define __Camera

class Camera
{

public:

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.01f;
	float sensitivity = 30.0f;
	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;
	// Position - Orientation - Up
	GLdouble px = 0,  py = 0, pz = 0, dx = 0, dy = 0, dz = -1, ux = 0, uy = 1, uz = 0;

	int camind = 0;

	Camera()
	{
		
	}

	void cameraInitialize()
	{
		px = 0, py = 5, pz = 0, dx = 0, dy = 0, dz = 0;
		ux = 0, uy = 1, uz = 0;
		//gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
		gluLookAt(px, py, pz, dx + px, dy + py, dz + pz, ux, uy, uz);
	}
	//Las coordenadas 'P' son el Eye (position), Coordenadas 'D' (observation)

	void cameraUpdate()
	{
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	// E
	void moveUp() {
		py += 1;
		dy += 1;

	}
	// Q
	void moveDown() {
		py -= 1;
		dy -= 1;
	}

	// A
	void moveLeft()
	{

		px -= 1;
		dx -= 1;
	}

	// D
	void moveRight()
	{

		px += 1;
		dx += 1;

	}

	// S
	void moveForward()
	{

		pz += 1;
		dz += 1;

	}

	// W
	void moveBackward()
	{

		pz -= 1;
		dz -= 1;

	}

	void turnRight()
	{
		//debe empezar viendo a z negativa, si no gira al reves
		if (dx < 15 + px && camind == 0)
			dx += 1;
		if (dx == 15 + px && camind == 0)
			camind = 1;
		if (dz < 15 + pz && camind == 1)
			dz += 1;
		if (dz == 15 + pz && camind == 1)
			camind = 2;
		if (dx > -15 + px && camind == 2)
			dx -= 1;
		if (dx == -15 + px && camind == 2)
			camind = 3;
		if (dz > -15 + pz && camind == 3)
			dz -= 1;
		if (dz == -15 + pz && camind == 3)
			camind = 0;

	}

	void turnLeft()
	{

		//debe empezar viendo a z negativa, si no gira al reves
		if (dx > -15 + px && camind == 0)
			dx -= 1;
		if (dx == -15 + px && camind == 0)
			camind = 1;
		if (dz < 15 + pz && camind == 1)
			dz += 1;
		if (dz == 15 + pz && camind == 1)
			camind = 2;
		if (dx < 15 + px && camind == 2)
			dx += 1;
		if (dx == 15 + px && camind == 2)
			camind = 3;
		if (dz > -15 + pz && camind == 3)
			dz -= 1;
		if (dz == -15 + pz && camind == 3)
			camind = 0;

	}

	void turnUp()
	{

		if (dy < 50 + py)
		{
			dy += 1;
		}

	}

	void turnDown()
	{

		if (dy > -50 + py)
		{
			dy -= 1;
		}

	}
};
#endif