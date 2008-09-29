//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "item.h"
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
	void addWorldItem(Item *pkItem);
	void GetCreations();
	//------------------------------------------------------------------------------------------
private:
	static int count;
	static WorldFactory * instance;
	Item * m_iAux;

};
//------------------------------------------------------------------------------------------