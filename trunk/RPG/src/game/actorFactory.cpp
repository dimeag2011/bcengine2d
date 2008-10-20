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
	Clase kClass;
	switch(iClass){
		case TYPE_WARRIOR:	
			kClass.sNomClass = "Guerrero";
			kClass.iClase = iClass;
			kClass.iCa = 15;
			kClass.iAtk = 6;
			kClass.iMana = 0;
			kClass.iVida = 160;
			break;

		case TYPE_MAGE:
			kClass.sNomClass = "Mago";
			kClass.iClase = iClass;
			kClass.iCa = 10;
			kClass.iAtk = 0;
			kClass.iMana = 150;
			kClass.iVida = 60;
			break;

		case TYPE_ROUGE:
			kClass.sNomClass = "Ladron";
			kClass.iClase = iClass;
			kClass.iCa = 12;
			kClass.iAtk = 2;
			kClass.iMana = 20;
			kClass.iVida = 100;
			break;

		case TYPE_CLERIC:
			kClass.sNomClass = "Clerigo";
			kClass.iClase = iClass;
			kClass.iCa = 13;
			kClass.iAtk = 3;
			kClass.iMana = 60;
			kClass.iVida = 120;
			break;

		default:
			kClass.sNomClass = "Comun";
			kClass.iClase = 99;
			kClass.iCa = 10;
			kClass.iAtk = 2;
			kClass.iMana = 0;
			kClass.iVida = 60;
			break;
	}// End Switch

	Actor* kActorAux = new Actor(kName, iType, kClass);

	m_lKList.push_back(kActorAux);

	return kActorAux;
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
	/*
	//if(count > 0)
	//	{	
	for (int i = 0; i < count; i++)
	{
		cout << "Nombre: " << m_iActorAux->getName() << endl;
	}
	//	}
	*/
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