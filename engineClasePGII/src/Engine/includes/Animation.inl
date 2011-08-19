//----------------------------------------------------------------
inline const AnimationInfo::Ptr Animation::getInfo () const
{
	return m_pkInfo;
}
//----------------------------------------------------------------
inline Animation::PlayState Animation::getState () const
{
	return m_eCurrentState;
}
//----------------------------------------------------------------
inline unsigned int Animation::getCurrentFrame () const
{
	return m_uiCurrentFrame;
}
//----------------------------------------------------------------