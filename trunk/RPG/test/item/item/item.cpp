//-----------------------------------------------------------------------------------------
#include "Item.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------
Item::Item(const string &rkName , int iType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSstr, int iSwill , int iAppraise,
				int iBluff, int iConcentration, int iDecipherScript, int iDiplomacy,
				int iDisableDevice, int iHeal, int iHide, int iIntimidate, int iListen, 
				int iMoveSilently, int iOpenLock, int iSearch, int iSpellcraft, int iSwim,
				int iUseMagicDevice)
:Component(rkName , iType),
//m_sName(rkName),
m_iType(iType),
m_kDesc(""),
m_kPeso(0)
{
	m_kModAtt = new Attribute();
	m_kModSkill = new Skill();

	m_kModAtt->setDaño(iDaño);
	m_kModAtt->setCa(iCa);
	m_kModAtt->setResAcd(iResAcd);
	m_kModAtt->setResFir(iResFir);
	m_kModAtt->setResFro(iResFro);
	m_kModAtt->setResSon(iResSon);
	m_kModAtt->setResElec(iResElec);
	m_kModAtt->setStr(iStr);
	m_kModAtt->setDex(iDex);
	m_kModAtt->setCon(iCon);
	m_kModAtt->setInt(iInt);
	m_kModAtt->setWis(iWis);
	m_kModAtt->setCha(iCha);
	m_kModAtt->setReDa(iReDa);
	m_kModAtt->setHps(iHps);
	m_kModAtt->setMana(iMana);
	m_kModAtt->setSlotOcu(iSlotOcu);
	m_kModAtt->setSref(iSref);
	m_kModAtt->setSstr(iSstr);
	m_kModAtt->setSwill(iSwill);
	
	m_kModSkill->setAppraise(iAppraise);
	m_kModSkill->setBluff(iBluff);
	m_kModSkill->setConcentration(iConcentration);
	m_kModSkill->setDecipherScript(iDecipherScript);
	m_kModSkill->setDiplomacy(iDiplomacy);
	m_kModSkill->setDisableDevice(iDisableDevice);
	m_kModSkill->setHeal(iHeal);
	m_kModSkill->setHide(iHide);
	m_kModSkill->setIntimidate(iIntimidate);
	m_kModSkill->setListen(iListen);
	m_kModSkill->setMoveSilently(iMoveSilently);
	m_kModSkill->setOpenLock(iOpenLock);
	m_kModSkill->setSearch(iSearch);
	m_kModSkill->setSpellcraft(iSpellcraft);
	m_kModSkill->setSwim(iSwim);
	m_kModSkill->setUseMagicDevice(iUseMagicDevice);

}
//-----------------------------------------------------------------------------------------
Item::Item()
:
Component(),
m_bStackeable(0),
m_iMaxStack(0),
m_iType(TYPE_ITEM)
//m_sName("")
{
	
	m_kModAtt = new Attribute();
	m_kModSkill = new Skill();

	m_kModAtt->setDaño(0);
	m_kModAtt->setCa(0);
	m_kModAtt->setResAcd(0);
	m_kModAtt->setResFir(0);
	m_kModAtt->setResFro(0);
	m_kModAtt->setResSon(0);
	m_kModAtt->setResElec(0);
	m_kModAtt->setStr(0);
	m_kModAtt->setDex(0);
	m_kModAtt->setCon(0);
	m_kModAtt->setInt(0);
	m_kModAtt->setWis(0);
	m_kModAtt->setCha(0);
	m_kModAtt->setReDa(0);
	m_kModAtt->setHps(0);
	m_kModAtt->setMana(0);
	m_kModAtt->setSlotOcu(0);
	m_kModAtt->setSref(0);
	m_kModAtt->setSstr(0);
	m_kModAtt->setSwill(0);
	m_kModSkill->setAppraise(0);
	m_kModSkill->setBluff(0);
	m_kModSkill->setConcentration(0);
	m_kModSkill->setDecipherScript(0);
	m_kModSkill->setDiplomacy(0);
	m_kModSkill->setDisableDevice(0);
	m_kModSkill->setHeal(0);
	m_kModSkill->setHide(0);
	m_kModSkill->setIntimidate(0);
	m_kModSkill->setListen(0);
	m_kModSkill->setMoveSilently(0);
	m_kModSkill->setOpenLock(0);
	m_kModSkill->setSearch(0);
	m_kModSkill->setSpellcraft(0);
	m_kModSkill->setSwim(0);
	m_kModSkill->setUseMagicDevice(0);

}
//-----------------------------------------------------------------------------------------
Item::~Item()
{
 //destruyo las variables de attribute y skill 
	delete m_kModAtt;
   m_kModAtt = NULL;
	
   delete m_kModSkill;
   m_kModSkill = NULL;

   /***/
}
//-----------------------------------------------------------------------------------------
