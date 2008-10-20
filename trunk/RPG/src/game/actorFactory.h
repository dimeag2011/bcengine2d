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
public:
	//Actor * m_iActorAux;
private:
	static int count;
	static ActorFactory * instance;
	//Clase m_kClass;

};
//------------------------------------------------------------------------------------------