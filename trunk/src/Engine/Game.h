#ifndef GAME_H
#define GAME_H
//--------------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include "Renderer.h"
#include "Entity2D.h"
#include "Timer.h"
#include "Input.h"
#include "DirectInput.h"

#include "Structs.h"
//--------------------------------------------------------------------------------
class Importer;
//--------------------------------------------------------------------------------
class ENGINE_API Game
{

public:
	Game(HINSTANCE hInstance);
	virtual ~Game();

	//engine functions
	bool StartUp();
	bool Loop();
	bool ShutDown();

	void addEntity(Entity2D* pkEntity);

	Timer m_kTimer;

protected:
	//game virtual functions to be overloaded in game
	virtual bool OnStartUp()=0;
	virtual bool OnLoop()=0;
	virtual bool OnShutDown()=0;

	//the input
	Input* m_pkInput;

// resources
public:
	Importer* getImporter ();

private:
	Renderer* m_pkRender;
	Window* m_pkWindows;
	HINSTANCE m_hInstance;
	Importer* m_pkImporter;

	vector<Entity2D*> m_apkEntities;

};
//----------------------------------------------------------------
#include "Game.inl"
//--------------------------------------------------------------------------------
#endif //GAME_H 