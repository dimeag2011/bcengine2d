#pragma once
//-----------------------------------------------------------------------------------------
#include "event.h"
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Component;

class ChildRemoveEvent : public Event {
public:
	ChildRemoveEvent(Component* kChild) : Event(CHILD_REMOVE_EVENT) {
		this->kChild = kChild;
	}

public:
	static const string CHILD_REMOVE_EVENT;
	Component* kChild;

};