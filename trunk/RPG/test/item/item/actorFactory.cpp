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
Actor * ActorFactory::CreateActor(int iType , int iClass){
//Seteo la clase
	switch(iClass){
		case TYPE_WARRIOR:	
				m_kClass.iCa = 15;
				m_kClass.iAtk = 6;
				m_kClass.iMana = 0;
				m_kClass.iVida = 160;
				break;

		case TYPE_MAGE:
				m_kClass.iCa = 10;
				m_kClass.iAtk = 0;
				m_kClass.iMana = 150;
				m_kClass.iVida = 60;
				break;
		
		case TYPE_ROUGE:
				m_kClass.iCa = 12;
				m_kClass.iAtk = 2;
				m_kClass.iMana = 20;
				m_kClass.iVida = 100;
				break;
		
		case TYPE_CLERIC:
				m_kClass.iCa = 13;
				m_kClass.iAtk = 3;
				m_kClass.iMana = 60;
				m_kClass.iVida = 120;
				break;
	
		case default:
				m_kClass.iCa = 10;
				m_kClass.iAtk = 2;
				m_kClass.iMana = 0;
				m_kClass.iVida = 60;
	}// End Switch
	
	
	//Seteo el tipo de actor	
	switch(m_iType){
		case TYPE_PLAYER:
				m_iAux = new Actor("",m_kClass);
				m_iAux->setName("Player");
				m_lKList.push_back(m_iAux);
				break;

		case TYPE_NPC:
				m_iAux = new Actor("",m_kClass);
				m_iAux->setName("NPC");
				m_lKList.push_back(m_iAux);
				break;
		
		case TYPE_MINON:
				m_iAux = new Actor("",m_kClass);
				m_iAux->setName("Minon");
				m_lKList.push_back(m_iAux);
				break;
		case TYPE_BOSS:
				m_iAux = new Actor("",m_kClass);
				m_iAux->setName("Boss");
				m_lKList.push_back(m_iAux);
	}// End Switch
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