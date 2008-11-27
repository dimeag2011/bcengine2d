#pragma once
//-----------------------------------------------------------------------------------------
#include "event.h"
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Component;

class ChildAddedEvent : public Event {
public:
	ChildAddedEvent(Component* kChild) : Event(CHILD_ADDED_EVENT) {
		this->kChild = kChild;
	}

public:
	static const string CHILD_ADDED_EVENT;
	Component* kChild;

};

