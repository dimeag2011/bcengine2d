#pragma once
//-----------------------------------------------------------------------------------------
#include "Evento.h"
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
//class Component;

class ChildAddedEvent : public Evento {
public:
	ChildAddedEvent(Component* kChild);
	

public:
	static const string CHILD_ADDED_Evento;
	Component* kChild;

};

