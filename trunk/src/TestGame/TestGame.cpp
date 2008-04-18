//----------------------------------------------------------------
#include "TestGame.h"
//----------------------------------------------------------------
TestGame::TestGame (HINSTANCE hInstance)
:
Game (hInstance)
{
	
}
//----------------------------------------------------------------
TestGame::~TestGame ()
{

}
//----------------------------------------------------------------
bool TestGame::OnStartUp ()
{
	m_pkShape = new Shape(m_pkShape->TRIANGLE);
	m_pkShape->setDim(100,100);
	m_pkShape->setPos(50,50);
	m_pkShape->setRotation(45);

	addEntity(m_pkShape);

	return true;
}
//----------------------------------------------------------------
bool TestGame::OnLoop ()
{
	return false;
}
//----------------------------------------------------------------
bool TestGame::OnShutDown ()
{
	return true;
}
