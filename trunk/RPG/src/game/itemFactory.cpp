//-----------------------------------------------------------------------------------------
#include "itemFactory.h"
//-----------------------------------------------------------------------------------------
int ItemFactory :: count = 0;
ItemFactory * ItemFactory::instance = NULL;
//-----------------------------------------------------------------------------------------
ItemFactory::ItemFactory(){

}
//-----------------------------------------------------------------------------------------
ItemFactory::~ItemFactory(){

	ItemFactory::removeAll();
}
//-----------------------------------------------------------------------------------------
Item * ItemFactory::CreateItem(int m_iType){

	switch(m_iType){
		case TYPE_ARMOR:
			m_iAux = new ArmorWeapon();
			m_iAux->setName("Armadura linda");
			m_lKList.push_back(m_iAux);
			break;

		case TYPE_WEAPON:
			m_iAux = new ArmorWeapon();
			m_iAux->setName("Espada grosa");
			m_lKList.push_back(m_iAux);
			break;
		case TYPE_POTION:
			m_iAux = new Potion();
			m_iAux->setName("Pocion loca");
			m_lKList.push_back(m_iAux);

	}
	return m_iAux;
}
//-----------------------------------------------------------------------------------------
ItemFactory * ItemFactory::GetInstance(){
	if(count ==0)
		instance = new ItemFactory();
	count++;
	return instance;
}
//-----------------------------------------------------------------------------------------
void ItemFactory::GetCreations()
{
	//if(count > 0)
	//	{	
	//			for (int i = 0; i < count; i++)
	//			{cout << "Nombre: " << m_iAux->getName() << endl;}
	//	}
	//Ver como hacer para que muestre el contenido
	m_lkListIterator = m_lKList.begin();

	while(m_lkListIterator != m_lKList.end())
	{
		m_AuxComp = *m_lkListIterator;
		cout << "Nombre: " << m_AuxComp->getName() << endl;

		m_lkListIterator++;

	}




}
//-----------------------------------------------------------------------------------------
void ItemFactory::RelaseInstance(){
	if(count > 0)
	{
		count--;
		if(count < 0)
		{	
			instance = NULL;
			delete instance;
		}
	}
}
//-----------------------------------------------------------------------