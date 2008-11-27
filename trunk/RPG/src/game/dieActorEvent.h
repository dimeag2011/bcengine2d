#pragma once
//-----------------------------------------------------------------------------------------
#include "Evento.h"

//-----------------------------------------------------------------------------------------
using namespace std;
class Component;
//-----------------------------------------------------------------------------------------
class dieActorEvent : public Evento {
public:
	dieActorEvent() : Evento(DIE_ACTOR_Evento) {
		
	}

public:
	static const string DIE_ACTOR_Evento;
	
};
