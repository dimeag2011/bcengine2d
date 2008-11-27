#pragma once
//-----------------------------------------------------------------------------------------
#include <string>
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Evento {
public:
	Evento(string name) { m_kName = name; }
	Evento();
	~Evento();
//-----------------------------------------------------------------------------------------
void setEvento(string name){ m_kName = name; }
string getEvento() { return m_kName;}

void setDescrip(string descrip){ m_kDescrip = descrip; }
string getDescrip() { return m_kDescrip; }
//-------------Eventoos----------------------------------------------------------------------
//void childAddendEvento(string name, Component *pkChild);
//bool ChildRemovedEvent(string name, Component *pkChild);
//void addedToParentEvento(string name, Component *pkParent);
//bool removedFromParentEvento(string name, Component *pkParent);
//-----------------------------------------------------------------------------------------
private:
	string m_kName;
	string m_kDescrip;
};
//-----------------------------------------------------------------------------------------
