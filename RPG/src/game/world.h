//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "item.h"
#include <list>
#include <iostream>
//-----------------------------------------------------------------------------------------
class WorldFactory : public Component
private:
	World();
	~World();
	//-------------------------------------------------------------------------------------------
public:
	void addWorldComp(Component pkComp);
	bool removeWorldComp(Component pkComp);
	void GetCreations();
	//------------------------------------------------------------------------------------------
private:
	list<Component>WorldList;
	list<Component>::iterator WorldListIterator;

	/*public:
	WorldList			m_WorldList;
	WorldListIterator	m_WorldIterator;
	*/

};
//------------------------------------------------------------------------------------------