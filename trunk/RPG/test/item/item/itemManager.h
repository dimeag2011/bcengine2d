//-----------------------------------------------------------------------------------------
#ifndef ITEMMNGR_H
#define ITEMMNGR_H
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

	Item* CreateItem(string &m_kType);
	void DeleteItem(Item *kItem);
//-----------------------------------------------------------------------------------------
private:
	list<Item*>m_lkItemList;
	list<Item*>m_lkItemListIterator;
	string m_kType;
	Item *m_ikAuxItem;

};
#endif;