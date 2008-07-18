//----------------------------------------------------------------
inline unsigned int Texture::getWidth ()
{
	return m_uiWidth;
}
//----------------------------------------------------------------
inline unsigned int Texture::getHeight ()
{
	return m_uiHeight;
}
//----------------------------------------------------------------
inline void Texture::setWidth (unsigned int uiWidth)
{
	m_uiWidth = uiWidth;
}
//----------------------------------------------------------------
inline void Texture::setHeight (unsigned int uiHeight)
{
	m_uiHeight = uiHeight;
}
//----------------------------------------------------------------
inline string Texture::getFilename ()
{
	return m_kFilename;
}
//----------------------------------------------------------------
inline void Texture::getColorKey (int &iRed, int &iGreen, int &iBlue)
{
	iRed = m_kColorKey.iRed;
	iGreen = m_kColorKey.iGreen;
	iBlue = m_kColorKey.iBlue;
}
//----------------------------------------------------------------
