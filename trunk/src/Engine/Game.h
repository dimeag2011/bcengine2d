#ifndef GAME_H
#define GAME_H
//--------------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include "Renderer.h"
#include "Entity2D.h"

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

protected:
	//game virtual functions to be overloaded in game
	virtual bool OnStartUp()=0;
	virtual bool OnLoop()=0;
	virtual bool OnShutDown()=0;

private:
	Renderer* m_pkRender;
	Window* m_pkWindows;
	HINSTANCE m_hInstance;

/*
   template class ENGINE_API std::allocator<Entity2D*>
   template class ENGINE_API std::vector<Entity2D*,
      std::allocator<Entity2D*> >;
*/

	std::vector<Entity2D*> m_apkEntities;

	//ColorVertex Vertices[3];
};
//--------------------------------------------------------------------------------
#endif //GAME_H 