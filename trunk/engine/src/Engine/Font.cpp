//----------------------------------------------------------------
#include "includes\Font.h"
//----------------------------------------------------------------
Font::Font(Renderer* pkRenderer, Scene* pkScene)
:
m_pkRenderer(pkRenderer),
m_pkScene(pkScene),
m_fPosX(66),
m_fPosY(66),
m_fPosZ(0),
m_pkChars(NULL),
m_kText("")
{

}
//----------------------------------------------------------------
Font::~Font()
{

}
//----------------------------------------------------------------
bool Font::loadFont(string kFontFile)
{
	if (kFontFile == "")
		return false;

	m_pcCharsData.clear();

	//abro el archivo del mapa
	XMLNode kMainNode = XMLNode::openFileHelper(kFontFile.c_str(),"font");

	XMLNode kTextureNode = kMainNode.getChildNode("pages");
	kTextureNode = kTextureNode.getChildNode("page", 0);
	string kTexture = kTextureNode.getAttribute("file");
	// create the new texture
	string kPath = kFontFile.substr(0,kFontFile.find_last_of("/") + 1);
	m_pkTexture = Texture::Ptr( new Texture((kPath.append(kTexture)), 0, 0, 0) );
	m_pkRenderer->loadTexture((kPath.append(kTexture)).c_str(), m_pkTexture);


	XMLNode kCharsNode = kMainNode.getChildNode("chars");
	int iTotalChars = kCharsNode.nChildNode("char");
	int iIterator = 0;
	for(int i=0; i<iTotalChars; i++)
	{
		XMLNode kCharNode = kCharsNode.getChildNode("char",&iIterator);

		const char* pszCharId = kCharNode.getAttribute("id");
		const char* pszCharX = kCharNode.getAttribute("x");
		const char* pszCharY = kCharNode.getAttribute("y");
		const char* pszCharHeight = kCharNode.getAttribute("height");
		const char* pszCharWidth = kCharNode.getAttribute("width");

		CharData aux;
		aux.fX = atof(pszCharX);
		aux.fY = atof(pszCharY);
		aux.fHeight = atof(pszCharHeight);
		aux.fWidth = atof(pszCharWidth);
		
		char cId = atoi(pszCharId);
		m_pcCharsData.insert(pair<char, CharData>(cId, aux));
	}

}
//----------------------------------------------------------------
void Font::setText(string kText)
{
	delete[] m_pkChars;
	m_pkChars = NULL;
	if (kText.length() != 0)
	{
		m_pkChars = new Sprite[kText.length()];
		for (int i=0; i < kText.length(); i++)
		{
			CharsDataIt itChar = m_pcCharsData.find(kText.at(i));
			if (itChar != m_pcCharsData.end())
			{
				char cChar = itChar->first;
				CharData kCharData = itChar->second;
				m_pkChars[i].setTexture(m_pkTexture);
				m_pkChars[i].setTextureArea(kCharData.fX, kCharData.fY,
											kCharData.fWidth, kCharData.fHeight);
				m_pkScene->addEntity(&m_pkChars[i]);
			}
		}
	}

}
//----------------------------------------------------------------
void Font::setPos(float fPosX, float fPosY, float fPosZ)
{

}
//----------------------------------------------------------------