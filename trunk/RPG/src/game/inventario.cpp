//-----------------------------------------------------------------------
#include "inventario.h"
//-----------------------------------------------------------------------
Inventario::Inventario()
:
m_iSlots(INVENTORY_SLOTS),
m_itera(0)
{
	for (int i=0; i<INVENTORY_SLOTS; i++){
		m_pkInvSprt[i] = NULL;
		m_kItmSprt[i] = NULL;
	}
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
bool Inventario::addItem(Item* pkNewItem){

	if((int(getNumChilds()) < m_iSlots))
	{
		if(addNewChild(pkNewItem))
		{
			
			m_kItmSprt[m_itera] = pkNewItem->getSprite();
			m_kItmSprt[m_itera]->setVisible(true);
			m_itera++;
			m_iSlots--;
			//m_kNumItems[getNumChilds()-1]++;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
	//}
	return true;

}
//-----------------------------------------------------------------------
bool Inventario::removeItem(Item* pkItem){

	//	if(!pkItem->removeChild(this))
	if(!removeChild(pkItem))
	{
		return false;
	}
	m_iSlots++;
	return true;
}
//-----------------------------------------------------------------------
Item* Inventario::getItem(int iType){

	int i;
	if (this->getNumChilds() > 0)
	{
		this->goFirstChild();
		for (i = 0; i < m_iSlots; i++)
		{
			if ((this->getCurrentChild()->getType()) == iType)
				break;
		}

		return  (Item*) this->getCurrentChild();

	}

	return NULL;
}
//-----------------------------------------------------------------------
/*void Inventario::setPosItem(float fPosX, float fPosY)
{
	
}*/
//-----------------------------------------------------------------------
void Inventario::setPos(float fPosX, float fPosY)
{
	if (m_pkInvSprt[0])
	{
		float Pos0X = ((INVENTORY_WIDTH * m_pkInvSprt[0]->getDimW()) - (m_pkInvSprt[0]->getDimW() / 2));
		float Pos0Y = ((INVENTORY_HEIGHT * m_pkInvSprt[0]->getDimH()) - (m_pkInvSprt[0]->getDimH() / 2));

		for(int i = 0; i < INVENTORY_HEIGHT; i++)
		{
			for (int j = 0; j < INVENTORY_WIDTH; j++)
			{
				if (m_pkInvSprt[INVENTORY_WIDTH * i + j])
				{
					float fWidth = m_pkInvSprt[INVENTORY_WIDTH * i + j]->getDimW();
					float fHeight = m_pkInvSprt[INVENTORY_WIDTH * i + j]->getDimH();
					if(m_kItmSprt[INVENTORY_WIDTH * i + j] != NULL)
					{
						m_kItmSprt[INVENTORY_WIDTH * i + j]->setPos(Pos0X + fWidth *  i, Pos0Y + fHeight * j);
					}
					else
						{
						m_pkInvSprt[INVENTORY_WIDTH * i + j]->setPos(Pos0X + fWidth *  i, Pos0Y + fHeight * j);					
						}
					}				
				}
			}
		}
	
}
//-----------------------------------------------------------------------