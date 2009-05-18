//----------------------------------------------------------------
#include "TestScene.h"
//----------------------------------------------------------------
TestScene::TestScene ()
:
m_pkShape(NULL),
m_pkPacman(NULL),
m_pkGhost1(NULL),
m_pkMapa(NULL),
m_pkFont(NULL),
iPuntaje(0)
{
	/***/
}
//----------------------------------------------------------------
TestScene::~TestScene ()
{
	/***/
}
//----------------------------------------------------------------
bool TestScene::onInit (Importer* pkImporter, Renderer* pkRenderer)
{
	std::cout << "HOLA!!!" << std::endl;

	m_pkShape = new Box();
	m_pkPacman = new Sprite();
	m_pkGhost1 = new Sprite();
	m_pkMapa = new Map(pkRenderer);

	pkImporter->importResources("../../res/sprite.xml");

	// create the entities
	m_pkShape->setDim(100,100);
	m_pkShape->setPos(200, 0, 1.0f);
	m_pkShape->setColor(50,100,150);

	// initialize pacman
	if( !pkImporter->createSprite("Pacman", m_pkPacman) )
		return false;

	// set properties
	m_pkPacman->setName("el pacman loco");
	m_pkPacman->setDim(50,50);
	m_pkPacman->setPos(10.0f, 10.0f, 0.0f);
	m_pkPacman->setRotation(0);

	// set animation
	if( m_pkPacman->setAnimation("Eat") )
		m_pkPacman->getAnimation()->play();

	// initialize ghost
	if( !pkImporter->createSprite("Fantasma", m_pkGhost1) )
		return false;

	// set properties
	m_pkGhost1->setName("el fantasma loco");
	m_pkGhost1->setDim(50,50);
	m_pkGhost1->setPos(-100.0f, 0.0f, -1.0f);

	addCollisionGroup("fantasma");
	addCollisionGroup("pacman");
	addCollisionGroup("caja");

	addEntity(m_pkPacman, "pacman");
	addEntity(m_pkGhost1, "fantasma");
	addEntity(m_pkShape, "caja");

	m_pkMapa = new Map(pkRenderer);
	m_pkMapa->loadMap("../../res/MapaPrueba/tilesetFixed.xml","../../res/MapaPrueba/Mapa.xml");
	m_pkMapa->setPos(500,500);
	m_pkMapa->setLayerVisible(0,false);
	setCurrentMap(m_pkMapa);

	m_pkMapa->setTile(3,1,1,17);
	m_pkMapa->setTile(2,1,1,0);

	cout << m_pkMapa->getTile(5,4,0) << endl;

	cout << m_pkMapa->getNumCols() << endl;
	cout << m_pkMapa->getNumRows() << endl;
	cout << m_pkMapa->getNumLayers() << endl;
	cout << m_pkMapa->getTileHeight() << endl;
	cout << m_pkMapa->getTileWidth() << endl;

	m_pkFont = new Font(pkRenderer, this);
	m_pkFont->loadFont("../../res/font/font2.fnt");
	m_pkFont->setText("SOMOS LA SAL!-.");
	m_pkFont->setPos(-400,0);

	return true;
}
//----------------------------------------------------------------
bool TestScene::onUpdate (float fTimeBetweenFrames)
{
	//updatePacmanCollision();
	updateGhostInput();

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

	m_pkFont->setPos(m_pkFont->getPosX() + 0.1, m_pkFont->getPosY());

	if (m_pkInput->getKeyEventDown(DIK_P))
		iPuntaje += 100;

	m_pkFont->setText("Puntaje: %d", iPuntaje);
	
	return true;
}
//----------------------------------------------------------------
void TestScene::updateGhostInput ()
{
	m_pkGhost1->setPos(
					m_pkGhost1->getPosX() + m_pkInput->getMouseRelPosX(),
					m_pkGhost1->getPosY() - m_pkInput->getMouseRelPosY()
	);

	m_pkInput->getKeyEvent();
	if (m_pkInput->getKeyEventUp(DIK_T))
	{
		//m_pkPacman->setPos(m_pkPacman->getPosX() + 0.1, m_pkPacman->getPosY() + 0.1);
		
		m_pkPacman->setMoveAngle(0);
		m_pkPacman->setMoveSpeed(35);
		m_pkPacman->setMoving(true);
		
	}

	if (m_pkInput->getKeyEventDown(DIK_B))
		removeEntity(m_pkGhost1);

}
//----------------------------------------------------------------
void TestScene::updatePacmanCollision ()
{
	/*
	Entity2D::CollisionResult eResult = m_pkPacman->checkCollision(m_pkShape);

	if(eResult != Entity2D::None )
	{
		m_pkPacman->setPos(
						m_pkPacman->getPrevPosX(),
						m_pkPacman->getPrevPosY()
		);

		if(eResult == Entity2D::Horizontal)
		{
			float fAngle = m_pkPacman->getMoveAngle();

			m_pkPacman->setMoveAngle(360.0f - fAngle);
			m_pkPacman->setRotation(360.0f - fAngle);
		}	
		else if(eResult == Entity2D::Vertical)
		{
			float fAngle = m_pkPacman->getMoveAngle();

			m_pkPacman->setMoveAngle(180.0f - fAngle);
			m_pkPacman->setRotation(180.0f - fAngle);
		}	
	}

	eResult = m_pkPacman->checkCollision(m_pkGhost1);

	if(eResult != Entity2D::None )
	{
		m_pkGhost1->setPos(1000,1000);
	}
	*/
}
//----------------------------------------------------------------
void TestScene::onDraw (Renderer* pkRenderer) const
{

}
//----------------------------------------------------------------
bool TestScene::onDeinit ()
{
	delete m_pkShape;	m_pkShape = NULL;
	delete m_pkPacman;	m_pkPacman = NULL;
	delete m_pkGhost1;	m_pkGhost1 = NULL;
	//delete m_pkMapTexture;	m_pkMapTexture = NULL;

	return true;
}
//----------------------------------------------------------------