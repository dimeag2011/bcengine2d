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
				int iUseMagicDevice, bool bCom);
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
	void setConsumable(bool bCon){ m_bConsumable = bCon; }
;//-----------------------------------------------------------------------------------------
	int GetItemType() { return m_iType; }
	bool GetConsumable() {return m_bConsumable; }
//-----------------------------------------------------------------------------------------
	void setAttributes(int iResAcd,int iResFir, int iResFro ,int iResSon,int iResElec
						,int iStr,int iDex,int iCon, int iInt,int iWis, int iCha,bool bCon);
	
	//virtual void setAttItem(Atrribute kModAtt);
//-----------------------------------------------------------------------------------------
private:
	string m_kDesc;
	float m_kPeso;
	
	//propidades del item
	bool			m_bConsumable;
	int				m_iMaxStack;
	int				m_iType;
	string			m_sName;

	Attribute m_kAttAux; 
	Skill m_kSkillAux;

private:
	Attribute m_kModAtt; 
	Skill m_kModSkill;
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
