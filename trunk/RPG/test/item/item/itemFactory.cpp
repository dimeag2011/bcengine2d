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
		case TYPE_ARMOR:{
			//m_iAux = new Armor();
			m_lKList.push_back(m_iAux);
			break;
		 	}
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