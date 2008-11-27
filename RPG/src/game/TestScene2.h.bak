//----------------------------------------------------------------
#pragma once
//----------------------------------------------------------------
#include "Engine.h"
#include "Include.h"
//----------------------------------------------------------------
class TestScene2 : public Scene
{
	// constructor / destructor
public:
	TestScene2 (Actor  *m_pkChar);
	virtual ~TestScene2 ();

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

	// game entities
private:	
	Actor m_kPersonaje;
	Font * m_pkFstg; //Font de fuerza
	Font * m_pkFdex; //Font de destreza
	Font * m_pkFcon; //Font de constitucion
	Font * m_pkFint; //Font de inteligencia
	Font * m_pkFcha; //Font de carisma
	Font * m_pkFwis; //Font de sabiduria
	Font * m_pkFsstr;//Font de salvacion fortaleza
	Font * m_pkFsref;//Font de salvacion reflejos
	Font * m_pkFswis;//Font de salvacion sabiduria
	Font * m_pkFca;  //Font de CA
	Font * m_pkFmana;//Font de mana
	Font * m_pkFhps;//Font de mana
	Font * m_pkFatk; //Font de ataque base
};
//----------------------------------------------------------------