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
//-----------------------------------------------------------------------
	bool onInit(Importer* pkImporter, float fPosX, float fPosY);
	void Draw(Renderer * pkRenderer);
//-----------------------------------------------------------------------

private:
	int m_iSlots;
	float m_fPosX, m_fPosY;
//	Sprite *m_pkInvSprt;

	//vector<int> m_kNumItems;
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------
#endif //INVENTARIO_H
