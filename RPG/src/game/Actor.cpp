//-----------------------------------------------------------------------------------------
#include "actor.h"
//-----------------------------------------------------------------------------------------
Actor::Actor()
:
m_iType(TYPE_NPC),
m_sDescript("Un guerrero del mal"),
m_sName("G1"),
m_fPosX(0),
m_fPosY(0)
//m_kAEffect()
{
	for(i=0; i< 10; i++){

		m_kAEffect[i] = NULL;
	}
	//m_kActAtt = new Attribute();
	//m_kActSki = new Skill();

	//Crea con clase default
	m_kClass.sNomClass = "Comun";
	m_kClass.iClase = 99;
	m_kClass.iCa = 10;
	m_kClass.iAtk = 2;
	m_kClass.iMana = 0;
	m_kClass.iVida = 60;

	//seteo los stasts basicos  por clase del Actor
	m_kActAtt.setCa(m_kClass.iCa);
	m_kActAtt.setMana(m_kClass.iMana);
	m_kActAtt.setHps(m_kClass.iVida);

	//Seteo los atributos base del actor todos a 10 que es lo base
	m_kActAtt.setStr(10);
	m_kActAtt.setDex(10);
	m_kActAtt.setCon(10);
	m_kActAtt.setInt(10);
	m_kActAtt.setWis(10);
	m_kActAtt.setCha(10);

	//Seteo salvaciones base
	m_kActAtt.setSref(m_kActAtt.getDex()/2);
	m_kActAtt.setSstr(m_kActAtt.getStr()/2);
	m_kActAtt.setSwill(m_kActAtt.getWis()/2);

	i=0;

	m_kInventory = new Inventario();
}
//-----------------------------------------------------------------------------------------
Actor::Actor( const string rkName , int iType, Clase kClase)
:
m_iType(iType),
m_kClass(kClase),
m_sDescript("Un guerrero del mal"),
m_sName(rkName),
m_fPosX(0),
m_fPosY(0)
//m_kAEffect()
{

	for(i=0; i< 10; i++){

		m_kAEffect[i] = NULL;
	}
	//Seteo los stasts basicos  por clase del Actor
	m_kActAtt.setCa(m_kClass.iCa);
	m_kActAtt.setMana(m_kClass.iMana);
	m_kActAtt.setHps(m_kClass.iVida);

	//Seteo los atributos base del actor todos a 10 que es lo base
	m_kActAtt.setStr(10);
	m_kActAtt.setDex(10);
	m_kActAtt.setCon(10);
	m_kActAtt.setInt(10);
	m_kActAtt.setWis(10);
	m_kActAtt.setCha(10);

	//Seteo salvaciones base
	m_kActAtt.setSref(m_kActAtt.getDex()/2);
	m_kActAtt.setSstr(m_kActAtt.getStr()/2);
	m_kActAtt.setSwill(m_kActAtt.getWis()/2);

	i=0;
	m_kInventory = new Inventario();
}
//-----------------------------------------------------------------------------------------
Actor::~Actor()
{
	/*delete m_kActAtt;
	m_kActAtt = NULL;

	delete m_kActSki;
	m_kActSki = NULL;

	delete m_kInventory;
	m_kInventory = NULL;
	*/
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
	m_kActAtt.setResAcd((m_kActAtt.getResAcd()+ kItem->m_kAttAux.getResAcd()));
	m_kActAtt.setResFir((m_kActAtt.getResFir()+ kItem->m_kAttAux.getResFir()));
	m_kActAtt.setResSon((m_kActAtt.getResSon()+ kItem->m_kAttAux.getResSon()));
	m_kActAtt.setResElec((m_kActAtt.getResElec()+ kItem->m_kAttAux.getResElec()));
	m_kActAtt.setStr((m_kActAtt.getStr()+ kItem->m_kAttAux.getStr()));
	m_kActAtt.setDex((m_kActAtt.getDex()+ kItem->m_kAttAux.getDex()));
	m_kActAtt.setCon((m_kActAtt.getCon()+ kItem->m_kAttAux.getCon()));
	m_kActAtt.setInt((m_kActAtt.getInt()+ kItem->m_kAttAux.getInt()));
	m_kActAtt.setWis((m_kActAtt.getWis()+ kItem->m_kAttAux.getWis()));
	m_kActAtt.setCha((m_kActAtt.getCha()+ kItem->m_kAttAux.getCha()));

	m_kActAtt.setSref((m_kActAtt.getSref()+ kItem->m_kAttAux.getSref()));
	m_kActAtt.setSstr((m_kActAtt.getSstr()+ kItem->m_kAttAux.getSstr()));
	m_kActAtt.setSwill((m_kActAtt.getSwill()+ kItem->m_kAttAux.getSwill()));

	m_kAuxActAtt = m_kActAtt;

	//Guardo el item en un vector de items temporales , para conservar sus efectos
	// asi despues , puedo buscar el item y lo uso para sacar los efectos.
	if((kItem->GetConsumable()) == true)
	{
		m_kAEffect[i] = kItem;
		m_kInventory->removeItem(kItem);

		i++;
	}

}
//-----------------------------------------------------------------------------------------
void Actor::removeEquipable(Item *kItem)
{
	m_kActAtt.setResAcd((m_kActAtt.getResAcd()- kItem->m_kAttAux.getResAcd()));
	m_kActAtt.setResFir((m_kActAtt.getResFir()- kItem->m_kAttAux.getResFir()));
	m_kActAtt.setResSon((m_kActAtt.getResSon()- kItem->m_kAttAux.getResSon()));
	m_kActAtt.setResElec((m_kActAtt.getResElec()- kItem->m_kAttAux.getResElec()));
	m_kActAtt.setStr((m_kActAtt.getStr()- kItem->m_kAttAux.getStr()));
	m_kActAtt.setDex((m_kActAtt.getDex()- kItem->m_kAttAux.getDex()));
	m_kActAtt.setCon((m_kActAtt.getCon()- kItem->m_kAttAux.getCon()));
	m_kActAtt.setInt((m_kActAtt.getInt()- kItem->m_kAttAux.getInt()));
	m_kActAtt.setWis((m_kActAtt.getWis()- kItem->m_kAttAux.getWis()));
	m_kActAtt.setCha((m_kActAtt.getCha()- kItem->m_kAttAux.getCha()));

	m_kActAtt.setSref((m_kActAtt.getSref()- kItem->m_kAttAux.getSref()));
	m_kActAtt.setSstr((m_kActAtt.getSstr()- kItem->m_kAttAux.getSstr()));
	m_kActAtt.setSwill((m_kActAtt.getSwill()- kItem->m_kAttAux.getSwill()));

	m_kAuxActAtt = m_kActAtt;

}
//-----------------------------------------------------------------------------------------
void Actor::removeEffect(string m_sName)
{
	//Busco el nombre del item al cual quiero sacar el efecto.
	for(i=0; i<10; i++){
		if((m_kAEffect[i]->getName().compare(m_sName))== 0)
		{
			break;
		}
}	

	m_kActAtt.setResAcd((m_kActAtt.getResAcd()- m_kAEffect[i]->m_kAttAux.getResAcd()));
	m_kActAtt.setResFir((m_kActAtt.getResFir()- m_kAEffect[i]->m_kAttAux.getResFir()));
	m_kActAtt.setResSon((m_kActAtt.getResSon()- m_kAEffect[i]->m_kAttAux.getResSon()));
	m_kActAtt.setResElec((m_kActAtt.getResElec()- m_kAEffect[i]->m_kAttAux.getResElec()));
	m_kActAtt.setStr((m_kActAtt.getStr()- m_kAEffect[i]->m_kAttAux.getStr()));
	m_kActAtt.setDex((m_kActAtt.getDex()- m_kAEffect[i]->m_kAttAux.getDex()));
	m_kActAtt.setCon((m_kActAtt.getCon()- m_kAEffect[i]->m_kAttAux.getCon()));
	m_kActAtt.setInt((m_kActAtt.getInt()- m_kAEffect[i]->m_kAttAux.getInt()));
	m_kActAtt.setWis((m_kActAtt.getWis()- m_kAEffect[i]->m_kAttAux.getWis()));
	m_kActAtt.setCha((m_kActAtt.getCha()- m_kAEffect[i]->m_kAttAux.getCha()));

	m_kActAtt.setSref((m_kActAtt.getSref()- m_kAEffect[i]->m_kAttAux.getSref()));
	m_kActAtt.setSstr((m_kActAtt.getSstr()- m_kAEffect[i]->m_kAttAux.getSstr()));
	m_kActAtt.setSwill((m_kActAtt.getSwill()- m_kAEffect[i]->m_kAttAux.getSwill()));

	m_kAuxActAtt = m_kActAtt;

	//Libero esa posicion del vector
	m_kAEffect[i] = NULL;

	//Actualizo el vector
	for(z=i; z<10 ; z++)
	{
		m_kAEffect[z]= m_kAEffect[z+1];
		m_kAEffect[z+1] = NULL;

	}
}
//-----------------------------------------------------------------------------------------
void Actor::setAttributes(int iResAcd,int iResFir, int iResFro ,int iResSon,int iResElec,int iStr, 
						  int iDex,  int iCon, int iInt,int iWis, int iCha)
{
	//Atributos basicos
	m_kActAtt.setResAcd(iResAcd);
	m_kActAtt.setResFir(iResFir);
	m_kActAtt.setResSon(iResSon);
	m_kActAtt.setResElec(iResElec);
	m_kActAtt.setStr(iStr);
	m_kActAtt.setDex(iDex);
	m_kActAtt.setCon(iCon);
	m_kActAtt.setInt(iInt);
	m_kActAtt.setWis(iWis);
	m_kActAtt.setCha(iCha);

	//Seteo salvaciones base
	m_kActAtt.setSref(m_kActAtt.getDex()/2);
	m_kActAtt.setSstr(m_kActAtt.getStr()/2);
	m_kActAtt.setSwill(m_kActAtt.getWis()/2);

	m_kAuxActAtt = m_kActAtt;
}
//-----------------------------------------------------------------------------------------
void Actor::putItemInventory(Item *kItem)
{
	//Dejo que el invetario se encargue de manejar los items
	if (!m_kInventory->isInventoryFull())
	{
		m_kInventory->addItem(kItem);
	}
	else
	{
		cout << "Inventario full papa" << endl;
	}

}
//-----------------------------------------------------------------------------------------
void Actor::removeItemInventory(Item *kItem)
{
	if (!m_kInventory->removeItem(kItem))
	{
		cout << "Se quito correctamente" <<endl;
	}

	cout << "Se a producido un error" << endl;

}
//-----------------------------------------------------------------------------------------
void Actor::useItem(int iType){

	this->setItemEffect((m_kInventory->getItem(iType)));

}
//-----------------------------------------------------------------------------------------
/*
void Actor::Draw(Renderer* pkReenderer)
{
	m_pkActorSpr->draw(pkReenderer);
}
//-----------------------------------------------------------------------------------------
bool Actor::onInit(Importer* pkImporter, float fPosX, float fPosY, string sName)
{
	
	m_pkActorSpr = new Sprite();
	if( !pkImporter->createSprite("Pacman", m_pkActorSpr) ){
		return true;
	}
	return false;

	m_pkActorSpr->setName(sName);
	m_pkActorSpr->setDim(50,50);
	m_pkActorSpr->setPos(fPosX, fPosY, 500.0f);
}
//-----------------------------------------------------------------------------------------
*/