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

	m_pkBox = new Box();
	m_pkBox->setPos(0,0);
	m_pkBox->setColor(255,255,255);
	m_pkBox->setDim(100,100);

	addEntity(m_pkBox);

	m_pkCirc = new Circle(145);
	m_pkCirc->setPos(150, 150);
	m_pkCirc->setDim(50,50);
	m_pkCirc->setColor(55,55,55);

	addEntity(m_pkCirc);

	m_pkTri = new Triangle();
	m_pkTri->setPos(-100, -100);
	m_pkTri->setDim(100,100);
	m_pkTri->setColor(100,100,0);

	addEntity(m_pkTri);

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
