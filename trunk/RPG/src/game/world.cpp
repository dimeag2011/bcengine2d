//-----------------------------------------------------------------------------------------
#include "world.h"
//-----------------------------------------------------------------------------------------
World::World(){

}
//-----------------------------------------------------------------------------------------
World::~World(){

	
}
//-----------------------------------------------------------------------------------------
void World::addWorldComp(Component *pkComp)
{
	if(addNewChild(pkComp));
}
//-----------------------------------------------------------------------------------------
void World::GetCreations()
{
	
}
//-----------------------------------------------------------------------------------------
bool World::removeWorldComp(Component* pkComp){

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
void World::onEvento(Evento *pkEvento, Component* dispatcher){

	DispachEvento(pkEvento);


}