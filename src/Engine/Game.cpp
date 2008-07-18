#include "Game.h"
#include "Importer.h"
//--------------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_pkRender(NULL),
m_pkWindows(NULL),
m_hInstance(hInstance),
m_pkImporter(NULL),
m_pkInput(NULL),
m_pkSound(NULL)
{

}
//--------------------------------------------------------------------------------
Game::~Game()
{

}
//--------------------------------------------------------------------------------
bool Game::StartUp()
{
	//variable temporal para almacenar el hWnd recibirlo del createWindow y 
	//pasarlo a InitDX
	HWND hWnd=NULL;

	m_pkWindows = new Window(m_hInstance);

	if (!m_pkWindows)
		return false;

	m_pkWindows->createWindow(800, 600, hWnd);

	m_pkRender = new Renderer(hWnd);

	if(!m_pkRender)
		return false;

	if(!m_pkRender->InitDX(hWnd))
		return false;

	// create loader
	m_pkImporter = new Importer(m_pkRender);

	// create input
	m_pkInput = new DirectInput(m_hInstance, hWnd);

	if(!m_pkInput->init())
		return false;

	m_pkSound = new Sound();

	if(!m_pkSound->startSoundEngine())
		return false;

	if (!OnStartUp())
		return false;

	m_kTimer.FirstMeasure();

	m_pkMapa = new Map(m_pkRender);
	m_pkMapa->loadMap("../../res/MapaPrueba/tilesetFixed.xml","../../res/MapaPrueba/Mapa.xml");

	return true;
}
//--------------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkRender);

	m_pkInput->reacquire();

	m_pkMapa->update(m_kTimer.GetDT());

	// update all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->update(m_kTimer.GetDT());
	}

	// update a las scenes del ToUpdate map
	SceneMapIt itActualUpdate;
	SceneMapIt itEndUpdate;

	for(itActualUpdate = m_kpaSceneToUpdate.begin(), itEndUpdate = m_kpaSceneToUpdate.end();
		itActualUpdate != itEndUpdate; itActualUpdate++)
	{
		Scene* pkSceneToUpdate = itActualUpdate->second;
		pkSceneToUpdate->update(m_kTimer.GetDT());
	}

	m_pkRender->StartFrame();

	m_pkMapa->draw();

	// draw all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->draw(m_pkRender);
	}

	// dibujo las scenes del ToDraw map
	SceneMapIt itActualDraw;
	SceneMapIt itEndDraw;

	for(itActualDraw = m_kpaSceneToDraw.begin(), itEndDraw = m_kpaSceneToDraw.end();
		itActualDraw != itEndDraw; itActualDraw++)
	{
		Scene* pkSceneToDraw = itActualDraw->second;
		pkSceneToDraw->draw(m_pkRender);
	}

	if (OnLoop())
		return true;

	m_pkRender->EndFrame();

	stringstream s;
	s << "Engine v0.1 - FPS:" << m_kTimer.GetFPS();
	//m_pkWindows->SetWindowTitle(strcat("Engine v0.1 - FPS", itoa(m_kTimer.GetFPS())));
	m_pkWindows->SetWindowTitle(s.str().c_str());

	m_kTimer.Measure();

	return false;
}
//--------------------------------------------------------------------------------
bool Game::ShutDown()
{
	if (!OnShutDown())
		return false;

	if (m_pkWindows)
		delete m_pkWindows;

	m_pkWindows = NULL;

	m_pkInput->deinit();
	delete m_pkInput;
	m_pkInput = NULL;

	if(!m_pkSound->stopSoundEngine())
		return false;

	delete m_pkSound;
	m_pkSound = NULL;

	return true;
}
//--------------------------------------------------------------------------------
bool Game::addSceneToUpdate(Scene* pkScene)
{
	string kSceneName = pkScene->getName();
	//si la escena no tiene nombre no hago nada
	if (kSceneName == "")
		return false;

	//busco la escena en el ToUpdate map
	SceneMapIt itScene = m_kpaSceneToUpdate.find(kSceneName);

	//si la encuentro no hago nada
	if (itScene != m_kpaSceneToUpdate.end())
		return false;

	//si no la encuentro la agrego
	m_kpaSceneToUpdate[kSceneName]=pkScene;
		
	return true;
}
//--------------------------------------------------------------------------------
bool Game::removeSceneToUpdate(Scene* pkScene)
{
	string kSceneName = pkScene->getName();
	//si la escena no tiene nombre no hago nada
	if (kSceneName == "")
		return false;

	//busco la escena en el ToUpdate map
	SceneMapIt itScene = m_kpaSceneToUpdate.find(kSceneName);

	//si no la encuentro no hago nada
	if (itScene == m_kpaSceneToUpdate.end())
		return false;

	//si la encuentro la borro
	m_kpaSceneToUpdate.erase(itScene);
	
	return true;
}
//--------------------------------------------------------------------------------
bool Game::addSceneToDraw(Scene* pkScene)
{
	string kSceneName = pkScene->getName();
	//si la escena no tiene nombre no hago nada
	if (kSceneName == "")
		return false;

	//busco la escena en el ToDraw map
	SceneMapIt itScene = m_kpaSceneToDraw.find(kSceneName);

	//si la encuentro no hago nada
	if (itScene != m_kpaSceneToDraw.end())
		return false;

	//si no la encuentro la agrego
	m_kpaSceneToDraw[kSceneName]=pkScene;
		
	return true;
}
//--------------------------------------------------------------------------------
bool Game::removeSceneToDraw(Scene* pkScene)
{
	string kSceneName = pkScene->getName();
	//si la escena no tiene nombre no hago nada
	if (kSceneName == "")
		return false;

	//busco la escena en el ToDraw map
	SceneMapIt itScene = m_kpaSceneToDraw.find(kSceneName);

	//si no la encuentro no hago nada
	if (itScene == m_kpaSceneToDraw.end())
		return false;

	//si la encuentro la borro
	m_kpaSceneToDraw.erase(itScene);
	
	return true;
}
//--------------------------------------------------------------------------------
