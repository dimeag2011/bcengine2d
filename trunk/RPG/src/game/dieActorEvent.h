#pragma once
//-----------------------------------------------------------------------------------------
#include "event.h"

//-----------------------------------------------------------------------------------------
using namespace std;
class Component;
//-----------------------------------------------------------------------------------------
class DieActorEvent : public Event {
public:
	DieActorEvent() : Event(DIE_ACTOR_EVENT) {
		
	}

public:
	static const string DIE_ACTOR_EVENT;
	
};
