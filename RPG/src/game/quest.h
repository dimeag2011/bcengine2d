//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "event.h"
#include <string>
#include <vector>
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Quest : public Component{
public:
	Quest(string quest) { m_kQuest = quest; }
	Quest();
	~Quest();
//-----------------------------------------------------------------------------------------
void Activate(){m_kActivate = true;}
void Desactivate(){m_kActivate = false;}
//-----------------------------------------------------------------------------------------
bool IsItemAdded(string name);
bool IsQuestCompleted(); 
void setQuest(string quest){ m_kQuest = quest; }
string getQuest() { return m_kQuest;}
//---------------------Virtuals--------------------------------------------------------------
virtual void onStart();
virtual void onComplete();
virtual void onTaskComplet();
virtual void onEvent(Event *pkEvent, Component* dispatcher);
//-----------------------------------------------------------------------------------------
public:
	string	m_kQuest;
	string  m_kDescrip;
private:
	bool m_kActivate;
	vector<string> m_kVecQuest;

};