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
inline std::string Texture::getFilename ()
{
	return m_kFilename;
}
//----------------------------------------------------------------