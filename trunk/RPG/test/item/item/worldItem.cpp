//-----------------------------------------------------------------------------------------
#include "worldFactory.h"
//-----------------------------------------------------------------------------------------
int WorldFactory :: count = 0;
WorldFactory * WorldFactory::instance = NULL;
//-----------------------------------------------------------------------------------------
WorldFactory::WorldFactory(){

}
//-----------------------------------------------------------------------------------------
WorldFactory::~WorldFactory(){

	WorldFactory::removeAll();
}
//-----------------------------------------------------------------------------------------
void WorldFactory::addWorldItem(Item *pkItem){

		//	m_iAux = new Item();
		//	m_iAux->setName("gloria");
			m_lKList.push_back(pkItem);
			
}
//-----------------------------------------------------------------------------------------
WorldFactory * WorldFactory::GetInstance(){
	if(count ==0)
		instance = new WorldFactory();
	count++;
	return instance;
}
//-----------------------------------------------------------------------------------------
void WorldFactory::GetCreations()
{
/*	//Ver como hacer para que muestre el contenido
	m_iAux = NULL;
	//if(count > 0)
	//	{	
	m_lkListIterator = m_lKList.begin;
	while(m_lkListIterator != m_lKList.end())
	{
		m_iAux = m_lKList.front;
		cout << "Nombre: " << m_iAux->getName() << endl;
	}
*/	
}
//-----------------------------------------------------------------------------------------
void WorldFactory::RelaseInstance(){
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