//----------------------------------------------------------------
#include "TestScene.h"
//----------------------------------------------------------------
TestScene::TestScene ()
:
m_pkFont(NULL),
m_kmyActor(NULL),
m_kPosion(NULL),
m_kArmadura(NULL),
m_kEspada(NULL),
m_kPj(NULL),
Actor1(NULL),
Armadura(NULL),
Posion(NULL),
Espada(NULL),
mundo(NULL)
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
	mundo = new World();
	pkImporter->importResources("../../res/sprite.xml");

	// create the entities
	
	// initialize actor
	//Le paso un puntero al importer y le seteo la posicion
	Sprite* m_pkAuxSprite = new Sprite();
	if(!pkImporter->createSprite("Pacman", m_pkAuxSprite))
	{
		return false;
	}
	else
	{
		//m_pkAuxSprite->setName(sName);
		m_pkAuxSprite->setDim(50,50);
		m_pkAuxSprite->setPos(0, 0);
		m_kPj->setSprite(m_pkAuxSprite);
		Actor1 = m_kPj->getSprite();
		addEntity(Actor1);
		//addEntity(m_pkAuxSprite);
		m_pkAuxSprite = NULL;
	}
	//Lo agrego al mundo
	mundo->addWorldComp(m_kPj);
	mundo->addWorldComp(m_kPosion);
	mundo->addWorldComp(m_kArmadura);
	mundo->addWorldComp(m_kEspada);
	for(int i=0; i < m_kPj->m_kInventory->getMaxSlots(); i++)
	{
		Sprite* m_pkAuxSprite = new Sprite();
		if(!pkImporter->createSprite("Fantasma", m_pkAuxSprite))
		{
			return false;
		}
		else
		{
			m_pkAuxSprite->setDim(50,50);
			m_kPj->m_kInventory->setSprite(m_pkAuxSprite, i);
			addEntity(m_pkAuxSprite);
			m_pkAuxSprite = NULL;
		}
	}
	m_kPj->m_kInventory->setPos(10,10);


	m_pkAuxSprite = new Sprite();
	if(!pkImporter->createSprite("Fantasma", m_pkAuxSprite))
	{
		return false;
	}
	else
	{
		//m_pkAuxSprite->setName(sName);
		m_pkAuxSprite->setDim(50,50);
		m_pkAuxSprite->setPos(-50, 200);
		m_kPosion->setSprite(m_pkAuxSprite);
		//addEntity(m_pkAuxSprite);
		Posion = m_kPosion->getSprite();
		addEntity(Posion);
		m_pkAuxSprite = NULL;
	}

	m_pkAuxSprite = new Sprite();
	if(!pkImporter->createSprite("Fantasma", m_pkAuxSprite))
	{
		return false;
	}
	else
	{
		//m_pkAuxSprite->setName(sName);
		m_pkAuxSprite->setDim(50,50);
		m_pkAuxSprite->setPos(-150, 200);
		m_kArmadura->setSprite(m_pkAuxSprite);
		//addEntity(m_pkAuxSprite);
		Armadura = m_kArmadura->getSprite();
		addEntity(Armadura);
		m_pkAuxSprite = NULL;
	}
	
	m_pkAuxSprite = new Sprite();
	if(!pkImporter->createSprite("Fantasma", m_pkAuxSprite))
	{
		return false;
	}
	else
	{
		//m_pkAuxSprite->setName(sName);
		m_pkAuxSprite->setDim(50,50);
		m_pkAuxSprite->setPos(-300, -150);
		m_kEspada->setSprite(m_pkAuxSprite);
		//addEntity(m_pkAuxSprite);
		Espada = m_kEspada->getSprite();
		addEntity(Espada);
		m_pkAuxSprite = NULL;
	}

	m_pkFont = new Font(pkRenderer, this);
	m_pkFont->loadFont("../../res/font/font2.fnt");
	m_pkFont->setText("SOMOS LA SAL!-.");
	m_pkFont->setPos(-400,0);

	return true;
}
//----------------------------------------------------------------
bool TestScene::onUpdate (float fTimeBetweenFrames)
{
	updatePacmanCollision();
	//updateGhostInput();

	if (m_pkInput->getKeyDown(DIK_W))
		m_kPj->getSprite()->setPos(m_kPj->getSprite()->getPosX(), m_kPj->getSprite()->getPosY()+1.0f);

	if (m_pkInput->getKeyDown(DIK_S))
		m_kPj->getSprite()->setPos(m_kPj->getSprite()->getPosX(), m_kPj->getSprite()->getPosY()-1.0f);		

	if (m_pkInput->getKeyDown(DIK_A))
		m_kPj->getSprite()->setPos(m_kPj->getSprite()->getPosX()-1.0f, m_kPj->getSprite()->getPosY());		
	
	if (m_pkInput->getKeyDown(DIK_D))
		m_kPj->getSprite()->setPos(m_kPj->getSprite()->getPosX()+1.0f, m_kPj->getSprite()->getPosY());		

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
		m_kPj->useItem(TYPE_POTION);
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
	
	m_pkFont->setPos(m_pkFont->getPosX() + 0.1, m_pkFont->getPosY());

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
		if (Posion)
			removeEntity(Posion);
				
	}

	 eResult = Actor1->checkCollision(Armadura);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kArmadura);
		Armadura->setVisible(false);
		if (Armadura)
			removeEntity(Armadura);
	}
	 eResult = Actor1->checkCollision(Espada);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kEspada);
		Espada->setVisible(false);
		if (Espada)
			removeEntity(Espada);
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
	/*
	delete Actor1; Actor1 = NULL;
	
	delete Armadura;  Armadura = NULL;
	delete Espada;  Espada = NULL;
			
	delete m_kPj; m_kPj =NULL; 
	delete m_kPosion; m_kPosion = NULL;
	delete m_kArmadura; m_kArmadura = NULL;
	delete m_kEspada; m_kEspada = NULL;
	*/
	delete Posion;  Posion = NULL;
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