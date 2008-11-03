//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "item.h"
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
//------------------------------------------------------------------------------------------
private:
//	list<Component>WorldList;
//	list<Component>::iterator WorldListIterator;

};
//------------------------------------------------------------------------------------------