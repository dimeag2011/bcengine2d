//-----------------------------------------------------------------------------------------
#ifndef ITEM_H
#define ITEM_H
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "attribute.h"
//-----------------------------------------------------------------------------------------
class Item : public Component
{
public:
	Item();
	Item(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
     : Attribute(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill)
	~Item();

//-----------------------------------------------------------------------------------------
	void setPeso(float &rkPeso);
	float getPeso();
	void setDescripcion(const string &rkDesc);
	string getDescripcion() const ;
	virtual void setAttItem(Atrribute kModAtt);
//-----------------------------------------------------------------------------------------
private:
	string m_kDesc;
	float m_kPeso;
	Attribute m_kModAtt; 
//-----------------------------------------------------------------------------------------	
};
//-----------------------------------------------------------------------------------------
#include "item.inl"
//-----------------------------------------------------------------------------------------
#endif //ITEM_H
//-----------------------------------------------------------------------------------------
