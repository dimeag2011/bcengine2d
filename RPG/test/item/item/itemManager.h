//-----------------------------------------------------------------------------------------
#ifndef ITEMMNGR_H
#define ITEMMNGR_H
//-----------------------------------------------------------------------------------------
#include "Defines.h"
//-----------------------------------------------------------------------------------------
#include "item.h"
//#include "armorWeapon.h"
#include <list>
#include <cstdlib>
//-----------------------------------------------------------------------------------------
class ItemManager{
//-----------------------------------------------------------------------------------------
public:

	ItemManager();
	~ItemManager();

	Item* CreateItem(int m_iType);
	void DeleteItem(Item *kItem);
//-----------------------------------------------------------------------------------------
private:
	list<Item*>m_lkItemList;
	list<Item*>::iterator m_lkItemListIterator;
	int m_iType;
	Item *m_ikAuxItem;

};
#endif;