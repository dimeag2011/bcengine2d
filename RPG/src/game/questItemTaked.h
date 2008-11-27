//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "quest.h"
#include <string>
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class QuestItemTaked : public Quest{
public:
QuestItemTaked(string quest);
QuestItemTaked();
~QuestItemTaked();
//---------------------Virtuals--------------------------------------------------------------
virtual void onStart();
virtual void onComplete();
virtual void onTaskComplet();
};