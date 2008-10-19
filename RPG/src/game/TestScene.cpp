//----------------------------------------------------------------
#include "TestScene.h"
//----------------------------------------------------------------
TestScene::TestScene ()
:
m_kmyActor(NULL),
m_kPosion(NULL),
m_kArmadura(NULL),
m_kEspada(NULL),
m_kPj(NULL),
Actor1(NULL),
Item1(NULL)
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
	//Inicializo la factories y el pj
	m_kmyActor = ActorFactory::GetInstance();
	m_kPj = m_kmyActor->CreateActor("Mariano" ,TYPE_PLAYER , TYPE_WARRIOR);
	m_kPosion = new Item();
	m_kArmadura = new Item();
	m_kEspada = new Item();

	pkImporter->importResources("../../res/sprite.xml");

	// create the entities
	
	// initialize actor
	//Le paso un puntero al importer y le seteo la posicion
	if( !m_kPj->onInit(pkImporter, 0.0f, 0.0f, "Actor 1") )
		return false;

	// set properties
	
	// set animation
	/*if( m_pkPacman->setAnimation("Eat") )
		m_pkPacman->getAnimation()->play();
	*/
	// initialize posion
	//Lo mismo que el actor
	if( !m_kPosion->onInit(pkImporter, 50.0f, 50.0f, "Item1") )
		return false;

/*	if( !m_kArmadura->onInit(pkImporter, 200.0f, 0.0f, "Item2") )
		return false;

	if( !m_kEspada->onInit(pkImporter, -300.0f, -300.0f, "Item3") )
		return false;

*/
	// set properties
	/*m_pkGhost1->setName("el fantasma loco");
	m_pkGhost1->setDim(50,50);
	m_pkGhost1->setPos(-100.0f, 0.0f, -1.0f);
*/
	addCollisionGroup("fantasma");
	addCollisionGroup("pacman");
	addCollisionGroup("caja");
	
	//Le paso los Sprites para el addEntity
	Sprite * Actor1 = (m_kPj->getSprite());
	Sprite * Item1 = (m_kPosion->getSprite());
	
	Actor1->setVisible(true);
	Item1->setVisible(true);
	
	addEntity(Actor1, "pacman");
	addEntity(Item1, "fantasma");
	//addEntity(m_pkShape, "caja");

	return true;
}
//----------------------------------------------------------------
bool TestScene::onUpdate (float fTimeBetweenFrames)
{
	//updatePacmanCollision();
	updateGhostInput();

/*	if (m_pkInput->getKeyEventDown(DIK_M))
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

	if (m_pkInput->getKeyDown(DIK_V))
		m_pkPacman->setPos(m_pkPacman->getPosX(), m_pkPacman->getPosY(), m_pkPacman->getPosZ() + 10.0f);

	if (m_pkInput->getKeyDown(DIK_B))
		m_pkPacman->setPos(m_pkPacman->getPosX(), m_pkPacman->getPosY(), m_pkPacman->getPosZ() - 10.0f);
*/

	return true;
}
//----------------------------------------------------------------
void TestScene::updateGhostInput ()
{
/*	m_pkGhost1->setPos(
		m_pkGhost1->getPosX() + m_pkInput->getMouseRelPosX(),
		m_pkGhost1->getPosY() - m_pkInput->getMouseRelPosY()
		);
*/
/*	m_pkInput->getKeyEvent();
	if (m_pkInput->getKeyEventUp(DIK_T))
	{
		//m_pkPacman->setPos(m_pkPacman->getPosX() + 0.1, m_pkPacman->getPosY() + 0.1);

		m_pkPacman->setMoveAngle(0);
		m_pkPacman->setMoveSpeed(35);
		m_pkPacman->setMoving(true);

	}*/
}
//----------------------------------------------------------------
void TestScene::updatePacmanCollision ()
{

	Entity2D::CollisionResult eResult = Actor1->checkCollision(Item1);

	
	//eResult = m_pkPacman->checkCollision(m_pkGhost1);

	//Si el resultado de la colision esta bien, le agrego el item al inventario
	//y lo seteo no visible
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kPosion);
		Item1->setVisible(false);
	}

}
//----------------------------------------------------------------
void TestScene::onDraw (Renderer* pkRenderer) const
{

}
//----------------------------------------------------------------
bool TestScene::onDeinit ()
{
	//Hago boleta todo
	delete m_kPj; m_kPj =NULL; 
	delete m_kPosion; m_kPosion = NULL;
	delete m_kArmadura; m_kArmadura = NULL;
	delete m_kEspada; m_kEspada = NULL;
	delete Actor1; Actor1 = NULL;
	delete Item1;  Item1 = NULL;
	m_kmyActor->RelaseInstance();
	
	
/*	delete m_pkShape;	m_pkShape = NULL;
	delete m_pkPacman;	m_pkPacman = NULL;
	delete m_pkGhost1;	m_pkGhost1 = NULL;
	//delete m_pkMapTexture;	m_pkMapTexture = NULL;
*/
	return true;
}
//----------------------------------------------------------------