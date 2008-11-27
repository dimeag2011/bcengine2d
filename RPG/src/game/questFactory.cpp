//-----------------------------------------------------------------------------------------
#include "questFactory.h"
//-----------------------------------------------------------------------------------------
int QuestFactory :: count = 0;
QuestFactory * QuestFactory::instance = NULL;
//-----------------------------------------------------------------------------------------
QuestFactory::QuestFactory(){

}
//-----------------------------------------------------------------------------------------
QuestFactory::~QuestFactory(){

	QuestFactory::removeAll();
}
//-----------------------------------------------------------------------------------------
Quest * QuestFactory::CreateQuest(int iQuestType){
	//Seteo de quest
	Quest* kQuestAux = new Quest();
	switch(iQuestType){
		case TYPE_KILL_MONSTER:	
			kQuestAux->setQuest("Matar al Troll guacho");
			break;

		case TYPE_TAKE_ITEM:
			kQuestAux->setQuest("Agarra la posion espectacular");
			break;

		case TYPE_SPEAKE_TO:
			kQuestAux->setQuest("El aldeano vago");

			break;
		
		default:
			kQuestAux->setQuest("Matar al Troll guacho");
	
	}// End Switch

	
	//m_lKList.push_back(kActorAux);

	return kQuestAux;
}

//-----------------------------------------------------------------------------------------
QuestFactory * QuestFactory::GetInstance(){
	if(count ==0)
		instance = new QuestFactory();
	count++;
	return instance;
}
//-----------------------------------------------------------------------------------------
void QuestFactory::GetCreations()
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
void QuestFactory::RelaseInstance(){
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