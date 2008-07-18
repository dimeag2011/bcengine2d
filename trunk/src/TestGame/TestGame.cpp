//----------------------------------------------------------------
#include "TestGame.h"
//----------------------------------------------------------------
TestGame::TestGame (HINSTANCE hInstance)
:
Game (hInstance),
m_pkScene1(NULL),
m_pkScene2(NULL)
{

}
//----------------------------------------------------------------
TestGame::~TestGame ()
{

}
//----------------------------------------------------------------
bool TestGame::OnStartUp ()
{
	Importer* pkImporter = getImporter();

	m_pkScene1 = new TestScene();

	m_pkScene1->init("Escena1", pkImporter, m_pkInput, m_pkSound, m_pkRender);
	
	addSceneToUpdate(m_pkScene1);
	addSceneToDraw(m_pkScene1);

	m_pkScene2 = new TestScene2();

	m_pkScene2->init("Escena2", pkImporter, m_pkInput, m_pkSound, m_pkRender);
	
	addSceneToUpdate(m_pkScene2);
	addSceneToDraw(m_pkScene2);

	return true;
}
//----------------------------------------------------------------
bool TestGame::OnLoop ()
{
/*


	if (m_pkInput->getKeyDown(DIK_A))
		m_pkCirc->setRotation(m_pkCirc->getRotation() + 0.1f);

	if (m_pkInput->getKeyDown(DIK_Z))
		m_pkCirc->setRotation(m_pkCirc->getRotation() - 0.1f);

	if (m_pkInput->getKeyDown(DIK_S))
		m_pkCirc->setDim(m_pkCirc->getDimW() + 0.1f, m_pkCirc->getDimH() + 0.1f);

	if (m_pkInput->getKeyDown(DIK_X))
		m_pkCirc->setDim(m_pkCirc->getDimW() - 0.1f, m_pkCirc->getDimH() - 0.1f);
*/
	UpdateViewPortPos();

	return false;
}
//----------------------------------------------------------------
bool TestGame::OnShutDown ()
{
	if (m_pkScene1)
	{
		m_pkScene1->deinit();
		delete m_pkScene1;
		m_pkScene1=NULL;
	}

	if (m_pkScene2)
	{
		m_pkScene2->deinit();
		delete m_pkScene2;
		m_pkScene2=NULL;
	}
	return true;
}
//----------------------------------------------------------------
void TestGame::UpdateViewPortPos()
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
