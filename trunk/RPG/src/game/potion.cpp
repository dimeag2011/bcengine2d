//-----------------------------------------------------------------------------------------
#include "potion.h"
//-----------------------------------------------------------------------------------------
Potion :: Potion()
:
m_sName(""),
m_iType(0)            
{
	m_kPotion.setDaño(0);
	m_kPotion.setCa(0);
	m_kPotion.setResAcd(0);
	m_kPotion.setResFir(0);
	m_kPotion.setResFro(0);
	m_kPotion.setResSon(0);
	m_kPotion.setResElec(0);
	m_kPotion.setStr(0);
	m_kPotion.setDex(0);
	m_kPotion.setCon(0);
	m_kPotion.setInt(0);
	m_kPotion.setWis(0);
	m_kPotion.setCha(0);
	m_kPotion.setReDa(0);
	m_kPotion.setHps(0);
	m_kPotion.setMana(0);
	m_kPotion.setSlotOcu(0);
	m_kPotion.setSref(0);
	m_kPotion.setSstr(0);
	m_kPotion.setSwill(0);

}
//-----------------------------------------------------------------------------------------
Potion :: Potion(const string &rkName , int iType  ,int iDaño, int iCa, int iResAcd,
				 int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				 int iDex,  int iCon, int iInt,int iWis, int iCha, bool bCom) 

:Item(rkName ,iType ,iDaño,iCa,iResAcd,iResFir,iResFro ,iResSon,iResElec,iStr, 
	 iDex,iCon,iInt,iWis,iCha,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, bCom),
m_sName(rkName),
m_iType(iType),
m_bCom(bCom)
{
	//Creo el objeto del tipo atributo

	m_kPotion.setDaño(iDaño);
	m_kPotion.setCa(iCa);
	m_kPotion.setResAcd(iResAcd);
	m_kPotion.setResFir(iResFir);
	m_kPotion.setResFro(iResFro);
	m_kPotion.setResSon(iResSon);
	m_kPotion.setResElec(iResElec);
	m_kPotion.setStr(iStr);
	m_kPotion.setDex(iDex);
	m_kPotion.setCon(iCon);
	m_kPotion.setInt(iInt);
	m_kPotion.setWis(iWis);
	m_kPotion.setCha(iCha);


}
//-----------------------------------------------------------------------------------------
Potion :: ~Potion()
{
	/*delete m_kAweapon;
	m_kAweapon = NULL;

	delete m_kSkill;
	m_kSkill = NULL;
	*/
	/***/
}
