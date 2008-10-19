#pragma once
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "attribute.h"
#include "item.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Potion : public Item
{
	//-----------------------------------------------------------------------------------------
public:
	Potion();
	~Potion();
	Potion(const string &rkName , int iType  ,int iDaño, int iCa, int iResAcd,
		int iResFue, int iResFri ,int iResSon,int iResElec,int iModFue, 
		int iModAgi,  int iModCon, int iModInt,int iModSab, int iModCar, bool bCom);
	//-----------------------------------------------------------------------------------------
	int GetItemType() { return m_iType; }
	void setDescripcion(string &rkDesc);
	string getDescripcion();
public:
	Attribute m_kPotion;
	//-----------------------------------------------------------------------------------------
private:
	int				m_iType;
	string			m_sName;
	string			m_Desc;
	//-----------------------------------------------------------------------------------------
	friend class ItemFactory;
	friend class Actor;
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
