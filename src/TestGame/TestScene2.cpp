//----------------------------------------------------------------
#include "TestScene2.h"
//----------------------------------------------------------------
TestScene2::TestScene2 ()
:
m_pkBox(NULL),
m_pkCirc(NULL),
m_pkTri(NULL),
m_pkPacman(new Sprite()),
m_pkGhost1(new Sprite()),
m_pkMapa(NULL)
{
	/***/
}
//----------------------------------------------------------------
TestScene2::~TestScene2 ()
{
	/***/
}
//----------------------------------------------------------------
bool TestScene2::onInit (Importer* pkImporter, Renderer* pkRenderer)
{
	if( !pkImporter->importResources("../../res/sprite.xml") )
		return false;

	m_pkBox = new Box();
	m_pkBox->setPos(0,0,1.0f);
	m_pkBox->setColor(0,65,220);
	m_pkBox->setDim(100,100);
	m_pkBox->setMoveSpeed(0.05f);
	m_pkBox->setMoveAngle(45);
	m_pkBox->setMoving(true);

	addEntity(m_pkBox);

	m_pkCirc = new Circle(145);
	m_pkCirc->setPos(150, 150,1.0f);
	m_pkCirc->setDim(100,100);
	m_pkCirc->setColor(0,0,0);
	m_pkCirc->setNumeroCaras(50);
	m_pkCirc->setVertexColor(0,255,255,255);
	m_pkCirc->setDim(200,100);
	m_pkCirc->setVisibleBB(true);
	
	addEntity(m_pkCirc);

	m_pkTri = new Triangle();
	m_pkTri->setPos(-150, -150,1.0f);
	m_pkTri->setDim(100,100);
	m_pkTri->setColor(200,0,0);
	m_pkTri->setVertexColor(0,100,20,0);
	m_pkTri->setVertexColor(1,100,20,0);
	m_pkTri->setHFlip(!m_pkTri->getHFlip());
	m_pkTri->setVFlip(!m_pkTri->getVFlip());
	//m_pkTri->setBBPos(50,50);

	addEntity(m_pkTri);

	// initialize pacman
	if( pkImporter->createSprite("Pacman", m_pkPacman) )
	{
		// set properties
		m_pkPacman->setName("el pacman loco");
		m_pkPacman->setDim(50,50);
		m_pkPacman->setPos(-100,150,0.0f);
		
		// set animation
		if( m_pkPacman->setAnimation("Eat") )
			m_pkPacman->getAnimation()->play();

		m_pkPacman->setMoveSpeed(0.15f);
		//m_pkPacman->setMoving(true);
	
		// add it to the scene
		addEntity(m_pkPacman);
	}

	// initialize ghost
	if( pkImporter->createSprite("Fantasma", m_pkGhost1) )
	{
		// set properties
		m_pkGhost1->setName("el fantasma loco");
		m_pkGhost1->setDim(50,50);
		m_pkGhost1->setPos(-200,0,-1.0f);

		addEntity(m_pkGhost1);
	}

	m_pkMapa = new Map(pkRenderer);
	m_pkMapa->loadMap("../../res/MapaPrueba/tilesetFixed.xml","../../res/MapaPrueba/Mapa.xml");
	m_pkMapa->setPos(500,500);
	m_pkMapa->setLayerVisible(0,false);
	setCurrentMap(m_pkMapa);
	

	m_pkSound->playSoundFile("../../res/Sounds/bell.wav");

	return true;
}
//----------------------------------------------------------------
bool TestScene2::onUpdate (float fTimeBetweenFrames)
{
	updateCollitions();
	updatePacManInput();
	updateSounds();
	
	return true;
}
//----------------------------------------------------------------
void TestScene2::updatePacManInput ()
{
	if (m_pkInput->getKeyEventUp(DIK_RIGHT))
		m_pkPacman->setMoving(false);
	if (m_pkInput->getKeyEventUp(DIK_LEFT))
		m_pkPacman->setMoving(false);
	if (m_pkInput->getKeyEventUp(DIK_DOWN))
		m_pkPacman->setMoving(false);
	if (m_pkInput->getKeyEventUp(DIK_UP))
		m_pkPacman->setMoving(false);

	if (m_pkInput->getKeyDown(DIK_UP))
	{
		m_pkPacman->setRotation(90);
		m_pkPacman->setMoveAngle(90);
		m_pkPacman->setMoving(true);
	}


	if (m_pkInput->getKeyDown(DIK_DOWN))
	{
		m_pkPacman->setRotation(270);
		m_pkPacman->setMoveAngle(270);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_LEFT))
	{
		m_pkPacman->setRotation(180);
		m_pkPacman->setMoveAngle(180);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_RIGHT))
	{
		m_pkPacman->setRotation(0);
		m_pkPacman->setMoveAngle(0);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_RIGHT) && m_pkInput->getKeyDown(DIK_UP))
	{
		m_pkPacman->setRotation(45);
		m_pkPacman->setMoveAngle(45);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_RIGHT) && m_pkInput->getKeyDown(DIK_DOWN))
	{
		m_pkPacman->setRotation(315);
		m_pkPacman->setMoveAngle(315);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_LEFT) && m_pkInput->getKeyDown(DIK_UP))
	{
		m_pkPacman->setRotation(135);
		m_pkPacman->setMoveAngle(135);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_LEFT) && m_pkInput->getKeyDown(DIK_DOWN))
	{
		m_pkPacman->setRotation(225);
		m_pkPacman->setMoveAngle(225);
		m_pkPacman->setMoving(true);
	}

	if (m_pkInput->getKeyDown(DIK_DOWN) && m_pkInput->getKeyDown(DIK_UP))
	{
		m_pkPacman->setMoving(false);
	}

	if (m_pkInput->getKeyDown(DIK_RIGHT) && m_pkInput->getKeyDown(DIK_LEFT))
	{
		m_pkPacman->setMoving(false);
	}}
//----------------------------------------------------------------
void TestScene2::updateCollitions ()
{
	if(m_pkPacman->checkCollision(m_pkCirc))
	{
		m_pkPacman->setPos(m_pkPacman->getPrevPosX(), m_pkPacman->getPrevPosY(), m_pkPacman->getPrevPosZ());
	}
	if(m_pkBox->checkCollision(m_pkCirc))
	{
		m_pkBox->setMoveAngle(m_pkBox->getMoveAngle()*-1);
	}
}
//----------------------------------------------------------------
void TestScene2::onDraw (Renderer* pkRenderer) const
{

}
//----------------------------------------------------------------
bool TestScene2::onDeinit ()
{
	delete m_pkBox; m_pkBox=NULL;
	delete m_pkCirc; m_pkCirc=NULL;
	delete m_pkTri; m_pkTri=NULL;
	delete m_pkPacman; m_pkPacman=NULL;
	delete m_pkGhost1; m_pkGhost1=NULL;
	delete m_pkMapa; m_pkMapa=NULL;

	return true;
}
//----------------------------------------------------------------
void TestScene2::updateSounds ()
{
	if (m_pkInput->getKeyEventDown(DIK_M))
		m_pkSound->playSoundFile("../../res/Sounds/ophelia.mp3");

	if (m_pkInput->getKeyEventDown(DIK_N))
		m_pkSound->stopAllSounds();

	if (m_pkInput->getKeyDown(DIK_K))
		m_pkSound->setMasterVolume(m_pkSound->getMasterVolume() + 0.001f);
	
	if (m_pkInput->getKeyDown(DIK_J))
		m_pkSound->setMasterVolume(m_pkSound->getMasterVolume() - 0.001f);

	if (m_pkInput->getKeyEventDown(DIK_L))
		m_pkSound->pauseAllSounds(true);

	if (m_pkInput->getKeyEventUp(DIK_L))
		m_pkSound->pauseAllSounds(false);
}
//----------------------------------------------------------------
