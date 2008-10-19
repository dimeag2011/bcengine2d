//-----------------------------------------------------------------------------------------
#include "skills.h"
//-----------------------------------------------------------------------------------------
Skill :: Skill(int iAppraise,
			   int iBluff, int iConcentration, int iDecipherScript, int iDiplomacy,
			   int iDisableDevice, int iHeal, int iHide, int iIntimidate, int iListen, 
			   int iMoveSilently, int iOpenLock, int iSearch, int iSpellcraft, int iSwim,
			   int iUseMagicDevice)
			   :
//m_iAlert(iAlert);
m_iAppraise(iAppraise),
m_iBluff(iBluff),
m_iConcentration(iConcentration),
m_iDecipherScript(iDecipherScript),
m_iDiplomacy(iDiplomacy),
m_iDisableDevice(iDisableDevice),       
m_iHeal(iHeal),
m_iHide(iHide),
m_iIntimidate(iIntimidate),
m_iListen(iListen),
m_iMoveSilently(iMoveSilently),
m_iOpenLock(iOpenLock),
m_iSearch(iSearch),
m_iSpellcraft(iSpellcraft),
m_iSwim(iSwim),
m_iUseMagicDevice(iUseMagicDevice)
{
	/***/
}
//-----------------------------------------------------------------------------------------
Skill :: Skill()
:
m_iAlert(0),
m_iAppraise(0),
m_iBluff(0),
m_iConcentration(0),
m_iDecipherScript(0),
m_iDiplomacy(0),
m_iDisableDevice(0),       
m_iHeal(0),
m_iHide(0),
m_iIntimidate(0),
m_iListen(0),
m_iMoveSilently(0),
m_iOpenLock(0),
m_iSearch(0),
m_iSpellcraft(0),
m_iSwim(0),
m_iUseMagicDevice(0)
{
	/***/
}
//-----------------------------------------------------------------------------------------
Skill :: ~Skill()
{
	/***/
}
//-----------------------------------------------------------------------------------------
