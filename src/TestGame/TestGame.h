#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "Game.h"
//#include "Shape.h"
#include "Box.h"
#include "Circle.h"
#include "Triangle.h"

class TestGame : public Game
{
public:

	// constructor / destructor
	TestGame (HINSTANCE hInstance);
	~TestGame ();

protected:

	// derived from Game
	bool OnStartUp();
	bool OnLoop();
	bool OnShutDown();

	Box* m_pkBox;
	Circle* m_pkCirc;
	Triangle* m_pkTri;

};
#endif