//-----------------------------------------------------------------------------------------
#include "Item.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------
/*Item::Item()
:
Attribute(),
m_kName(""),
m_kType(5),            
m_iDaño(iDaño),
m_iCa(iCa),
m_iResAcd(iResAcd),
m_iResFir(iResFir),
m_iResFro(iResFro),
m_iResSon(iResSon),
m_iResElec(iResElec),
m_iStr(iStr),
m_iDex(iDex),
m_iCon(iCon),
m_iInt(iInt),
m_iWis(iWis),
m_iCha(iCha),
m_iReDa(iReDa),
m_iHps(iHps),
m_iMana(iMana),
m_iSlotOcu(iSlotOcu),
m_iSref(iSref),
m_iSstr(iSstr),
m_iSwill(iSwill)
m_kDesc(""),
m_kPeso(0)
*/

//-----------------------------------------------------------------------------------------
Item::Item()
:
m_bStackeable(0),
m_iMaxStack(0),
m_iType(TYPE_ITEM)
/*
Attribute(),
m_kName(""),
m_kType(""),            
m_iDaño(0),
m_iCa(0),
m_iResAcd(0),
m_iResFir(0),
m_iResFro(0),
m_iResSon(0),
m_iResElec(0),
m_iStr(0),
m_iDex(0),
m_iCon(0),
m_iInt(0),
m_iWis(0),
m_iCha(0),
m_iReDa(0),
m_iHps(0),
m_iMana(0),
m_iSlotOcu(0),
m_iSref(0),
m_iSstr(0),
m_iSwill(0),
*/
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
