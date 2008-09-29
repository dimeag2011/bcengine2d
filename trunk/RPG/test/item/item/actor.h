//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "inventario.h"
//-----------------------------------------------------------------------------------------
class Actor:public Component{
public:

	Actor();
	Actor(string rkName , int iType);
	~Actor();
//-----------------------------------------------------------------------------------------
	void setDescripcion(const string &rkDesc);
	string getDescripcion() const ;

	void setClassHero(Class kClase);
	int getClassHero();

private:
	Inventario* m_kInventory; 

};