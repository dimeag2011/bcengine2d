//----------------------------------------------------------------
#include "includes\Texture.h"
//----------------------------------------------------------------
Texture::Texture (string kFilename, int iRed, int iGreen, int iBlue)
:
m_uiWidth(0),
m_uiHeight(0),
m_kFilename(kFilename),
m_kColorKey(iRed, iGreen, iBlue)
{

}
//----------------------------------------------------------------
Texture::~Texture ()
{

}
//----------------------------------------------------------------