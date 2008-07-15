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
#include "Scene.h"
#include "Sound.h"

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


protected:
	//game virtual functions to be overloaded in game
	virtual bool OnStartUp()=0;
	virtual bool OnLoop()=0;
	virtual bool OnShutDown()=0;

	Input* m_pkInput;
	Renderer* m_pkRender;
	Importer* m_pkImporter;
	Timer m_kTimer;
	Sound* m_pkSound;

	// resources
public:
	Importer* getImporter ();

private:
	Window* m_pkWindows;
	HINSTANCE m_hInstance;

	vector<Entity2D*> m_apkEntities;

	//scenes
public:

private:
	typedef map< string, Scene* > SceneMap;
	typedef map< string, Scene* >::iterator SceneMapIt;
	SceneMap m_kpaSceneToUpdate;
	SceneMap m_kpaSceneToDraw;

public:
	bool addSceneToUpdate(Scene* pkScene);
	bool removeSceneToUpdate(Scene* pkScene);
	bool addSceneToDraw(Scene* pkScene);
	bool removeSceneToDraw(Scene* pkScene);

};
//----------------------------------------------------------------
#include "Game.inl"
//--------------------------------------------------------------------------------
#endif //GAME_H 