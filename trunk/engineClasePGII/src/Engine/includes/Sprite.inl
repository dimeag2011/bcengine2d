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
inline AnimationInfo::Ptr Sprite::getAnimationInfo (std::string kName)
{
	return m_kAnimationMap[kName];
}
//----------------------------------------------------------------
inline Animation* Sprite::getAnimation ()
{
	return m_pkCurrentAnim;
}
//----------------------------------------------------------------
inline bool Sprite::setAnimation (std::string kName)
{
	delete m_pkCurrentAnim;
	m_pkCurrentAnim = NULL;

	AnimationInfo::Ptr pkInfo = m_kAnimationMap[kName];

	if( !pkInfo.get() )
		return false;

	m_pkCurrentAnim = new Animation(pkInfo);

	return true;
}
//----------------------------------------------------------------