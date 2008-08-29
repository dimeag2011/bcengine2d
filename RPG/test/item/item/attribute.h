//-----------------------------------------------------------------------------------------
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
//-----------------------------------------------------------------------------------------
#include "component.h"
//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Attribute : public Component
{
//-----------------------------------------------------------------------------------------
public:
	Attribute();
	Attribute(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
				: Component(const string &rkName,const string &rkType)
	
	void setDaño(int iDaño);
	int  getDaño();
	void setCa(int iCa);
	int  getCa();
	void setResAcd(int iResAcd);
	int  getResAcd();
	void setResFir(int iResFir);
	int  getResStr();
	void setResFro(int iResFro);
	int  getResFro();
	void setResSon(int iResSon);
	int  getResSon();
	void setResElec(int iResElec);
	int  getResElec();
	void setStr(int iStr);
	int  getStr();
	void setDex(int iDex);
	int  getDex();
	void setCon(int iCon);
	int  getCon();
	void setInt(int iInt);
	int  getInt();
	void setWis(int iWis);
	int  getWis();
	void setCha(int iCha);
	int  getCha();
	void setReDa(int iReDa);
	int  getReDa();
    void setHps(int iHps);
	int  getHps();
    void setMana(int iMana);
	int  getMana();
	void setSlotOcu(int iSlotOcu);
	int  getSlotOcu();
	void setSref(int iSref);
	int  getSref();
	void setSStr(int iSStr);
	int  getSStr();
	void setSwill(int iSwill);
	int  getSwill();
//-----------------------------------------------------------------------------------------
private:
	int m_iDaño;
	int m_iCa;
	int m_iResAcd;
	int m_iResFir;
	int m_iResFro;
	int m_iResSon;
	int m_iResElec;
	int m_iStr;
	int m_iDex;
	int m_iCon;
	int m_iInt;
	int m_iWis;
	int m_iCha;
	int m_iReDa;
	int m_iHps;
	int m_iMana;
	int m_iSlotOcu;
	int m_iSref;
	int m_iSstr;
	int m_iSwill; 
}
//-----------------------------------------------------------------------------------------
#include "attribute.inl"
//-----------------------------------------------------------------------------------------
#endif //ATTRIBUTE_H
//-----------------------------------------------------------------------------------------
