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

	if (!(m_pkScene1->init("Escena1", pkImporter, m_pkInput, m_pkSound, m_pkRender)))
		return false;
	
	addSceneToUpdate(m_pkScene1);
	addSceneToDraw(m_pkScene1);
/*
	m_pkScene2 = new TestScene2();

	m_pkScene2->init("Escena2", pkImporter, m_pkInput, m_pkSound, m_pkRender);
	
	addSceneToUpdate(m_pkScene2);
	addSceneToDraw(m_pkScene2);
*/
	m_pkCam1 = new Camera(m_pkRender);
	//m_pkCam1->SetLookPos(
	setCurrentCamera(m_pkCam1);

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

	if (m_pkCam1)
	{
		delete m_pkCam1;
		m_pkCam1 = NULL;
	}

	return true;
}
//----------------------------------------------------------------
void TestGame::UpdateViewPortPos()
{
	if (m_pkInput->getKeyDown(DIK_W))
		m_pkCam1->MoveForward(0.1f);

	if (m_pkInput->getKeyDown(DIK_S))
		m_pkCam1->MoveForward(-0.1f);

	if (m_pkInput->getKeyDown(DIK_D))
		m_pkCam1->MoveRight(0.1f);

	if (m_pkInput->getKeyDown(DIK_A))
		m_pkCam1->MoveRight(-0.1f);

	if (m_pkInput->getKeyDown(DIK_Q))
		m_pkCam1->MoveUp(0.1f);

	if (m_pkInput->getKeyDown(DIK_E))
		m_pkCam1->MoveUp(-0.1f);

	if (m_pkInput->getKeyDown(DIK_UP))
		m_pkCam1->RotateDown(-0.01f);

	if (m_pkInput->getKeyDown(DIK_DOWN))
		m_pkCam1->RotateDown(0.01f);

	if (m_pkInput->getKeyDown(DIK_RIGHT))
		m_pkCam1->RotateRight(0.01f);

	if (m_pkInput->getKeyDown(DIK_LEFT))
		m_pkCam1->RotateRight(-0.01f);
	//m_pkCam1->RotateRight(m_pkInput->getMouseRelPosX());
	//m_pkCam1->RotateDown(m_pkInput->getMouseScrAbsPosX());

	/* OLD CAMERA CODE
	if (m_pkInput->getKeyDown(DIK_A))
		m_pkCam1->SlideCamera(0.1,0);

	if (m_pkInput->getKeyDown(DIK_D))
		m_pkCam1->SlideCamera(-0.1,0);

	if (m_pkInput->getKeyDown(DIK_Q))
		m_pkCam1->SlideCamera(0,0.1);

	if (m_pkInput->getKeyDown(DIK_E))
		m_pkCam1->SlideCamera(0,-0.1);

	if (m_pkInput->getKeyDown(DIK_W))
		m_pkCam1->MoveCamera(0.1);

	if (m_pkInput->getKeyDown(DIK_S))
		m_pkCam1->MoveCamera(-0.1);

	m_pkCam1->RotateCamera(-((float)(m_pkInput->getMouseRelPosX())/100), -((float)(m_pkInput->getMouseRelPosY())/100));
	*/

	/* BACK UP CAMERA CODE
	if (m_pkInput->getKeyDown(DIK_ADD))
		m_pkCam1->setRoll(m_pkCam1->getRoll() +	0.01f);	

	if (m_pkInput->getKeyDown(DIK_SUBTRACT))
		m_pkCam1->setRoll(m_pkCam1->getRoll() -	0.01f);	

		
	if (m_pkInput->getKeyDown(DIK_NUMPAD4))
	{
		m_pkCam1->Strafe(-0.1f);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD6))
	{
		m_pkCam1->Strafe(0.1f);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD2))
	{
		m_pkCam1->Fly(-0.1f);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD8))
	{
		m_pkCam1->Fly(0.1f);
	}
	
	if (m_pkInput->getKeyDown(DIK_DECIMAL))
	{
		m_pkCam1->Walk(-0.1f);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD0))
	{
		m_pkCam1->Walk(0.1f);
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD7))
	{
		m_pkCam1->setPitch(m_pkCam1->getPitch() + 0.01f);	
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD1))
	{
		m_pkCam1->setPitch(m_pkCam1->getPitch() - 0.01f);	
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD9))
	{
		m_pkCam1->setYaw(m_pkCam1->getYaw() + 0.01f);	
	}

	if (m_pkInput->getKeyDown(DIK_NUMPAD3))
	{
		m_pkCam1->setYaw(m_pkCam1->getYaw() - 0.01f);	
	}
	*/
	
	/*
	if (m_pkInput->getKeyDown(DIK_NUMPAD5))
	{
		m_pkRender->setViewerAngle(0);
		m_pkRender->setViewerPosition(0,0);
	}
	*/

}
