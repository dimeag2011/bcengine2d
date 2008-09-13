//-----------------------------------------------------------------------------------------
#ifndef ARMORWEAPON_H
#define ARMORWEAPON_H
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "item.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class ArmorWeapon : public Component
{
//-----------------------------------------------------------------------------------------
public:
	ArmorWeapon();
	~ArmorWeapon();
	createAweapon(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFue, int iResFri ,int iResSon,int iResElec,int iModFue, 
				int iModAgi,  int iModCon, int iModInt,int iModSab, int iModCar, 
				int iModReDa)
				: Component(const string &rkName,const string &rkType)
	
	
	/*
	void setDaño(int iDaño);
	int  getDaño();
	void setCa(int iCa);
	int  getCa();
	void setResAcd(int iResAcd);
	int  getResAcd();
	void setResFue(int iResFue);
	int  getResFue();
	void setResFri(int iResFri);
	int  getResFri();
	void setResSon(int iResSon);
	int  getResSon();
	void setResElec(int iResElec);
	int  getResElec();
	void setModFue(int iModFue);
	int  getModFue();
	void setModAgi(int iModAgi);
	int  getModAgi();
	void setModCon(int iModCon);
	int  getModCon();
	void setModInt(int iModInt);
	int  getModInt();
	void setModSab(int iModSab);
	int  getModSab();
	void setModCar(int iModCar);
	int  getModCar();
	void setModReDa(int iModReDa);
	int  getModReDa();
    void setHps(int iHps);
	int  getHps();
    void setMana(int iMana);
	int  getMana();
	void setSlotOcu(int iSlotOcu);
	int  getSlotOcu();
	*/
//-----------------------------------------------------------------------------------------
public:
	/*
	int m_iDaño;
	int m_iCa;
	int m_iResAcd;
	int m_iResFue;
	int m_iResFri;
	int m_iResSon;
	int m_iResElec;
	int m_iModFue;
	int m_iModAgi;
	int m_iModCon;
	int m_iModInt;
	int m_iModSab;
	int m_iModCar;
	int m_iModReDa;
	int m_iHps;
	int m_iMana;
	int m_iSlotOcu;
	*/
	Attribute m_kAweapon;
	Skill m_kSkill;
}
//-----------------------------------------------------------------------------------------
//#include "ArmorWeapon.inl"
//-----------------------------------------------------------------------------------------
#endif //ARMORWEAPON_H
//-----------------------------------------------------------------------------------------
