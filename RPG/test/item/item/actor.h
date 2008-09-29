//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "inventario.h"
//-----------------------------------------------------------------------------------------
class Actor:public Component{
public:

	Actor();
	Actor(string rkName , int iType, Clase kClase);
	~Actor();
//-----------------------------------------------------------------------------------------
	void setDescripcion(const string &rkDesc);
	string getDescripcion() const ;
//-----------------------------------------------------------------------------------------
	void setClassHero(Clase kClase);
	int getClassHero();
	void setItemEffect(Item *kItem);
	void removeEffect();
//-----------------------------------------------------------------------------------------
private:
	Inventario* m_kInventory; 
	int m_iType;
	Clase m_kClase;
	string m_sDescript;
};
//-----------------------------------------------------------------------------------------
