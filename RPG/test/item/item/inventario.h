#ifndef INVENTARIO_H
#define INVENTARIO_H
//-----------------------------------------------------------------------
#include "Component.h"
#include "Defines.h"
#include "slot.h"
#include "item.h"
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
	void addSlot(Slot* pkNewSlot);
	void removeSlot(Slot* pkSlot);
//-----------------------------------------------------------------------
private:
	int m_iSlots;
	char *m_ckAux;
	Slot m_kSlot;
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------
#endif //INVENTARIO_H
