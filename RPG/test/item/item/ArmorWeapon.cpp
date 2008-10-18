//-----------------------------------------------------------------------------------------
#include "ArmorWeapon.h"
//-----------------------------------------------------------------------------------------
ArmorWeapon :: ArmorWeapon()
:
m_sName(""),
m_iType(TYPE_ARMOR),
m_bCom(false)
{
	m_kAweapon.setDaño(0);
	m_kAweapon.setCa(0);
	m_kAweapon.setResAcd(0);
	m_kAweapon.setResFir(0);
	m_kAweapon.setResFro(0);
	m_kAweapon.setResSon(0);
	m_kAweapon.setResElec(0);
	m_kAweapon.setStr(0);
	m_kAweapon.setDex(0);
	m_kAweapon.setCon(0);
	m_kAweapon.setInt(0);
	m_kAweapon.setWis(0);
	m_kAweapon.setCha(0);
	m_kAweapon.setReDa(0);
	m_kAweapon.setHps(0);
	m_kAweapon.setMana(0);
	m_kAweapon.setSlotOcu(0);
	m_kAweapon.setSref(0);
	m_kAweapon.setSstr(0);
	m_kAweapon.setSwill(0);

}
//-----------------------------------------------------------------------------------------
ArmorWeapon :: ArmorWeapon(const string &rkName , int iType  ,int iDaño, int iCa, int iResAcd,
				  int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				  int iDex,  int iCon, int iInt,int iWis, int iCha , bool bCom) 
				  
:Item(rkName ,iType ,iDaño,iCa,iResAcd,iResFir,iResFro ,iResSon,iResElec,iStr, 
				  iDex,iCon,iInt,iWis,iCha,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,bCom),
m_sName(rkName),
m_iType(iType),
m_bCom(bCom)
{
	//Creo el objeto del tipo atributo

	m_kAweapon.setDaño(iDaño);
	m_kAweapon.setCa(iCa);
	m_kAweapon.setResAcd(iResAcd);
	m_kAweapon.setResFir(iResFir);
	m_kAweapon.setResFro(iResFro);
	m_kAweapon.setResSon(iResSon);
	m_kAweapon.setResElec(iResElec);
	m_kAweapon.setStr(iStr);
	m_kAweapon.setDex(iDex);
	m_kAweapon.setCon(iCon);
	m_kAweapon.setInt(iInt);
	m_kAweapon.setWis(iWis);
	m_kAweapon.setCha(iCha);
	

}
//-----------------------------------------------------------------------------------------
ArmorWeapon :: ~ArmorWeapon()
{
	/*delete m_kAweapon;
	m_kAweapon = NULL;
	
	delete m_kSkill;
	m_kSkill = NULL;
*/
	/***/
}
