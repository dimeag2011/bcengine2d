#include "Game.h"
//--------------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_pkRender(NULL),
m_pkWindows(NULL),
m_hInstance(hInstance)
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

	if (!OnStartUp())
		return false;

	m_kTimer.FirstMeasure();

	return true;
}
//--------------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkRender);

	m_pkRender->StartFrame();

	// draw all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->draw(m_pkRender);
	}

	if (OnLoop())
		return true;

	m_pkRender->EndFrame();

	m_pkWindows->SetWindowTitle(strcat("Engine v0.1 - FPS", itoa(m_kTimer.GetFPS())));

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

	return true;
}
//--------------------------------------------------------------------------------
void Game::addEntity(Entity2D* pkEntity)
{
	assert(pkEntity);

	m_apkEntities.push_back(pkEntity);
}
//----------------------------------------------------------------