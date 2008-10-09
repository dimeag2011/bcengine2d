//-----------------------------------------------------------------------------------------
#include "actor.h"
//-----------------------------------------------------------------------------------------
Actor::Actor()
:
m_iType(TYPE_NPC),
m_sDescript("Un guerrero del mal"),
m_sName("G1") 
{
	m_kActAtt = new Attribute();
	m_kActSki = new Skill();
	
	//Crea con clase default
	m_kClass.sNomClass = "Comun";
	m_kClass.iClase = 99;
	m_kClass.iCa = 10;
	m_kClass.iAtk = 2;
	m_kClass.iMana = 0;
	m_kClass.iVida = 60;

	//seteo los stasts basicos  por clase del Actor
	m_kActAtt->setCa(m_kClass.iCa);
	m_kActAtt->setMana(m_kClass.iMana);
	m_kActAtt->setHps(m_kClass.iVida);

	//Seteo los atributos base del actor todos a 10 que es lo base
	m_kActAtt->setStr(10);
	m_kActAtt->setDex(10);
	m_kActAtt->setCon(10);
	m_kActAtt->setInt(10);
	m_kActAtt->setWis(10);
	m_kActAtt->setCha(10);
	
	//Seteo salvaciones base
	m_kActAtt->setSref(m_kActAtt->getDex()/2);
	m_kActAtt->setSstr(m_kActAtt->getStr()/2);
	m_kActAtt->setSwill(m_kActAtt->getWis()/2);
}
//-----------------------------------------------------------------------------------------
Actor::Actor( const string rkName , int iType, Clase kClase)
:
m_iType(iType),
m_kClass(kClase),
m_sDescript("Un guerrero del mal"),
m_sName(rkName)
{
	//Seteo los stasts basicos  por clase del Actor
	m_kActAtt->setCa(m_kClass.iCa);
	m_kActAtt->setMana(m_kClass.iMana);
	m_kActAtt->setHps(m_kClass.iVida);

	//Seteo salvaciones base
	m_kActAtt->setSref(m_kActAtt->getDex()/2);
	m_kActAtt->setSstr(m_kActAtt->getStr()/2);
	m_kActAtt->setSwill(m_kActAtt->getWis()/2);

}
//-----------------------------------------------------------------------------------------
Actor::~Actor()
{
	delete m_kActAtt;
	m_kActAtt = NULL;

	delete m_kActSki;
	m_kActSki = NULL;
	
}
//-----------------------------------------------------------------------------------------
void Actor::setDescripcion(const string &rkDesc)
{
	m_sDescript = rkDesc;
}
//-----------------------------------------------------------------------------------------
string Actor::getDescripcion() const
{
	return m_sDescript;
} 
//-----------------------------------------------------------------------------------------
void Actor::setClassHero(int iClase)// Por si quiero setear una nueva clase al actor
{
	switch(iClase){
		case TYPE_WARRIOR:	
				m_kClass.sNomClass = "Guerrero";
				m_kClass.iClase = iClase;
				m_kClass.iCa = 15;
				m_kClass.iAtk = 6;
				m_kClass.iMana = 0;
				m_kClass.iVida = 160;
				break;

		case TYPE_MAGE:
				m_kClass.sNomClass = "Mago";
				m_kClass.iClase = iClase;
				m_kClass.iCa = 10;
				m_kClass.iAtk = 0;
				m_kClass.iMana = 150;
				m_kClass.iVida = 60;
				break;
		
		case TYPE_ROUGE:
				m_kClass.sNomClass = "Ladron";
				m_kClass.iClase = iClase;
				m_kClass.iCa = 12;
				m_kClass.iAtk = 2;
				m_kClass.iMana = 20;
				m_kClass.iVida = 100;
				break;
		
		case TYPE_CLERIC:
				m_kClass.sNomClass = "Clerigo";
				m_kClass.iClase = iClase;
				m_kClass.iCa = 13;
				m_kClass.iAtk = 3;
				m_kClass.iMana = 60;
				m_kClass.iVida = 120;
				break;
	
		default:
				m_kClass.sNomClass = "Comun";
				m_kClass.iClase = 99;
				m_kClass.iCa = 10;
				m_kClass.iAtk = 2;
				m_kClass.iMana = 0;
				m_kClass.iVida = 60;
	}// End Switch 
}
//-----------------------------------------------------------------------------------------
Clase Actor::getClassHero()
{
	return m_kClass;
}
//-----------------------------------------------------------------------------------------
void Actor::setItemEffect(Item *kItem)
{

}
//-----------------------------------------------------------------------------------------
void Actor::removeEffect()
{

}
//-----------------------------------------------------------------------------------------
void Actor::setAttributes(int iResAcd,int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
				       int iDex,  int iCon, int iInt,int iWis, int iCha)
{
	//Atributos basicos
	m_kActAtt->setResAcd(iResAcd);
	m_kActAtt->setResFir(iResFir);
	m_kActAtt->setResSon(iResSon);
	m_kActAtt->setResElec(iResElec);
	m_kActAtt->setStr(iStr);
	m_kActAtt->setDex(iDex);
	m_kActAtt->setCon(iCon);
	m_kActAtt->setInt(iInt);
	m_kActAtt->setWis(iWis);
	m_kActAtt->setCha(iCha);
	
	//Seteo salvaciones base
	m_kActAtt->setSref(m_kActAtt->getDex()/2);
	m_kActAtt->setSstr(m_kActAtt->getStr()/2);
	m_kActAtt->setSwill(m_kActAtt->getWis()/2);
}
//-----------------------------------------------------------------------------------------