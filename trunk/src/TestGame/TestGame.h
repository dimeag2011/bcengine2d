#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "Game.h"
#include "Shape.h"

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

	Shape* m_pkShape;

};
#endif