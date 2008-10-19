//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "item.h"
#include <list>
#include <iostream>
//-----------------------------------------------------------------------------------------
class WorldFactory : public Factory
{
private:
	WorldFactory();
	~WorldFactory();
	//-------------------------------------------------------------------------------------------
public:
	static WorldFactory * GetInstance();
	static void RelaseInstance();

	void addWorldComp(Component pkComp);
	bool removeWorldComp(Component pkComp);
	void GetCreations();
	//------------------------------------------------------------------------------------------
private:
	static int count;
	static WorldFactory * instance;
	Component  m_iAux;

	list<Component>WorldList;
	list<Component>::iterator WorldListIterator;

	/*public:
	WorldList			m_WorldList;
	WorldListIterator	m_WorldIterator;
	*/

};
//------------------------------------------------------------------------------------------