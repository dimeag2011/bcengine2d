//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "inventario.h"
#include "actor.h"
#include <iostream>
//-----------------------------------------------------------------------------------------
class ActorFactory : public Factory
{
private:
	ActorFactory();
	~ActorFactory();
//-------------------------------------------------------------------------------------------
public:
	static ActorFactory * GetInstance();
	static void RelaseInstance();
	Actor* CreateActor(string kName ,int iType , int iClass);
	void GetCreations();
//------------------------------------------------------------------------------------------
private:
	static int count;
	static ActorFactory * instance;
	Actor * m_iAux;
	Clase m_kClass;

};
//------------------------------------------------------------------------------------------