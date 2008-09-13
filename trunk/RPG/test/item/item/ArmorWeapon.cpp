//-----------------------------------------------------------------------------------------
#include "ArmorWeapon.h"
//-----------------------------------------------------------------------------------------
ArmorWeapon : ArmorWeapon()
:
m_kName(""),
m_kType(""),            
m_iDaño(iDaño),
m_iCa(iCa),
m_iResAcd(iResAcd),
m_iResFue(iResFue),
m_iResFri(iResFri),
m_iResSon(iResSon),
m_iResElec(iResElec),
m_iModFue(iModFue),
m_iModAgi(iModAgi),
m_iModCon(iModCon),
m_iModInt(iModInt),
m_iModSab(iModSab),
m_iModCar(iModCar),
m_iModReDa(iModReDa)
{
 /***/
}
//-----------------------------------------------------------------------------------------
ArmorWeapon : createAweapon()
:
m_kName(&rkName),
m_kType(&rkType)            
{
	//Creo el objeto del tipo atributo
	m_kAweapon = new Attribute();
	
	m_kAweapon.setDaño(iDaño);
	m_kAweapon.setCa(iCA);
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
	m_kAweapon.setReDa(iReDa);
	m_kAweapon.setHps(iHps);
	m_kAweapon.setMana(iMana);
	m_kAweapon.setSlotOcu(iSlotOcu);
	m_kAweapon.setSref(iSref);
	m_kAweapon.setSStr(iSStr);
	m_kAweapon.setSwill(iSwill);

	m_kSkill = new Skill();
}
//-----------------------------------------------------------------------------------------
ArmorWeapon : ~ArmorWeapon()
{
	delete m_kAweapon;
	m_kAweapon = NULL;
	
	delete m_kSkill;
	m_kSkill = NULL;

	/***/
}
