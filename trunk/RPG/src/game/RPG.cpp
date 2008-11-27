//----------------------------------------------------------------
#include "RPG.h"
//----------------------------------------------------------------
BasicGame::BasicGame (HINSTANCE hInstance)
:
Game (hInstance),
m_pkScene1(NULL),
m_pkScene2(NULL)

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

	//removeSceneToDraw();
	return true;
}
//----------------------------------------------------------------
bool BasicGame::OnLoop ()
{
	UpdateViewPortPos();
	UpdateCharacterSheet();

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

	if (m_pkScene2)
	{
		delete m_pkScene2;
		m_pkScene2=NULL;
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
//-----------------------------------------------------------------------------------------
void BasicGame::UpdateCharacterSheet()
{
	if (m_pkInput->getKeyEventDown(DIK_C))
	{
		
		Importer* pkImporter2 = getImporter();
		m_pkScene2 = new TestScene2(m_pkScene1->getCharacter());
		
		m_pkScene2->init("Escena2", pkImporter2, m_pkInput, m_pkSound, m_pkRender);
			
		removeSceneToUpdate(m_pkScene1);
		removeSceneToDraw(m_pkScene1);
		addSceneToDraw(m_pkScene2);
	}
	if(m_pkInput->getKeyEventDown(DIK_Z))
	{
		addSceneToUpdate(m_pkScene1);
		addSceneToDraw(m_pkScene1);
		removeSceneToDraw(m_pkScene2);
		//m_pkScene2->deinit();
		//delete m_pkScene2;
		//m_pkScene2=NULL;
	}
}
//-----------------------------------------------------------------------------------------