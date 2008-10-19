//-----------------------------------------------------------------------
#include "inventario.h"
//-----------------------------------------------------------------------
Inventario::Inventario()
:
m_iSlots(INVENTORY_SLOTS) 
{
	/*
	for (int i = 0; i < m_iSlots; i++)
	m_kNumItems.push_back(0);
	*/
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

	/*
	int i;
	if (getNumChilds() > 0)
	{
	goFirstChild();
	for (i = 0; i < m_iSlots; i++)
	{
	if ((getCurrentChild()->getName().compare(pkNewItem->getName())) == 0)
	break;
	}
	}
	else
	{
	i = m_iSlots;
	}

	// TO-DO 
	if (i < m_iSlots)
	{
	m_kNumItems[i]++;
	}
	else
	{
	*/
	if((int(getNumChilds()) < m_iSlots))
	{
		if(addNewChild(pkNewItem))
		{
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
	if (getNumChilds() > 0)
	{
		goFirstChild();
		for (i = 0; i < m_iSlots; i++)
		{
			if ((getCurrentChild()->getType()) == iType)
				break;
		}

		return  (Item*) getCurrentChild();

		/*}else{
		cout << "No se encontro Item" <<endl;
		}*/

	}
}
//-----------------------------------------------------------------------
bool onInit(Importer* pkImporter, float fPosX, float fPosY)
{
	/*if( !pkImporter->createSprite("Ghost", m_pkInvSprt) ){
		return true;
	}

	m_pkInvSprt->setName("el Item loco");
	m_pkInvSprt->setDim(50,50);
	m_pkInvSprt->setPos(fPosX, fPosY, 500.0f);
*/
	return false;
}
//-----------------------------------------------------------------------
void Draw(Renderer * pkRenderer)
{

}
//-----------------------------------------------------------------------