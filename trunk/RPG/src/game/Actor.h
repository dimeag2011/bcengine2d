//-----------------------------------------------------------------------------------------
#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "inventario.h"
#include "attribute.h"
#include "skills.h"
#include "Defines.h"
#include "event.h"
#include <iostream>
//-----------------------------------------------------------------------------------------
using namespace std;

class DieActorEvent;
class Component;

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
	Attribute GetAttributes() {return m_kActAtt;}
	
//-----------------------------------------------------------------------------------------
	void setItemEffect(Item *kItem);
	void removeEffect(string m_sName);
	void removeEquipable(Item *kItem);
	void putItemInventory(Item *kItem);
	void removeItemInventory(Item *kItem);
	void useItem(int iType);
//-----------------------------------------------------------------------------------------
	void onEvent(Event *event, Component* dispatcher);
//-----------------------------------------------------------------------------------------
	//void Draw(Renderer* pkReenderer);
	//bool onInit(Importer* pkImporter, float fPosX, float fPosY, string sName);
	Sprite * getSprite(){ return m_pkActorSpr; }
	void setSprite(Sprite* kSprite) { m_pkActorSpr = kSprite;}
//-----------------------------------------------------------------------------------------
private:
	Item		*m_kAEffect[10];


	int			m_iType;
	Clase		m_kClass;
	string		m_sDescript;
	string		m_sName; 
	//Atributos y skills del actor	
	Attribute  m_kActAtt;
	Skill		m_kActSki;


	float		m_fPosX;
	float		m_fPosY;

	Sprite		*m_pkActorSpr;

public:
	Inventario *m_kInventory; 
	Attribute  m_kAuxActAtt;
	Skill		m_kAuxActSki;
	int			i,z;
};
//-----------------------------------------------------------------------------------------
