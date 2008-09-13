//-----------------------------------------------------------------------------------------
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

	list<Component*>m_lKList;
	list<Component*>::iterator m_klKlistIterator;

public:
	void removeAll();
	void remove(Component *kComponent);

	}