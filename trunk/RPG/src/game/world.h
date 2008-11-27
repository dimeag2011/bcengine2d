//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "item.h"
#include "Actor.h"
#include "quest.h"
#include <list>
#include <iostream>
//-----------------------------------------------------------------------------------------
class World : public Component
{
public:
	World();
	~World();
//-------------------------------------------------------------------------------------------
public:
	void addWorldComp(Component *pkComp);
	bool removeWorldComp(Component *pkComp);
	void GetCreations();
	virtual void onEvent(Event *pkEvent, Component* dispatcher);
//------------------------------------------------------------------------------------------
private:

};
//------------------------------------------------------------------------------------------