//-----------------------------------------------------------------------------------------
#include "itemFactory.h"
//-----------------------------------------------------------------------------------------
int ItemFactory::count = 0;
ItemFactory * ItemFactory::instance = NULL;
//-----------------------------------------------------------------------------------------
ItemFactory::ItemFactory(){

}
//-----------------------------------------------------------------------------------------
ItemFactory::~ItemFactory(){

	ItemFactory::removeAll();
}
//-----------------------------------------------------------------------------------------
Item* ItemFactory::CreateItem(string m_kType){

	if(strcmp(m_kType,"ArmorWeapon")){
		m_ikAux = new ArmorWeapon();
        m_lkItemList.push_back(m_ikAux);
	}else {
	
		/***/
		//Agregar tipos futuros de items
	}   
  return m_ikAux;
}
//-----------------------------------------------------------------------------------------
ItemFactory * ItemFactory::GetInstance(){
	if(count ==0)
		instance = new ItemFactory();
	count++;
	return instance;
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
