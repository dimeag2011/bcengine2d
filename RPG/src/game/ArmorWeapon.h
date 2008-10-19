//-----------------------------------------------------------------------------------------
#ifndef ARMORWEAPON_H
#define ARMORWEAPON_H
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "attribute.h"
#include "item.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class ArmorWeapon : public Item
{
	//-----------------------------------------------------------------------------------------
public:
	ArmorWeapon();
	~ArmorWeapon();
	ArmorWeapon(const string &rkName , int iType  ,int iDaño, int iCa, int iResAcd,
		int iResFue, int iResFri ,int iResSon,int iResElec,int iModFue, 
		int iModAgi,  int iModCon, int iModInt,int iModSab, int iModCar , bool bCom);
	//-----------------------------------------------------------------------------------------
	int GetItemType() { return m_iType; }
	void setDescripcion(string &rkDesc);
	string getDescripcion();
public:
	Attribute m_kAweapon;
	//-----------------------------------------------------------------------------------------
private:
	int				m_iType;
	string			m_sName;
	string			m_Desc;
	bool			m_bCom;
	//-----------------------------------------------------------------------------------------
	friend class ItemFactory;
	friend class Actor;
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//#include "ArmorWeapon.inl"
//-----------------------------------------------------------------------------------------
#endif //ARMORWEAPON_H
//-----------------------------------------------------------------------------------------
