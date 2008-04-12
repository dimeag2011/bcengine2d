//----------------------------------------------------------------
inline void Entity2D::setName (std::string kName)
{
	m_kName = kName;
}
//----------------------------------------------------------------
inline const std::string& Entity2D::getName () const
{
	return m_kName;
}
//----------------------------------------------------------------
inline void Entity2D::setPos (float fX, float fY)
{
	m_fX = fX;
	m_fY = fY;
}
//----------------------------------------------------------------
inline float Entity2D::getPosX () const
{
	return m_fX;
}
//----------------------------------------------------------------
inline float Entity2D::getPosY () const
{
	return m_fY;
}
//----------------------------------------------------------------
inline void Entity2D::setRotation (float fRotation)
{
	m_fRotation = fRotation;
}
//----------------------------------------------------------------
inline float Entity2D::getRotation () const
{
	return m_fRotation;
}
//----------------------------------------------------------------
inline void Entity2D::setDim (float fW, float fH)
{
	m_fW = fW;
	m_fH = fH;
}
//----------------------------------------------------------------