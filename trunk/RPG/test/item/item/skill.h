#pragma once
//-----------------------------------------------------------------------------------------
#include "functions.h"
using namespace std;
//-----------------------------------------------------------------------------------------
class Skill{
public:
	Skill();
	Skill(int iAppraise,int iBluff, int iConcentration, int iDecipherScript,
		int iDiplomacy,int iDisableDevice, int iHeal, int iHide, int iIntimidate,
		int iListen,int iMoveSilently, int iOpenLock, int iSearch, int iSpellcraft,
		int iSwim,int iUseMagicDevice);
	~Skill();
//-----------------------------------------------------------------------------------------
	void setAppraise(int iAppraise);
	int getAppraise();
	void setBluff(int iBluff);
	int getBluff();
	void setConcentration(int iConcentration);
	int getConcentration();
	void setDecipherScript(int iDecipherScript);
	int getDecipherScript();
	void setDiplomacy(int iDiplomacy);
	int getDiplomacy();
	void setDisableDevice(int iDisableDevice);
	int getDisableDevice();
	void setHeal(int iHeal);
	int getHeal();
	void setHide(int iHide);
	int getHide();
	void setIntimidate(int iIntimidate);
	int getIntimidate();
	void setListen(int iListen);
	int getListen();
    void setMoveSilently(int iMoveSilently);
	int getMoveSilently();
	void setOpenLock(int iOpenLock);
	int getOpenLock();
	void setSearch(int iSearch);
	int getSearch();
	void setSpellcraft(int iSpellcraft);
	int getSpellcraft();
	void setSwim(int iSwim);
	int getSwim();
	void setUseMagicDevice(int iUseMagicDevice);
	int getUseMagicDevice();
//-----------------------------------------------------------------------------------------

private:

	//Skill list
	int m_iAlert;
    int m_iAppraise;
	int m_iBluff;
	int m_iConcentration;
	int m_iDecipherScript;
	int m_iDiplomacy;
	int m_iDisableDevice;       
	int m_iHeal;
	int m_iHide;
	int m_iIntimidate;
	int m_iListen;
	int m_iMoveSilently;
	int m_iOpenLock;
	int m_iSearch;
	int m_iSpellcraft;
	int m_iSwim;
	int m_iUseMagicDevice;
};
//-----------------------------------------------------------------------------------------
#include "skill.inl"
//-----------------------------------------------------------------------------------------