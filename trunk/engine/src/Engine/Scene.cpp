//----------------------------------------------------------------
#include "includes\Scene.h"
#include "includes\Entity2D.h"
#include "includes\Map.h"
//----------------------------------------------------------------
Scene::Scene ()
:
m_pkInput(NULL),
m_pkSound(NULL),
m_pkCurrentMap(NULL)
{
	/***/
}
//----------------------------------------------------------------
Scene::~Scene ()
{
	/***/
}
//----------------------------------------------------------------
bool Scene::init (string kName, Importer* pkImporter, 
				  Input* pkInput, Sound* pkSound, Renderer* pkRenderer)
{
	if (kName == "")
		return false;

	setName(kName);

	if (!pkSound)
		return false;

	m_pkSound = pkSound;

	m_pkInput = pkInput;

	if( !onInit(pkImporter, pkRenderer) )
		return false;

	sortEntitiesByDepth();

	return true;
}
//----------------------------------------------------------------
void Scene::checkAllCollisions ()
{
	if(!m_kpaCollisionGroups.empty())
	{
		CollisionGroupMapIt itBegin = m_kpaCollisionGroups.begin();
		CollisionGroupMapIt itEnd = m_kpaCollisionGroups.end();

		// for each collision group
		for( CollisionGroupMapIt itB = itBegin, itE = (--itEnd); itB != itE; itB++)
		{
			Entity2DVector* pkColGroup1 = itB->second;
			size_t uiGroupCount1 = pkColGroup1->size();
			// for each collision group
			for( CollisionGroupMapIt itAux = (++itB), itE2 = itEnd; itAux != itE2; itAux++)
			{
				Entity2DVector* pkColGroup2 = itAux->second;
				size_t uiGroupCount2 = pkColGroup2->size();

				// for each entity in col group 1
				for(unsigned int k=0; k<uiGroupCount1; k++)
				{
					Entity2D* pkEnt1 = (*pkColGroup1)[k];

					// for each entity in col group 2
					for(unsigned int m=0; m<uiGroupCount2; m++)
					{
						Entity2D* pkEnt2 = (*pkColGroup2)[m];

						// check collision
						if( pkEnt1->checkCollision(pkEnt2) )
						{
							pkEnt1->onCollision(pkEnt2);
							pkEnt2->onCollision(pkEnt1);
						}
					}
				}
			}
		}
	}
}
//----------------------------------------------------------------
bool Scene::update (float fTimeBetweenFrames)
{
	//actualizo el mapa
	if (m_pkCurrentMap)
		m_pkCurrentMap->update(fTimeBetweenFrames);

	// update all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
		m_apkEntities[i]->update(fTimeBetweenFrames);

	// TO-DO: check collision between all the groups
	checkAllCollisions ();

	// user defined update
	return onUpdate(fTimeBetweenFrames);
}
//----------------------------------------------------------------
void Scene::draw (Renderer* pkRenderer) const
{
	//dibujo el mapa
	if (m_pkCurrentMap)
		m_pkCurrentMap->draw();

	// draw all the entities
	for(unsigned int i=0; i<m_apkEntities.size(); i++)
		m_apkEntities[i]->draw(pkRenderer);

	onDraw(pkRenderer);
}
//----------------------------------------------------------------
bool Scene::deinit ()
{
	return onDeinit();
}
//----------------------------------------------------------------
void Scene::sortEntitiesByDepth ()
{
	sort( m_apkEntities.begin(), m_apkEntities.end(), Scene::entity2DComp );
}
//----------------------------------------------------------------
bool Scene::entity2DComp (Entity2D* pkEnt1, Entity2D* pkEnt2)
{
	return ( pkEnt1->getPosZ() > pkEnt2->getPosZ() );
}
//----------------------------------------------------------------
bool Scene::addCollisionGroup (string kName)
{
	// check for empty name
	if(kName == "")
		return false;

	// find if a group with that name already exists
	CollisionGroupMapIt itColGruop = m_kpaCollisionGroups.find(kName);

	if (itColGruop != m_kpaCollisionGroups.end())
		return false;

	// create the group
	Entity2DVector* pkNewGroup = new Entity2DVector();

	m_kpaCollisionGroups[kName] = pkNewGroup;

	return true;
}
//----------------------------------------------------------------
bool Scene::addEntity (Entity2D* pkEntity, string kColGroup)
{
	assert(pkEntity);

	// check for empty collision group name
	if(kColGroup != "")
	{
		// find if a group with that name already exists
		CollisionGroupMapIt itColGruop = m_kpaCollisionGroups.find(kColGroup);

		if (itColGruop == m_kpaCollisionGroups.end())
			return false;

		Entity2DVector* pkColGroup = itColGruop->second;
		assert(pkColGroup);
		
		pkColGroup->push_back(pkEntity);
		pkEntity->setCollisionGroup(kColGroup);
	}

	m_apkEntities.push_back(pkEntity);

	return true;
}
//----------------------------------------------------------------
bool Scene::removeEntity (Entity2D* pkEntity)
{
	// delete from collision group
	const string& kColGroup = pkEntity->getCollisionGroup();
	
	// check for empty collision group name
	if(kColGroup != "")
	{
		// find if a group with that name already exists
		Entity2DVector* pkColGroup = m_kpaCollisionGroups[kColGroup];
		assert(pkColGroup);

		Entity2DVectorIt kEntColIt = find( pkColGroup->begin(), 
												pkColGroup->end(), 
												pkEntity
										);

		pkColGroup->erase(kEntColIt);
	}

	// delete from scene
	Entity2DVectorIt kEntIt = find( m_apkEntities.begin(), 
										m_apkEntities.end(), 
										pkEntity
								);
	m_apkEntities.erase(kEntIt);

	return true;	
}
//----------------------------------------------------------------
bool Scene::changeEntityColGroup (Entity2D* pkEntity, string kNewColGroup)
{
	//guardo el viejo grupo de colision
	const string& kOldColGroup = pkEntity->getCollisionGroup();
	
	//si el new ColGroup no es vacio la agrego a ese grupo
	if (kNewColGroup == "")
	{
		//chequeo si el nuevo grupo de colision existe
		CollisionGroupMapIt itNewColGruop = m_kpaCollisionGroups.find(kNewColGroup);
		if (itNewColGruop == m_kpaCollisionGroups.end())
			return false;

		//si existe la agrego
		Entity2DVector* pkNewColGroup = itNewColGruop->second;
		assert(pkNewColGroup);

		pkNewColGroup->push_back(pkEntity);
		pkEntity->setCollisionGroup(kNewColGroup);
	}	

	//si partenece a algun grupo de colision, la borro de ese grupo
	if (kOldColGroup != "")
	{
		// find if a group with that name already exists
		Entity2DVector* pkOldColGroup = m_kpaCollisionGroups[kOldColGroup];
		assert(pkOldColGroup);

		Entity2DVectorIt kEntColIt = find( pkOldColGroup->begin(), 
												pkOldColGroup->end(), 
												pkEntity
										);

		pkOldColGroup->erase(kEntColIt);
	}

	return true;

}
//----------------------------------------------------------------
bool Scene::removeCollisionGroup (string kName)
{
	// check for empty name
	if(kName == "")
		return false;

	// find if a group with that name already exists
	CollisionGroupMapIt itColGruop = m_kpaCollisionGroups.find(kName);
	if (itColGruop == m_kpaCollisionGroups.end())
		return false;

	// borro la entrada en el mapa del grupo
	m_kpaCollisionGroups.erase(itColGruop);

	return true;
}
