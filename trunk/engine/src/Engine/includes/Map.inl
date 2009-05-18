//----------------------------------------------------------------
inline float Map::getPosX()
{
	return m_fPosX;
}
//----------------------------------------------------------------
inline float Map::getPosY()
{
	return m_fPosY;
}
//----------------------------------------------------------------
inline float Map::getPosZ()
{
	return m_fPosZ;
}
//----------------------------------------------------------------
inline void Map::setPos(float fX, float fY, float fZ)
{
	m_fPosX = fX;
	m_fPosY = fY;
	m_fPosZ = fZ;

	moveMap();
}
//----------------------------------------------------------------
inline int Map::getTileWidth()
{
	return m_iTileWidth;
}
//----------------------------------------------------------------
inline int Map::getTileHeight()
{
	return m_iTileHeight;
}
//----------------------------------------------------------------
inline int Map::getNumCols()
{
	return m_iCols;
}
//----------------------------------------------------------------
inline int Map::getNumRows()
{
	return m_iRows;
}
//----------------------------------------------------------------
inline int Map::getNumLayers()
{
	return m_iLayers;
}
//----------------------------------------------------------------

