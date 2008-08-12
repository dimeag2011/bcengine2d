//----------------------------------------------------------------
inline void Entity2D::setName (string kName)
{
	m_kName = kName;
}
//----------------------------------------------------------------
inline const string& Entity2D::getName () const
{
	return m_kName;
}
//----------------------------------------------------------------
inline void Entity2D::setPos (float fX, float fY, float fZ)
{
	m_fX = fX;
	m_fY = fY;
	m_fZ = fZ;
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
inline float Entity2D::getPosZ () const
{
	return m_fZ;
}
//----------------------------------------------------------------
inline void Entity2D::setBBPos (float fBBX, float fBBY)
{
	m_fBBX = fBBX;
	m_fBBY = fBBY;
}
//----------------------------------------------------------------
inline float Entity2D::getBBPosX () const
{
	return m_fBBX;
}
//----------------------------------------------------------------
inline float Entity2D::getBBPosY () const
{
	return m_fBBY;
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
inline void Entity2D::setDim (float fW, float fH, bool setBBDim)
{
	m_fW = fW;
	m_fH = fH;
	if (setBBDim)
	{
		m_fBBW = fW;
		m_fBBH = fH;
	}
}
//----------------------------------------------------------------
inline float Entity2D::getDimH () const
{
	return m_fH;
}
//----------------------------------------------------------------
inline float Entity2D::getDimW () const
{
	return m_fW;
}
//----------------------------------------------------------------
inline void Entity2D::setBBDim (float fBBW, float fBBH)
{
	m_fBBW = fBBW;
	m_fBBH = fBBH;
}
//----------------------------------------------------------------
inline float Entity2D::getBBDimH () const
{
	return m_fBBH;
}
//----------------------------------------------------------------
inline float Entity2D::getBBDimW () const
{
	return m_fBBW;
}
//----------------------------------------------------------------
inline void Entity2D::setMoveAngle (float fAngle)
{
	m_fMoveAngle = fAngle;
	m_fMoveAngleRad = fAngle * 3.14159f / 180.0f;
}
//----------------------------------------------------------------
inline float Entity2D::getMoveAngle () const
{
	return m_fMoveAngle;
}
//----------------------------------------------------------------
inline void Entity2D::setMoveSpeed (float fSpeed)
{
	m_fMoveSpeed = fSpeed;
}
//----------------------------------------------------------------
inline float Entity2D::getMoveSpeed () const
{
	return m_fMoveSpeed;
}
//----------------------------------------------------------------
inline void Entity2D::setMoving (bool bMoving)
{
	m_bIsMoving = bMoving;
}
//----------------------------------------------------------------
inline bool Entity2D::getMoving () const
{
	return m_bIsMoving;
}
//----------------------------------------------------------------
inline float Entity2D::getPrevPosX () const
{
	return m_fPrevX;
}
//----------------------------------------------------------------
inline float Entity2D::getPrevPosY () const
{
	return m_fPrevY;
}
//----------------------------------------------------------------
inline float Entity2D::getPrevPosZ () const
{
	return m_fPrevZ;
}
//----------------------------------------------------------------
inline const string& Entity2D::getCollisionGroup () const
{
	return m_kColGroup;
}
//----------------------------------------------------------------
inline void Entity2D::setCollisionGroup (string kColGroup)
{
	m_kColGroup = kColGroup;
}
//----------------------------------------------------------------
inline void Entity2D::setVisible (bool bVisible)
{
	m_bVisible = bVisible;	
}
//----------------------------------------------------------------
inline bool Entity2D::getVisible ()
{
	return m_bVisible;
}
//----------------------------------------------------------------
inline void Entity2D::setVisibleBB (bool bVisibleBB)
{
	m_bVisibleBB = bVisibleBB;
}
//----------------------------------------------------------------
inline bool Entity2D::getVisibleBB ()
{
	return m_bVisibleBB;
}
//----------------------------------------------------------------
inline void Entity2D::setHFlip(bool bHFlip)
{
	m_bHFlip = bHFlip;
}
//----------------------------------------------------------------
inline bool Entity2D::getHFlip()
{
	return m_bHFlip;
}
//----------------------------------------------------------------
inline void Entity2D::setVFlip(bool bVFlip)
{
	m_bVFlip = bVFlip;
}
//----------------------------------------------------------------
inline bool Entity2D::getVFlip()
{
	return m_bVFlip;
}
//----------------------------------------------------------------

