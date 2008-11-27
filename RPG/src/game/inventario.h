#ifndef INVENTARIO_H
#define INVENTARIO_H
//-----------------------------------------------------------------------
#include "Component.h"
#include "Defines.h"
//#include "slot.h"
#include "item.h"
#include "Engine.h"
#include <vector>
//-----------------------------------------------------------------------
class Inventario : public Component{
//-----------------------------------------------------------------------
public:
	Inventario();
	~Inventario();
//-----------------------------------------------------------------------
	bool isValidType(Component *pkChild);
	bool isInventoryEmpty();
	bool isInventoryFull();
	int getMaxSlots();
	int getOcupedSlots();
//-----------------------------------------------------------------------	
	bool addItem(Item* pkNewItem);
	bool removeItem(Item* pkItem);
	Item* getItem(int iType);
	//void setPosItem(float fPosX, float fPosY);
//-----------------------------------------------------------------------
	void setSprite(Sprite* kSprite, int iIndex) { m_pkInvSprt[iIndex] = kSprite; }
	Sprite * getSprite(int iIndex) { return m_pkInvSprt[iIndex]; }
//-----------------------------------------------------------------------
	void setPos(float fPosX, float fPosY);
	float getPosX() { return m_fPosX;}
	float getPosY() { return m_fPosY;}
//-----------------------------------------------------------------------

private:
	int m_iSlots;
	int m_itera;
	float m_fPosX, m_fPosY;
	Sprite *m_pkInvSprt[INVENTORY_SLOTS];
	Sprite *m_kItmSprt[INVENTORY_SLOTS];
	//vector<int> m_kNumItems;
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------
#endif //INVENTARIO_H
