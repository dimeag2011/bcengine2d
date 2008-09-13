#ifndef SLOT_H
#define SLOT_H
//-----------------------------------------------------------------------------------------
#include "Component.h"
//-----------------------------------------------------------------------------------------
class Slot : public Component{
public:
	bool addSlot(Component* pkNewSlot);
	bool removeSlot(Component* pkSlot);
	void reciveType(string m_kType);
	bool isFullStack(Item m_kItem);
}
//-----------------------------------------------------------------------------------------
#endif //SLOT_H
