#include "Game.h"
#include "Importer.h"
//--------------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_pkRender(NULL),
m_pkWindows(NULL),
m_hInstance(hInstance),
m_pkImporter(NULL),
m_pkInput(NULL)
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

	if (!OnStartUp())
		return false;

	m_kTimer.FirstMeasure();

	return true;
}
//--------------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkRender);

	m_pkInput->reacquire();

	// update all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->update(m_kTimer.GetDT());
	}

	m_pkRender->StartFrame();

	// draw all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->draw(m_pkRender);
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

	return true;
}
//--------------------------------------------------------------------------------