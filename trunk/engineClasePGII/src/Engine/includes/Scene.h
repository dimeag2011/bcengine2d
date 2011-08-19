//----------------------------------------------------------------
#ifndef SCENE_H
#define SCENE_H
//----------------------------------------------------------------
#include "Defines.h"
//----------------------------------------------------------------
class Renderer;
class Entity2D;
class Importer;
class Input;
class Sound;
class Map;
//----------------------------------------------------------------
class ENGINE_API Scene
{
// constructor / destructor
public:
	Scene ();
	virtual ~Scene ();

// name
private:
	string m_kName;

public:
	const string& getName() const;
	void setName(string kName);

// main loop steps
public:
	bool init (string kName, Importer* pkImporter, 
		Input* pkInput, Sound* pkSound, Renderer* pkRenderer);
	bool update (float fTimeBetweenFrames);
	void draw (Renderer* pkRenderer) const;
	bool deinit ();

// mapa
	void setCurrentMap(Map* pkMap);

// entity handling
public:
	bool addEntity (Entity2D* pkEntity, string kColGroup = "");
	bool removeEntity (Entity2D* pkEntity);
	bool changeEntityColGroup (Entity2D* pkEntity, string kNewColGroup);

// collision handling
public:
	bool addCollisionGroup (string kName);
	bool removeCollisionGroup (string kName);

// application specific steps
protected:
	virtual bool onInit (Importer* pkImporter, Renderer* pkRenderer) = 0;
	virtual bool onUpdate (float fTimeBetweenFrames) = 0;
	virtual void onDraw (Renderer* rkRenderer) const = 0;
	virtual bool onDeinit () = 0;

	void sortEntitiesByDepth ();

// services
protected:
	Input* m_pkInput;
	Sound* m_pkSound;

// entities
private:

	typedef vector<Entity2D*> Entity2DVector;
	typedef Entity2DVector::iterator Entity2DVectorIt;

	// entities
	Entity2DVector m_apkEntities;

	// mapa
	Map* m_pkCurrentMap;

	// collision groups
	typedef map< string, Entity2DVector* > CollisionGroupMap;
	typedef map< string, Entity2DVector* >::iterator CollisionGroupMapIt;

	CollisionGroupMap m_kpaCollisionGroups;

	void checkAllCollisions ();

	// Entity2D comparison function to sort
	static bool entity2DComp (Entity2D* pkEnt1, Entity2D* pkEnt2);
};
//----------------------------------------------------------------
#include "Scene.inl"
//----------------------------------------------------------------
#endif // SCENE_H
//----------------------------------------------------------------