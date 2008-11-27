#pragma once
//-----------------------------------------------------------------------------------------
#include "Evento.h"
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Component;

class ChildRemoveEvent : public Evento 
{
//class ChildRemoveEvent : public Evento {
public:
	ChildRemoveEvent(Component* kChild);
	
public:
	static const string CHILD_REMOVE_Evento;
	Component* kChild;

};