inline void Renderer::setViewerPosition(float fPosX, float fPosY)
{
	m_kViewerPos.x = fPosX;
	m_kViewerPos.y = fPosY;
	m_kViewerPos.z = -5.0f;

	setViewportPosition();
}
//----------------------------------------------------------------
inline void Renderer::getViewerPosition(float &fPosX, float &fPosY)
{
	fPosX = m_kViewerPos.x;
	fPosY = m_kViewerPos.y;
}
//----------------------------------------------------------------
inline void Renderer::setViewerAngle(float fAngle)
{
	m_fViewerAngle = fAngle;

	float fPiOver180 = 3.141592654f / 180.0f;
	float fPiOver2 = 3.141592654f / 2.0f;
	float fAngSin = sin((fAngle + 90.0f) * fPiOver180);
	float fAngCos = cos((fAngle + 90.0f) * fPiOver180);

	m_kViewerUp.x = fAngCos;
	m_kViewerUp.y = fAngSin;
	m_kViewerUp.z = 0.0f;

	setViewportPosition();
}
//----------------------------------------------------------------
inline float Renderer::getViewerAngle()
{
	return m_fViewerAngle;
}
//----------------------------------------------------------------
