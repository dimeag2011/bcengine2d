//----------------------------------------------------------------
#include "RPG.h"
//----------------------------------------------------------------
BasicGame::BasicGame (HINSTANCE hInstance)
:
Game (hInstance),
m_pkScene1(NULL)
{
	
}
//----------------------------------------------------------------
BasicGame::~BasicGame ()
{

}
//----------------------------------------------------------------
bool BasicGame::OnStartUp ()
{
	Importer* pkImporter = getImporter();

	 m_pkScene1 = new TestScene();

	m_pkScene1->init("Escena1", pkImporter, m_pkInput, m_pkSound, m_pkRender);

	addSceneToUpdate(m_pkScene1);
	addSceneToDraw(m_pkScene1);
	return true;
}
//----------------------------------------------------------------
bool BasicGame::OnLoop ()
{
	UpdateViewPortPos();

	return false;
}
//----------------------------------------------------------------
bool BasicGame::OnShutDown ()
{
	if (m_pkScene1)
	{
		m_pkScene1->deinit();
		delete m_pkScene1;
		m_pkScene1=NULL;
	}
	
	return true;
}
//----------------------------------------------------------------
void BasicGame::UpdateViewPortPos()
{
	if (m_pkInput->getKeyDown(DIK_ADD))
		m_pkRender->setViewerAngle(m_pkRender->getViewerAngle() + 0.1f);

	if (m_pkInput->getKeyDown(DIK_SUBTRACT))
		m_pkRender->setViewerAngle(m_pkRender->getViewerAngle() - 0.1f);

	if (m_pkInput->getKeyDown(DIK_NUMPAD4))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX -= 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD6))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX += 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD2))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fY -= 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD8))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fY += 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD7))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX -= 1.0f;
		fY += 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD9))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX += 1.0f;
		fY += 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD3))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX += 1.0f;
		fY -= 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD1))
	{
		float fX, fY;
		m_pkRender->getViewerPosition(fX, fY);
		fX -= 1.0f;
		fY -= 1.0f;
		m_pkRender->setViewerPosition(fX, fY);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD5))
	{
		m_pkRender->setViewerAngle(0);
		m_pkRender->setViewerPosition(0,0);
	}

}
