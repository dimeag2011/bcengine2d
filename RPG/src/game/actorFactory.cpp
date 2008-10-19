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
Actor * ActorFactory::CreateActor(string kName ,int iType , int iClass){
	//Seteo la clase
	switch(iClass){
		case TYPE_WARRIOR:	
			m_kClass.sNomClass = "Guerrero";
			m_kClass.iClase = iClass;
			m_kClass.iCa = 15;
			m_kClass.iAtk = 6;
			m_kClass.iMana = 0;
			m_kClass.iVida = 160;
			break;

		case TYPE_MAGE:
			m_kClass.sNomClass = "Mago";
			m_kClass.iClase = iClass;
			m_kClass.iCa = 10;
			m_kClass.iAtk = 0;
			m_kClass.iMana = 150;
			m_kClass.iVida = 60;
			break;

		case TYPE_ROUGE:
			m_kClass.sNomClass = "Ladron";
			m_kClass.iClase = iClass;
			m_kClass.iCa = 12;
			m_kClass.iAtk = 2;
			m_kClass.iMana = 20;
			m_kClass.iVida = 100;
			break;

		case TYPE_CLERIC:
			m_kClass.sNomClass = "Clerigo";
			m_kClass.iClase = iClass;
			m_kClass.iCa = 13;
			m_kClass.iAtk = 3;
			m_kClass.iMana = 60;
			m_kClass.iVida = 120;
			break;

		default:
			m_kClass.sNomClass = "Comun";
			m_kClass.iClase = 99;
			m_kClass.iCa = 10;
			m_kClass.iAtk = 2;
			m_kClass.iMana = 0;
			m_kClass.iVida = 60;
	}// End Switch


	//Seteo el tipo de actor y le paso la clase	
	switch(iType){
		case TYPE_PLAYER:
			m_iActorAux = new Actor(kName,iType, m_kClass);
			//m_iAux->setName(kName);
			m_lKList.push_back(m_iActorAux);
			break;

		case TYPE_NPC:
			m_iActorAux = new Actor(kName,iType,m_kClass);
			//m_iAux->setName(kName);
			m_lKList.push_back(m_iActorAux);
			break;

		case TYPE_MINON:
			m_iActorAux = new Actor(kName,iType,m_kClass);
			//m_iAux->setName(kName);
			m_lKList.push_back(m_iActorAux);
			break;

		case TYPE_BOSS:
			m_iActorAux = new Actor(kName,iType,m_kClass);
			//m_iAux->setName(kName);
			m_lKList.push_back(m_iActorAux);

	}// End Switch
	return m_iActorAux;
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
	{cout << "Nombre: " << m_iActorAux->getName() << endl;}
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