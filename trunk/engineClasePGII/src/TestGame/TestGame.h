#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "Engine.h"
#include "TestScene.h"
#include "TestScene2.h"

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

	void UpdateViewPortPos();

	//Texture::Ptr m_pkTexture;
	TestScene* m_pkScene1;
	TestScene2* m_pkScene2;
	Map* m_pkMapa;
	Camera* m_pkCam1;

};
#endif