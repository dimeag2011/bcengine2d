//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "item.h"
#include "ArmorWeapon.h"
#include "potion.h"
#include <iostream>
//-----------------------------------------------------------------------------------------
class ItemFactory : public Factory
{
private:
	ItemFactory();
	~ItemFactory();
	//-------------------------------------------------------------------------------------------
public:
	static ItemFactory * GetInstance();
	static void RelaseInstance();
	Item* CreateItem(int m_iType);
	void GetCreations();
	//------------------------------------------------------------------------------------------
private:
	static int count;
	static ItemFactory * instance;
	
	//Component * m_AuxComp;


};
//------------------------------------------------------------------------------------------