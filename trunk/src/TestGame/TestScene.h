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
	bool onInit (Importer* pkImporter);
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

};
//----------------------------------------------------------------
#endif // TESTSCENE_H
//----------------------------------------------------------------
