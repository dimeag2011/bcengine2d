//----------------------------------------------------------------
#include "TestGame.h"
//----------------------------------------------------------------
TestGame::TestGame (HINSTANCE hInstance)
:
Game (hInstance),
m_pkBox(NULL),
m_pkCirc(NULL),
m_pkTri(NULL),
m_pkPacman(new Sprite()),
m_pkGhost1(new Sprite())
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

	if( !pkImporter->importResources("../../res/sprite.xml") )
		return false;

	m_pkBox = new Box();
	m_pkBox->setPos(0,0);
	m_pkBox->setColor(0,65,220);
	m_pkBox->setDim(100,100);
	m_pkBox->setMoveSpeed(0.05f);
	m_pkBox->setMoveAngle(45);
	m_pkBox->setMoving(true);

	addEntity(m_pkBox);

	m_pkCirc = new Circle(145);
	m_pkCirc->setPos(150, 150);
	m_pkCirc->setDim(100,100);
	m_pkCirc->setColor(255,255,255);
	m_pkCirc->setNumeroCaras(50);
	m_pkCirc->setDim(200,100);

	addEntity(m_pkCirc);

	m_pkTri = new Triangle();
	m_pkTri->setPos(-150, -150);
	m_pkTri->setDim(100,100);
	m_pkTri->setColor(200,120,0);
	//m_pkTri->setBBPos(50,50);

	addEntity(m_pkTri);

	// initialize pacman
	if( pkImporter->createSprite("Pacman", m_pkPacman) )
	{
		// set properties
		m_pkPacman->setName("el pacman loco");
		m_pkPacman->setDim(50,50);
		m_pkPacman->setPos(-100,150);
		
		// set animation
		if( m_pkPacman->setAnimation("Eat") )
			m_pkPacman->getAnimation()->play();

		m_pkPacman->setMoveSpeed(0.15f);
		m_pkPacman->setMoving(true);
	
		// add it to the scene
		addEntity(m_pkPacman);
	}

	// initialize ghost
	if( pkImporter->createSprite("Fantasma", m_pkGhost1) )
	{
		// set properties
		m_pkGhost1->setName("el fantasma loco");
		m_pkGhost1->setDim(50,50);
		m_pkGhost1->setPos(-200,0);

		addEntity(m_pkGhost1);
	}

	return true;
}
//----------------------------------------------------------------
bool TestGame::OnLoop ()
{
	if(m_pkPacman->checkCollision(m_pkCirc))
	{

		//m_pkPacman->setMoveSpeed(0.0f);
		m_pkPacman->setMoveAngle(180.0);
		m_pkPacman->setRotation(180.0);
	}
	if(m_pkBox->checkCollision(m_pkCirc))
	{

		//m_pkPacman->setMoveSpeed(0.0f);
		m_pkBox->setMoveAngle(m_pkBox->getMoveAngle()*-1);
		//m_pkBox->setRotation(180.0);
	}
	return false;
}
//----------------------------------------------------------------
bool TestGame::OnShutDown ()
{
	return true;
}
