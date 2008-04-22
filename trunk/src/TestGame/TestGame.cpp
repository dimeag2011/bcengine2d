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
	m_pkShape = new Shape(m_pkShape->BOX);
	m_pkShape->setDim(100,100);
	m_pkShape->setPos(0,0);
	m_pkShape->setRotation(45);
	m_pkShape->setColor(155,0,155);
	int r;
	int g;
	int b;
	m_pkShape->getColor(r, g, b);


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
