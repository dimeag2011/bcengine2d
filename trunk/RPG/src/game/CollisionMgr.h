//---------------------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------------------
#include "Component.h"
#include "CollisionObject.h"
#include "Entity2D.h"
//---------------------------------------------------------------------------------------
class CollisionMgr  : public Component{
//---------------------------------------------------------------------------------------
	CollisionMgr();
	~CollisionMgr();
//---------------------------------------------------------------------------------------
	void OnAddedToParent(Component *pkParent);
	void OnRemovedParent(Component *pkParent);
	void OnChildRemoved(Component *pkChild);
	void OnChildAdded(string sEvent,Component * pkChild);
	void onEvent(Event *event, Component* dispatcher);
//---------------------------------------------------------------------------------------	
//---------------------------------------------------------------------------------------
};