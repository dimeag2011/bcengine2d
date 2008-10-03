//-----------------------------------------------------------------------------------------
#include "Item.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------
Item::Item(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
:
m_kName(""),
m_kType(5),            
m_kModAtt.setDaño(iDaño),
m_kModAtt.setCa(iCa),
m_kModAtt.setResAcd(iResAcd),
m_kModAtt.setResFir(iResFir),
m_kModAtt.setResFro(iResFro),
m_kModAtt.setResSon(iResSon),
m_kModAtt.setResElec(iResElec),
m_kModAtt.setStr(iStr),
m_kModAtt.setDex(iDex),
m_kModAtt.setCon(iCon),
m_kModAtt.setInt(iInt),
m_kModAtt.setWis(iWis),
m_kModAtt.setCha(iCha),
m_kModAtt.setReDa(iReDa),
m_kModAtt.setHps(iHps),
m_kModAtt.setMana(iMana),
m_kModAtt.setSlotOcu(iSlotOcu),
m_kModAtt.setSref(iSref),
m_kModAtt.setSstr(iSstr),
m_kModAtt.setSwill(iSwill)
m_kDesc(""),
m_kPeso(0)
*/

//-----------------------------------------------------------------------------------------
Item::Item()
:
m_bStackeable(0),
m_iMaxStack(0),
m_iType(TYPE_ITEM)
m_kName(""),
m_kType(""),            
m_kModAtt.setDaño(0),
m_kModAtt.setCa(0),
m_kModAtt.setResAcd(0),
m_kModAtt.setResFir(0),
m_kModAtt.setResFro(0),
m_kModAtt.setResSon(0),
m_kModAtt.setResElec(0),
m_kModAtt.setStr(0),
m_kModAtt.setDex(0),
m_kModAtt.setCon(0),
m_kModAtt.setInt(0),
m_kModAtt.setWis(0),
m_kModAtt.setCha(0),
m_kModAtt.setReDa(0),
m_kModAtt.setHps(0),
m_kModAtt.setMana(0),
m_kModAtt.setSlotOcu(0),
m_kModAtt.setSref(0),
m_kModAtt.setSstr(0),
m_kModAtt.setSwill(0)
{
 setType(TYPE_ITEM);
}
//-----------------------------------------------------------------------------------------
Item::~Item()
{
 /*//destruyo las variables de attribute y skill 
	delete m_kModAtt;
   m_kModAtt = NULL;
	
   delete m_kSkill;
   m_kModSkill = NULL;
*/
   /***/
}
//-----------------------------------------------------------------------------------------
void setAttItem(Atrribute kModAtt)
{
	m_kModAtt.setDaño(kModAtt.getDaño()),
	m_kModAtt.setCa(kModAtt.getCa),	
	m_kModAtt.setResAcd(kModAtt.getResAcd()),
	m_kModAtt.setResFir(kModAtt.getResFir()),
	m_kModAtt.setResFro(kModAtt.getResFro()),
	m_kModAtt.setResSon(kModAtt.getResSon()),
	m_kModAtt.setResElec(kModAtt.getResElec()),
	m_kModAtt.setStr(kModAtt.getStr()),
	m_kModAtt.setDex(kModAtt.getDex()),
	m_kModAtt.setCon(kModAtt.getCon()),
	m_kModAtt.setInt(kModAtt.getInt()),
	m_kModAtt.setWis(kModAtt.getWis()),
	m_kModAtt.setCha(kModAtt.getCha()),
	m_kModAtt.setReDa(kModAtt.getReDa()),
	m_kModAtt.setHps(kModAtt.getHps()),
	m_kModAtt.setMana(kModAtt.getMana()),
	m_kModAtt.setSlotOcu(kModAtt.getSlotOcu()),
	m_kModAtt.setSref(kModAtt.getSref());
	m_kModAtt.setSstr(kModAtt.getSstr());
	m_kModAtt.setSwill(kModAtt.setSwill());

}