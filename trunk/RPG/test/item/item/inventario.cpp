//-----------------------------------------------------------------------
#include "inventario.h"
//-----------------------------------------------------------------------
Inventario::Inventario()
:
m_iSlots(0) 
{
	/***/
}
//-----------------------------------------------------------------------
Inventario::~Inventario(){
	/***/
}
//-----------------------------------------------------------------------
bool Inventario::isValidType(Component *pkChild){
	
	if ((pkChild->getType() == TYPE_ITEM) && (!isInventoryFull())){
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------
bool Inventario::isInventoryEmpty(){
	if ((int(m_kChilds.size())) == 0){
		return true;
	} else {
		return false;
	}
}
//-----------------------------------------------------------------------
bool Inventario::isInventoryFull(){
	if ((int(m_kChilds.size())) == m_iSlots){
		return true;
	} else {
		return false;
	}
}
//-----------------------------------------------------------------------
int Inventario::getMaxSlots(){
	return m_iSlots;
}
//-----------------------------------------------------------------------
int Inventario::getOcupedSlots(){
	return int(m_kChilds.size());
}
//-----------------------------------------------------------------------
