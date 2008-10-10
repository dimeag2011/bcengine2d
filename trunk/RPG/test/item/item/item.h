//-----------------------------------------------------------------------------------------
#ifndef ITEM_H
#define ITEM_H
//-----------------------------------------------------------------------------------------
#include "component.h"
#include "attribute.h"
#include "skills.h"

using namespace std;
//-----------------------------------------------------------------------------------------
class Item : public Component{
//-----------------------------------------------------------------------------------------
public:
	
	Item();
	//Reever los constructores.
	Item(const string &rkName , int iType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSstr, int iSwill , int iAppraise,
				int iBluff, int iConcentration, int iDecipherScript, int iDiplomacy,
				int iDisableDevice, int iHeal, int iHide, int iIntimidate, int iListen, 
				int iMoveSilently, int iOpenLock, int iSearch, int iSpellcraft, int iSwim,
				int iUseMagicDevice);
    /* : Attribute(const string &rkName , const string &rkType ,int iDaño, int iCa, int iResAcd,
				int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				int iDex,  int iCon, int iInt,int iWis, int iCha, 
				int iReDa, int iHps, int iMana, int iSlotOcu, int iSref,
				int iSStr, int iSwill);*/
	~Item();

//-----------------------------------------------------------------------------------------
	void setPeso(float &rkPeso);
	float getPeso();
	void setDescripcion(const string &rkDesc);
	string getDescripcion() const ;

	int GetItemType() { return m_iType; }
	int GetMaxStack() {return m_iMaxStack; }
	
	//virtual void setAttItem(Atrribute kModAtt);
//-----------------------------------------------------------------------------------------
private:
	string m_kDesc;
	float m_kPeso;
	
	//propidades del item
	bool			m_bStackeable;
	int				m_iMaxStack;
	int				m_iType;
//	string			m_sName;

private:
	Attribute *m_kModAtt; 
	Skill *m_kModSkill;
//-----------------------------------------------------------------------	
friend class ItemFactory;
friend class Actor;
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------------------------
#include "item.inl"
//-----------------------------------------------------------------------------------------
#endif //ITEM_H
//-----------------------------------------------------------------------------------------
