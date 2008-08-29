#ifndef INVENTARIO_H
#define INVENTARIO_H
//-----------------------------------------------------------------------
#include "Component.h"
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
private:
	int m_iSlots;
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------
#endif //INVENTARIO_H
