//----------------------------------------------------------------
#ifndef TESTSCENE_H
#define TESTSCENE_H
//----------------------------------------------------------------
#include "Engine.h"
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

// game entities
private:
	Shape* m_pkShape;
	Sprite* m_pkPacman;
	Sprite* m_pkGhost1;
	Map* m_pkMapa;
	Font* m_pkFont;

};
//----------------------------------------------------------------
#endif // TESTSCENE_H
//----------------------------------------------------------------
