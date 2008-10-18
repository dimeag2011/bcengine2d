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
void WorldFactory::addWorldComp(Component pkComp){

		WorldList.push_back(pkComp);
			
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
	//Ver como hacer para que muestre el contenido
	WorldListIterator = WorldList.begin();
	//if(count > 0)
	//	{	
	while(WorldListIterator != WorldList.end())
	{
		m_iAux = WorldList.front();
		cout << "Nombre: " << m_iAux.getName() << endl;
		
		WorldListIterator++;
	}
	
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
bool WorldFactory::removeWorldComp(Component pkComp){

	WorldListIterator = WorldList.begin();
	
	while((WorldListIterator != WorldList.end()) && (WorldListIterator != pkComp))
	{
		WorldListIterator++;
	}
	if(WorldListIterator == WorldList.end()){
		return false
	}else{
	
			WorldList.erase(WorldListIterator);
		return true
	}
	
}
//-----------------------------------------------------------------------