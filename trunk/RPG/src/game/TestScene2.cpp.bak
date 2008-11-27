//----------------------------------------------------------------
#include "TestScene2.h"
//----------------------------------------------------------------
TestScene2::TestScene2 (Actor *m_pkChar)
:
m_pkFstg(NULL),
m_pkFdex(NULL),
m_pkFcon(NULL),
m_pkFint(NULL),
m_pkFcha(NULL),
m_pkFwis(NULL),
m_pkFsstr(NULL),
m_pkFsref(NULL),
m_pkFswis(NULL),
m_pkFca(NULL),
m_pkFmana(NULL),
m_pkFhps(NULL),
m_pkFatk(NULL)
{
	m_kPersonaje = *m_pkChar;
}
//----------------------------------------------------------------
TestScene2::~TestScene2 ()
{
	/***/
}
//----------------------------------------------------------------
bool TestScene2::onInit (Importer* pkImporter, Renderer* pkRenderer)
{
	m_pkFstg = new Font(pkRenderer, this);
	m_pkFstg->loadFont("../../res/font/font2.fnt");
	m_pkFstg->setText("Fuerza: %d\n", m_kPersonaje.m_kAuxActAtt.getStr());
	m_pkFstg->setPos(-400,300);
	
	m_pkFdex = new Font(pkRenderer, this);
	m_pkFdex->loadFont("../../res/font/font2.fnt");
	m_pkFdex->setText("Destreza: %d\n", m_kPersonaje.m_kAuxActAtt.getDex());
	m_pkFdex->setPos(-400,280);

	m_pkFcon = new Font(pkRenderer, this);
	m_pkFcon->loadFont("../../res/font/font2.fnt");
	m_pkFcon->setText("Comstitucion: %d\n", m_kPersonaje.m_kAuxActAtt.getCon());
	m_pkFcon->setPos(-400,260);

	m_pkFint = new Font(pkRenderer, this);
	m_pkFint->loadFont("../../res/font/font2.fnt");
	m_pkFint->setText("Inteligencia: %d\n", m_kPersonaje.m_kAuxActAtt.getInt());
	m_pkFint->setPos(-400,240);

	m_pkFcha = new Font(pkRenderer, this);
	m_pkFcha->loadFont("../../res/font/font2.fnt");
	m_pkFcha->setText("Carisma: %d\n", m_kPersonaje.m_kAuxActAtt.getCha());
	m_pkFcha->setPos(-400,220);

	m_pkFwis = new Font(pkRenderer, this);
	m_pkFwis->loadFont("../../res/font/font2.fnt");
	m_pkFwis->setText("Sabiduria: %d\n", m_kPersonaje.m_kAuxActAtt.getWis());
	m_pkFwis->setPos(-400,200);

	m_pkFsstr = new Font(pkRenderer, this);
	m_pkFsstr->loadFont("../../res/font/font2.fnt");
	m_pkFsstr->setText("Salvacion Fortaleza: %d\n", m_kPersonaje.m_kAuxActAtt.getSstr());
	m_pkFsstr->setPos(-400,180);

	m_pkFsref = new Font(pkRenderer, this);
	m_pkFsref->loadFont("../../res/font/font2.fnt");
	m_pkFsref->setText("Salvacion Reflejos: %d\n", m_kPersonaje.m_kAuxActAtt.getSref());
	m_pkFsref->setPos(-400,160);

	m_pkFswis = new Font(pkRenderer, this);
	m_pkFswis->loadFont("../../res/font/font2.fnt");
	m_pkFswis->setText("Salvacion voluntad: %d\n", m_kPersonaje.m_kAuxActAtt.getWis());
	m_pkFswis->setPos(-400,140);

	m_pkFca = new Font(pkRenderer, this);
	m_pkFca->loadFont("../../res/font/font2.fnt");
	m_pkFca->setText("CA: %d\n", m_kPersonaje.m_kAuxActAtt.getCa());
	m_pkFca->setPos(-400,120);

	m_pkFmana = new Font(pkRenderer, this);
	m_pkFmana->loadFont("../../res/font/font2.fnt");
	m_pkFmana->setText("Mana: %d\n", m_kPersonaje.m_kAuxActAtt.getMana());
	m_pkFmana->setPos(-400,100);

	m_pkFhps = new Font(pkRenderer, this);
	m_pkFhps->loadFont("../../res/font/font2.fnt");
	m_pkFhps->setText("Vida: %d\n", m_kPersonaje.m_kAuxActAtt.getHps());
	m_pkFhps->setPos(-400,80);

	m_pkFatk = new Font(pkRenderer, this);
	m_pkFatk->loadFont("../../res/font/font2.fnt");
	m_pkFatk->setText("Ataque base: %d\n", m_kPersonaje.getClassHero().iAtk);
	m_pkFatk->setPos(-400,60);

	return true;
}
//----------------------------------------------------------------
bool TestScene2::onDeinit ()
{
	//delete m_kPersonaje;
	//m_kPersonaje = NULL;

	return true;
}
//----------------------------------------------------------------
void TestScene2::onDraw (Renderer* pkRenderer) const
{

}
//----------------------------------------------------------------
bool TestScene2::onUpdate (float fTimeBetweenFrames)
{
	return true;
}
//----------------------------------------------------------------
