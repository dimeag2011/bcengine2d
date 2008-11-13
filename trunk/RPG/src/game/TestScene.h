//----------------------------------------------------------------
#ifndef TESTSCENE_H
#define TESTSCENE_H
//----------------------------------------------------------------
#include "Engine.h"
#include "Include.h"
//----------------------------------------------------------------
class TestScene : public Scene
{
	// constructor / destructor
public:
	TestScene ();
	virtual ~TestScene ();

	// application specific steps
protected:
	bool onInit (Importer* pkImporter, Renderer* pkRenderer);
	bool onUpdate (float fTimeBetweenFrames);
	void onDraw (Renderer* pkRenderer) const;
	bool onDeinit ();

	// update methods
protected:
	void updatePacmanCollision ();
	void updateGhostInput ();

public:	
	Actor * getCharacter();

	// game entities
private:	
	//Creo la factory de actor y algunos items
	// Los dos Sprite de abajo van a recibir los sprites de m_kPj y m_kPosion
	//mediante un getSprite de Actor y Item
	ActorFactory * m_kmyActor;
	ItemFactory * m_kmyItem;
	Item * m_kPosion;
	Item * m_kArmadura;
	Item * m_kEspada;
	Actor * m_kPj;
	Sprite * Actor1;  
	Sprite * Armadura; 
	Sprite * Posion;  
	Sprite * Espada; 
	Map * mapa;
	Font * m_pkFont;
	World * mundo;
};
//----------------------------------------------------------------
#endif // TESTSCENE_H
//----------------------------------------------------------------
