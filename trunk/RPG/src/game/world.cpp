//-----------------------------------------------------------------------------------------
#include "world.h"
//-----------------------------------------------------------------------------------------
World::World(){

}
//-----------------------------------------------------------------------------------------
World::~World(){

	//removeAll();
}
//-----------------------------------------------------------------------------------------
void World::addWorldComp(Component pkComp){

	WorldList.push_back(pkComp);

}
//-----------------------------------------------------------------------------------------
void World::GetCreations()
{
	/*
	//Ver como hacer para que muestre el contenido
	WorldListIterator = WorldList.begin();
	//if(count > 0)
	//	{	
	while(WorldListIterator != WorldList.end())
	{
		m_iAux = *WorldListIterator;
		cout << "Nombre: " << m_iAux.getName() << endl;

		WorldListIterator++;
	}
	*/

}
//-----------------------------------------------------------------------------------------
bool World::removeWorldComp(Component pkComp){

	/*WorldListIterator = WorldList.begin();

	while((WorldListIterator!= WorldList.end()) && (*WorldListIterator != pkComp))
	{
		WorldListIterator++;
	}
	if(WorldListIterator == WorldList.end()){

		return false;

	}else{

		WorldList.erase(WorldListIterator);

		return true;
	}
*/
	return true;
}
//-----------------------------------------------------------------------