//----------------------------------------------------------------
inline void Game::addEntity(Entity2D* pkEntity)
{
	assert(pkEntity);

	m_apkEntities.push_back(pkEntity);
}
//----------------------------------------------------------------
inline Importer* Game::getImporter ()
{
	return m_pkImporter;
}
//----------------------------------------------------------------