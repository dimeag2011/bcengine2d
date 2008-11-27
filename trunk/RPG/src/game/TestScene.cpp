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
m_kmyNpc(NULL),
m_pkEvent(NULL),
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
	//Creamos un NPC Kobold.
	m_kmyNpc = m_kmyActor->CreateActor("KOBOLD_PEDORRO",TYPE_NPC,TYPE_CLERIC);
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

	// Agrego un Listener al mundo para que mi NPC y mi Player escuchen los eventos de ataques.
	mundo->onAddedListener("ATTK_RANGE",m_kmyNpc);
	mundo->onAddedListener("ATTK_RANGE",m_kPj);
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


	// Creamos un nuevo Sprite para darle al npc Kobold.
	m_pkAuxSprite = new Sprite();
	if(!pkImporter->createSprite("Fantasma", m_pkAuxSprite))
	{
		return false;
	}
	else
	{
		m_pkAuxSprite->setDim(80,80);
		m_pkAuxSprite->setPos(-100, -100);
		m_kmyNpc->setSprite(m_pkAuxSprite);
		Kobold = m_kmyNpc->getSprite();
		addEntity(Kobold);
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
	
	// Updateo las coliciones del Actor. (no es lo mismo que el pacmancollision???)
	updateActorCollision();
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
/*	if (m_pkInput->getKeyEventDown(DIK_C))
	{
		m_pkFont->setText("Fuerza:", m_kPj->m_kAuxActAtt.getStr());
		m_pkFont->setPos(-400,300);
		m_pkFont->setText("Destreza:", m_kPj->m_kAuxActAtt.getDex());
		m_pkFont->setPos(-400,295);
		m_pkFont->setText("Comstitucion:", m_kPj->m_kAuxActAtt.getCon());
		m_pkFont->setPos(-400,290);
		m_pkFont->setText("Inteligencia:", m_kPj->m_kAuxActAtt.getInt());
		m_pkFont->setPos(-400,285);
		m_pkFont->setText("Carisma:", m_kPj->m_kAuxActAtt.getCha());
		m_pkFont->setPos(-400,280);
		m_pkFont->setText("Sabiduria:", m_kPj->m_kAuxActAtt.getWis());
		m_pkFont->setPos(-400,275);
		m_pkFont->setText("Salvacion Fortaleza:", m_kPj->m_kAuxActAtt.getSstr());
		m_pkFont->setPos(-400,265);
		m_pkFont->setText("Salvacion Reflejos:", m_kPj->m_kAuxActAtt.getSref());
		m_pkFont->setPos(-400,260);
		m_pkFont->setText("Salvacion voluntad:", m_kPj->m_kAuxActAtt.getWis());
		m_pkFont->setPos(-400,255);
		m_pkFont->setText("CA:", m_kPj->m_kAuxActAtt.getCa());
		m_pkFont->setPos(-400,245);
		m_pkFont->setText("Mana:", m_kPj->m_kAuxActAtt.getMana());
		m_pkFont->setPos(-400,240);
		m_pkFont->setText("Vida:", m_kPj->m_kAuxActAtt.getHps());
		m_pkFont->setPos(-400,235);
		m_pkFont->setText("Ataque base:", m_kPj->getClassHero().iAtk);
		m_pkFont->setPos(-400,230);
	}*/
	
	//m_pkFont->setPos(m_pkFont->getPosX() + 0.1, m_pkFont->getPosY());

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

		// Seteo El result a 0 [Bug Fixed: cada vez que habia una colicion esta quedaba cargada en el eResult
		// y todos los chekeos posteriores tiraban que huvo colision (por mas que no la huviera]
		// Similar a vaciarle el buffer y dejarla en 0, preparada para el proximo chekeo.
		eResult = Entity2D::None;
		eResult = Entity2D::None;
				
	}

	 eResult = Actor1->checkCollision(Armadura);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kArmadura);
		Armadura->setVisible(false);
		if (Armadura)
			removeEntity(Armadura);

		// Seteo El result a 0 [Bug Fixed: cada vez que habia una colicion esta quedaba cargada en el eResult
		// y todos los chekeos posteriores tiraban que huvo colision (por mas que no la huviera]
		// Similar a vaciarle el buffer y dejarla en 0, preparada para el proximo chekeo.
		eResult = Entity2D::None;
		eResult = Entity2D::None;
	}
	 eResult = Actor1->checkCollision(Espada);
	if(eResult != Entity2D::None )
	{
		m_kPj->putItemInventory(m_kEspada);
		Espada->setVisible(false);
		if (Espada)
			removeEntity(Espada);

		// Seteo El result a 0 [Bug Fixed: cada vez que habia una colicion esta quedaba cargada en el eResult
		// y todos los chekeos posteriores tiraban que huvo colision (por mas que no la huviera]
		// Similar a vaciarle el buffer y dejarla en 0, preparada para el proximo chekeo.
		eResult = Entity2D::None;
		eResult = Entity2D::None;
	}

}
//----------------------------------------------------------------
void TestScene::updateActorCollision()
{
	// Manager para chekear las colisiones entre NPC y Player.

	// Chekeo si mi colision es contra el kobold.
	Entity2D::CollisionResult eResult = Actor1->checkCollision(Kobold);
	// si eResult no es null (si es que se realizo una colicion)
	if (eResult != Entity2D::None){
		// creo el nuevo evento de ATTK_Range y lo despacho.
		m_pkEvent = new Event("ATTK_RANGE");
		m_kPj->DispachEvent(m_pkEvent);

		// Debug Text:
		m_pkFont->setText("EVENTO: ATTK_RANGE ");

		// Seteo El result a 0 [Bug Fixed: cada vez que habia una colicion esta quedaba cargada en el eResult
		// y todos los chekeos posteriores tiraban que huvo colision (por mas que no la huviera]
		// Similar a vaciarle el buffer y dejarla en 0, preparada para el proximo chekeo.
		eResult = Entity2D::None;
	}
	//eResult = m_pkPacman->checkCollision(m_pkGhost1);
/*
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
*/
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
Actor * TestScene::getCharacter()
{
	return m_kPj;
}