//----------------------------------------------------------------
#include "GameScene.h"
//----------------------------------------------------------------
GameScene::GameScene ()
:
m_pkControl(NULL)
{
}
//----------------------------------------------------------------
GameScene::~GameScene ()
{
}
//----------------------------------------------------------------
bool GameScene::onInit (Importer* pkImporter, Renderer* pkRenderer)
{
	m_pkControl = new Controller(pkImporter, this);

	return true;
}
//----------------------------------------------------------------
bool GameScene::onUpdate (float fTimeBetweenFrames)
{
	m_pkControl->Update();
	return true;
}
//----------------------------------------------------------------
void GameScene::onDraw (Renderer* pkRenderer) const
{
}
//----------------------------------------------------------------
bool GameScene::onDeinit ()
{
	if (m_pkControl)
	{
		delete m_pkControl;
		m_pkControl = NULL;
	}
	return true;
}
//----------------------------------------------------------------
