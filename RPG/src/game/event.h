#pragma once
//-----------------------------------------------------------------------------------------
#include <string>
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Event {
public:
	Event(string name) { m_kName = name; }
	Event();
	~Event();
//-----------------------------------------------------------------------------------------
void setEvent(string name){ m_kName = name; }
string getEvent() { return m_kName;}

void setDescrip(string descrip){ m_kDescrip = descrip; }
string getDescrip() { return m_kDescrip; }
//-------------Eventos----------------------------------------------------------------------
//void childAddendEvent(string name, Component *pkChild);
//bool childRemovedEvent(string name, Component *pkChild);
//void addedToParentEvent(string name, Component *pkParent);
//bool removedFromParentEvent(string name, Component *pkParent);
//-----------------------------------------------------------------------------------------
private:
	string m_kName;
	string m_kDescrip;
};
//-----------------------------------------------------------------------------------------
