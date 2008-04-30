#ifndef GAME_H
#define GAME_H
//--------------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include "Renderer.h"
#include "Entity2D.h"
#include "Timer.h"

#include "Structs.h"
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

private:
	Renderer* m_pkRender;
	Window* m_pkWindows;
	HINSTANCE m_hInstance;

	std::vector<Entity2D*> m_apkEntities;

};
//--------------------------------------------------------------------------------
#endif //GAME_H 