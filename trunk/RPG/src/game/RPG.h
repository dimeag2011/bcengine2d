#ifndef BASIC_GAME_H
#define BASIC_GAME_H

#include "Engine.h"
#include "TestScene.h"
//#include "TestScene2.h"


class BasicGame : public Game
{
public:

	// constructor / destructor
	BasicGame (HINSTANCE hInstance);
	~BasicGame ();

protected:

	bool OnStartUp();
	bool OnLoop();
	bool OnShutDown();

	void UpdateViewPortPos();

	TestScene* m_pkScene1;
	//TestScene2* m_pkScene2;

};
#endif