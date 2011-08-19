//----------------------------------------------------------------
#include "includes\Font.h"
//----------------------------------------------------------------
Font::Font(Renderer* pkRenderer, Scene* pkScene)
:
m_pkRenderer(pkRenderer),
m_pkScene(pkScene),
m_fPosX(0),
m_fPosY(0),
m_fPosZ(0),
m_iLength(0),
m_kText("")
{

}
//----------------------------------------------------------------
Font::~Font()
{
	if (!(m_pkChars.empty()))
	{
		for (int i = 0; i < m_iLength; i++)
		{
			if (&(m_pkChars[i]))
				m_pkScene->removeEntity(&(m_pkChars[i]));
		}
		m_pkChars.clear();
		m_iLength = 0;
	}
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
		const char* pszCharXOffset = kCharNode.getAttribute("xoffset");
		const char* pszCharYOffset = kCharNode.getAttribute("yoffset");
		const char* pszCharXAdvance = kCharNode.getAttribute("xadvance");

		CharData aux;
		aux.cId = atoi(pszCharId);
		aux.iX = atoi(pszCharX);
		aux.iY = atoi(pszCharY);
		aux.iHeight = atoi(pszCharHeight);
		aux.iWidth = atoi(pszCharWidth);
		aux.iXOffset = atoi(pszCharXOffset);
		aux.iYOffset = atoi(pszCharYOffset);
		aux.iXAdvance = atoi(pszCharXAdvance);
		
		char cId = atoi(pszCharId);
		m_pcCharsData.insert(pair<char, CharData>(cId, aux));
	}

	return true;

}
//----------------------------------------------------------------
void Font::setText(char * psz_Texto, ...)
{
	static char psz_Text[256];

	va_list argptr; 
		va_start(argptr, psz_Texto); 
		vsprintf(psz_Text, psz_Texto, argptr);
	va_end(argptr);

	m_kText.clear();
	m_kText = psz_Text;
	if (m_kText.length() > m_iLength)
	{
		if (!(m_pkChars.empty()))
		{
			for (int i = 0; i < m_iLength; i++)
			{
				if (&(m_pkChars[i]))
					m_pkScene->removeEntity(&(m_pkChars[i]));
			}
			m_pkChars.empty();
			m_iLength = 0;
		}
		m_pkChars.resize(m_kText.length(), Character());
	}
	else
	{
		while (m_pkChars.size() > m_kText.length())
		{
			m_pkScene->removeEntity(&m_pkChars.back());
			m_pkChars.resize((m_pkChars.size() - 1));
		}
	}

	m_iLength = 0;
	for (int i=0; i < m_kText.length(); i++)
	{
		CharsDataIt itChar = m_pcCharsData.find(m_kText.at(i));
		if (itChar != m_pcCharsData.end())
		{
			char cChar = itChar->first;
			CharData kCharData = itChar->second;

			m_pkChars[i].setTexture(m_pkTexture);
			m_pkChars[i].setTextureArea(kCharData.iX, kCharData.iY,
										kCharData.iWidth, kCharData.iHeight);
			m_pkChars[i].setDim(kCharData.iWidth, kCharData.iHeight, false);
			m_pkChars[i].setCharData(kCharData);

			m_pkScene->addEntity(&m_pkChars[i]);
			m_iLength++;
		}
	}

	setPos(m_fPosX, m_fPosY, m_fPosZ);

}
//----------------------------------------------------------------
void Font::setPos(float fPosX, float fPosY, float fPosZ)
{
	m_fPosX = fPosX;
	m_fPosY = fPosY;
	m_fPosZ = fPosZ;

	float fTotalWidth = 0;
	for (int i = 0; i < m_iLength; i++)
	{
		fTotalWidth += m_pkChars[i].getCharData().iXAdvance;
		fTotalWidth += m_pkChars[i].getCharData().iXOffset;
	}

	m_pkChars[0].setPos(m_fPosX - fTotalWidth / 2 + m_pkChars[0].getCharData().iXAdvance / 2 
							+ m_pkChars[0].getCharData().iXOffset,
							m_fPosY - m_pkChars[0].getCharData().iYOffset - m_pkChars[0].getCharData().iHeight / 2,
							m_fPosZ);

	for (int i = 1; i < m_iLength; i++)
		m_pkChars[i].setPos(m_pkChars[i-1].getPosX() + m_pkChars[i-1].getCharData().iXAdvance / 2 +
								m_pkChars[i].getCharData().iXAdvance / 2 + m_pkChars[i].getCharData().iXOffset,
								m_fPosY - m_pkChars[i].getCharData().iYOffset - m_pkChars[i].getCharData().iHeight / 2,
								m_fPosZ);
}
//----------------------------------------------------------------