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
Armadura(NULL),
Posion(NULL),
Espada(NULL)
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
	m_kmyItem = ItemFactory::GetInstance();
	m_kPj = m_kmyActor->CreateActor("Mariano" ,TYPE_PLAYER , TYPE_WARRIOR);
	m_kPosion = m_kmyItem->CreateItem(TYPE_POTION);
	m_kArmadura = m_kmyItem->CreateItem(TYPE_ARMOR);
	m_kEspada = m_kmyItem->CreateItem(TYPE_WEAPON);

	pkImporter->importResources("../../res/sprite.xml");

	// create the entities
	
	// initialize actor
	//Le paso un puntero al importer y le seteo la posicion
	if( !m_kPj->onInit(pkImporter, 0.0f, 0.0f, "Actor 1") )
		return false;

	
	// initialize posion
	//Lo mismo que el actor
	if( !m_kPosion->onInit(pkImporter, 50.0f, 50.0f, "Item1") )
		return false;

	if( !m_kArmadura->onInit(pkImporter, 200.0f, 0.0f, "Item2") )
		return false;

	if( !m_kEspada->onInit(pkImporter, -300.0f, -300.0f, "Item3") )
		return false;

// set properties
	/*m_pkGhost1->setName("el fantasma loco");
	m_pkGhost1->setDim(50,50);
	m_pkGhost1->setPos(-100.0f, 0.0f, -1.0f);
*/
	addCollisionGroup("fantasma");
	addCollisionGroup("pacman");
//	addCollisionGroup("caja");
	
	//Le paso los Sprites para el addEntity
	Actor1 = (m_kPj->getSprite());
	Posion = (m_kPosion->getSprite());
	Armadura = (m_kArmadura->getSprite());
	Espada = (m_kEspada->getSprite());
	
	Actor1->setVisible(true);
	Posion->setVisible(true);
	Armadura->setVisible(true);
	Espada->setVisible(true);

	addEntity(Actor1, "pacman");
	addEntity(Posion, "fantasma");
	addEntity(Armadura, "fantasma");
	addEntity(Armadura, "fantasma");
	//addEntity(m_pkShape, "caja");

	return true;
}
//----------------------------------------------------------------
bool TestScene::onUpdate (float fTimeBetweenFrames)
{
	//updatePacmanCollision();
	updateGhostInput();

	if (m_pkInput->getKeyDown(DIK_W))
		Actor1->setPos(Actor1->getPosX(), Actor1->getPosY()+10.0f, Actor1->getPosZ());

	if (m_pkInput->getKeyDown(DIK_N))
		Actor1->setPos(Actor1->getPosX(), Actor1->getPosY()-10.0f, Actor1->getPosZ());		

	if (m_pkInput->getKeyDown(DIK_A))
		Actor1->setPos(Actor1->getPosX()-10.0f, Actor1->getPosY(), Actor1->getPosZ());		
	
	if (m_pkInput->getKeyDown(DIK_D))
		Actor1->setPos(Actor1->getPosX()+10.0f, Actor1->getPosY(), Actor1->getPosZ());		

	if (m_pkInput->getKeyEventDown(DIK_U))
	{
		m_kPj->useItem(TYPE_ARMOR);
	}	
	if (m_pkInput->getKeyEventDown(DIK_I))
	{
		m_kPj->useItem(TYPE_WEAPON);
	}
	if (m_pkInput->getKeyEventDown(DIK_O))
	{
		m_kPj->useItem(TYPE_ARMOR);
	}
	if (m_pkInput->getKeyEventDown(DIK_J))
	{
		m_kPj->removeEquipable(m_kArmadura);
	}	
	if (m_pkInput->getKeyEventDown(DIK_K))
	{
		m_kPj->removeEquipable(m_kEspada);
	}
	if (m_pkInput->getKeyEventDown(DIK_L))
	{
		m_kPj->removeEffect(m_kPosion->GetName());
	}
	


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

	Entity2D::CollisionResult eResult = Actor1->checkCollision(Posion);
	//eResult = m_pkPacman->checkCollision(m_pkGhost1);

	//Si el resultado de la colision esta bien, le agrego el item al inventario
	//y lo seteo no visible
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kPosion);
		Posion->setVisible(false);
	}

	 eResult = Actor1->checkCollision(Armadura);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kArmadura);
		Armadura->setVisible(false);
	}
	 eResult = Actor1->checkCollision(Espada);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kEspada);
		Espada->setVisible(false);
	}

}
//----------------------------------------------------------------
void TestScene::onDraw (Renderer* pkRenderer) const
{
	/*Actor1->draw(pkRenderer);
	Item1->draw(pkRenderer);
*/
}
//----------------------------------------------------------------
bool TestScene::onDeinit ()
{
	//Hago boleta todo
	delete Actor1; Actor1 = NULL;
	delete Posion;  Posion = NULL;
	delete Armadura;  Armadura = NULL;
	delete Espada;  Espada = NULL;
			
	delete m_kPj; m_kPj =NULL; 
	delete m_kPosion; m_kPosion = NULL;
	delete m_kArmadura; m_kArmadura = NULL;
	delete m_kEspada; m_kEspada = NULL;
	
	m_kmyActor->removeAll();
	m_kmyActor->RelaseInstance();
	m_kmyItem->removeAll();
	m_kmyItem->RelaseInstance();
	
/*	delete m_pkShape;	m_pkShape = NULL;
	delete m_pkPacman;	m_pkPacman = NULL;
	delete m_pkGhost1;	m_pkGhost1 = NULL;
	//delete m_pkMapTexture;	m_pkMapTexture = NULL;
*/
	return true;
}
//----------------------------------------------------------------