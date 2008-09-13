//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "item.h"
//-----------------------------------------------------------------------------------------
class ItemFactory :public Factory
{
private:
	ItemFactory();
	~ItemFactory();
//-----------------------------------------------------------------------------º-------------
public
	static ItemFactory * GetInstance();
	static void RelaseInstance();
	Item* CreateItem(string m_kType);
//------------------------------------------------------------------------------------------
private:
	static int count;
	static ItemFactory * instance;

}
//------------------------------------------------------------------------------------------