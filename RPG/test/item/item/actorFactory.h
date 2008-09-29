//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "factory.h"
#include "inventario.h"
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
	Actor* CreateActor(int m_iType);
	void GetCreations();
	//------------------------------------------------------------------------------------------
private:
	static int count;
	static ActorFactory * instance;
	Actor * m_iAux;

};
//------------------------------------------------------------------------------------------