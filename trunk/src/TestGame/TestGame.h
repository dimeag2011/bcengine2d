#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "Engine.h"
#include "TestScene.h"

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

	Sprite* m_pkPacman;
	Sprite* m_pkGhost1;
	//Texture::Ptr m_pkTexture;
	TestScene* m_pkScene1;
};
#endif