//----------------------------------------------------------------
#include "Texture.h"
//----------------------------------------------------------------
Texture::Texture (string kFilename, int iRed, int iGreen, int iBlue)
:
m_uiWidth(0),
m_uiHeight(0),
m_kFilename(kFilename)
{
	m_kColorKey.red = iRed;
	m_kColorKey.green = iGreen;
	m_kColorKey.blue = iBlue;
}
//----------------------------------------------------------------
Texture::~Texture ()
{

}
//----------------------------------------------------------------