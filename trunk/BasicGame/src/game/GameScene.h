//----------------------------------------------------------------
#ifndef GAMESCENE_H
#define GAMESCENE_H
//----------------------------------------------------------------
#include "Engine.h"
#include <iostream>
#include "Controller.h"
//----------------------------------------------------------------
class GameScene : public Scene
{
// constructor / destructor
public:
	GameScene ();
	virtual ~GameScene ();

// application specific steps
protected:
	bool onInit (Importer* pkImporter, Renderer* pkRenderer);
	bool onUpdate (float fTimeBetweenFrames);
	void onDraw (Renderer* pkRenderer) const;
	bool onDeinit ();

// game entities
private:

	Controller* m_pkControl;

};
//----------------------------------------------------------------
#endif // GAMESCENE_H
//----------------------------------------------------------------
