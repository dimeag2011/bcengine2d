//-----------------------------------------------------------------------------------------
#include "slot.h"
#include "Item.h"
//-----------------------------------------------------------------------------------------

Slot::Slot():
Component(),
m_iMaxStack(-1),
m_iItemType(-1)
{
	m_isTypeFixed = false;	
}
//-----------------------------------------------------------------------
Slot::Slot(int iType)
:Component(),
m_iMaxStack(-1),
m_iItemType(iType)
{
	m_isTypeFixed = true;

}
//-----------------------------------------------------------------------

Slot::~Slot() 
{
	// ...
}
//-----------------------------------------------------------------------
void Slot::OnChildAdded(Component * pChild)
{
	Item * pItem = (Item *)pChild;
	// si es el primer hijo, tomar el max stack
	if (m_iMaxStack == -1) {
		m_iMaxStack = pItem->GetMaxStack();
		m_iItemType = pItem->GetItemType();
	}

	// si pkNewItem->m_iMaxStack != item is stackable
}

//-----------------------------------------------------------------------
void Slot::OnChildRemoved(Component * pChild)
{
   // si era el último, seteo maxStack en -1
	if (m_itCurrentChild == 0) {
		m_iMaxStack = -1;
		// si el slot no tiene un tipo de item fijo,
		// seteo el tipo de item en -1
		if (!m_isTypeFixed)
			m_iItemType = -1;
	}
}
//-----------------------------------------------------------------------
bool Slot::IsChildValid(Component * pChild)
{
	// se fija si es item...
	if (pChild->getType() != TYPE_ITEM)
		return false;
	// ...y si hay stack disponible
	//if (GetAvailableStack() == 0)
	//	return false;

	return true;

}
//-----------------------------------------------------------------------
/*int GetAvailableStack()
{
	return m_iMaxStack - m_itCurrentChild;

}*/
//-----------------------------------------------------------------------
bool Slot::IsItemType(int iItemType)
{
	// si el tipo es -1 también es del tipo
	return (m_iItemType == -1) || (m_iItemType == iItemType);
}
//-----------------------------------------------------------------------

