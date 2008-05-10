//----------------------------------------------------------------
inline void Sprite::setTexture (Texture::Ptr pkTexture)
{
	m_pkTexture = pkTexture;
}
//----------------------------------------------------------------
inline const Texture::Ptr Sprite::getTexture ()
{
	return m_pkTexture;
}
//----------------------------------------------------------------