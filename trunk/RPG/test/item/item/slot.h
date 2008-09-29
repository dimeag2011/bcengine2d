#ifndef SLOT_H
#define SLOT_H
//-----------------------------------------------------------------------------------------
#include "Component.h"
#include "item.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------
class Slot : public Component {
public:

    Slot();
	Slot(int iType);
	~Slot();

//---------------------------------------------------------------------
public:

	int GetAvailableStack();
	int GetItemType() { return m_iItemType; }
	int GetMaxStack() {return m_iMaxStack; }
	

	bool IsItemType(int iItemType);

	void OnChildAdded(Component * pChild);
	void OnChildRemoved(Component * pChild);
	bool IsChildValid(Component * pChild); 

	int m_iMaxStack;
	// qué tipo de item recibe
	int m_iItemType;
	// si puede recibir otro tipo de item
	bool m_isTypeFixed;




private:

	//cantidad de items en slot actual
	int itemCount;
};
//-----------------------------------------------------------------------------------------
#endif //SLOT_H
