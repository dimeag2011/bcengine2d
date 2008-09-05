//-----------------------------------------------------------------------------------------
#ifndef CLASS_H
#define CLASS_H
//-----------------------------------------------------------------------------------------
#include "component.h"
//-----------------------------------------------------------------------------------------
class Class : public Component
{
public:
	Class();
	Class(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
	:Attribute(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
	~Class();	
}


//-----------------------------------------------------------------------------------------
#endif //CLASS_H
//-----------------------------------------------------------------------------------------
