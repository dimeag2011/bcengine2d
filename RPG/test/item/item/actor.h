//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "inventario.h"
#include "attribute.h"
#include "skills.h"
#include "Defines.h"
#include <iostream>
//-----------------------------------------------------------------------------------------
using namespace std;

class Actor : public Component{
public:

	Actor();
	Actor(const string rkName , int iType, Clase kClase);
	~Actor();
//-----------------------------------------------------------------------------------------
	void setDescripcion(const string &rkDesc);
	string getDescripcion() const ;
//-----------------------------------------------------------------------------------------
	void setClassHero(int iClase);
	Clase getClassHero();
	void setAttributes(int iResAcd,int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				       int iDex,int iCon, int iInt,int iWis, int iCha);
//-----------------------------------------------------------------------------------------
	void setItemEffect(Item *kItem);
	void removeEffect(string m_sName);
	void putItemInventory(Item *kItem);
	void removeItemInventory(Item *kItem);
	void useItem(int iType);
//-----------------------------------------------------------------------------------------
private:
	Inventario *m_kInventory; 
	Item		*m_kAEffect[10];
	

	int			m_iType;
	Clase		m_kClass;
	string		m_sDescript;
	string		m_sName; 
//Atributos y skills del actor	
	Attribute   m_kActAtt;
	Skill		m_kActSki;

public:
	Attribute   m_kAuxActAtt;
	Skill		m_kAuxActSki;
	int			i,z;
};
//-----------------------------------------------------------------------------------------
