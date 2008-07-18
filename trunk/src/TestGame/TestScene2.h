//----------------------------------------------------------------
#ifndef TESTSCENE2_H
#define TESTSCENE2_H
//----------------------------------------------------------------
#include "Engine.h"
//----------------------------------------------------------------
class TestScene2 : public Scene
{
// constructor / destructor
public:
	TestScene2 ();
	virtual ~TestScene2 ();

// application specific steps
protected:
	bool onInit (Importer* pkImporter, Renderer* pkRenderer);
	bool onUpdate (float fTimeBetweenFrames);
	void onDraw (Renderer* pkRenderer) const;
	bool onDeinit ();

// update methods
protected:
	void updatePacManInput ();
	void updateCollitions ();
	void updateSounds ();

// game entities
private:
	Box* m_pkBox;
	Circle* m_pkCirc;
	Triangle* m_pkTri;

	Sprite* m_pkPacman;
	Sprite* m_pkGhost1;

	Map* m_pkMapa;

};
//----------------------------------------------------------------
#endif // TESTSCENE2_H
//----------------------------------------------------------------
