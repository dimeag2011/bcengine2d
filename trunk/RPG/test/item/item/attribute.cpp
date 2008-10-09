//-----------------------------------------------------------------------------------------
#include "Attribute.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------

Attribute :: Attribute(int iDaño, int iCa, int iResAcd,
					   int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
					   int iDex,  int iCon, int iInt,int iWis, int iCha, 
					   int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
					   int iSstr, int iSwill)
:
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
{
 /***/
}

//-----------------------------------------------------------------------------------------

Attribute :: Attribute()
:
//Component(),
//m_kName(""),
//m_iType(TYPE_ITEM),            
m_iDaño(0) ,
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
m_iSwill(0)
{
 /***/
}
//-----------------------------------------------------------------------------------------
Attribute::~Attribute()
{
 /***/
}

//-----------------------------------------------------------------------------------------