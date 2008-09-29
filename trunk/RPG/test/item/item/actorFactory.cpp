//-----------------------------------------------------------------------------------------
#include "actorFactory.h"
//-----------------------------------------------------------------------------------------
int ActorFactory :: count = 0;
ActorFactory * ActorFactory::instance = NULL;
//-----------------------------------------------------------------------------------------
ActorFactory::ActorFactory(){

}
//-----------------------------------------------------------------------------------------
ActorFactory::~ActorFactory(){

	ActorFactory::removeAll();
}
//-----------------------------------------------------------------------------------------
Actor * ActorFactory::CreateItem(int m_iType){

	switch(m_iType){
		case TYPE_ARMOR:{
			m_iAux = new Item();
			m_iAux->setName("gloria");
			m_lKList.push_back(m_iAux);
			break;
						}
	}
	return m_iAux;
}
//-----------------------------------------------------------------------------------------
ActorFactory * ActorFactory::GetInstance(){
	if(count ==0)
		instance = new ActorFactory();
	count++;
	return instance;
}
//-----------------------------------------------------------------------------------------
void ActorFactory::GetCreations()
{
	//if(count > 0)
	//	{	
	for (int i = 0; i < count; i++)
	{cout << "Nombre: " << m_iAux->getName() << endl;}
	//	}
}
//-----------------------------------------------------------------------------------------
void ActorFactory::RelaseInstance(){
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