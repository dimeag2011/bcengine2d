//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include <list>
#include <cstdlib>
#include "component.h"
//-----------------------------------------------------------------------------------------
class Factory
{

protected:
	Factory();
	~Factory();

	list<Component*> m_lKList;
	list<Component*>::iterator m_lkListIterator;

public:
	void removeAll();
	void remove(Component *kComponent);

};
//-----------------------------------------------------------------------