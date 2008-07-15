//----------------------------------------------------------------
inline void Scene::setName (string kName)
{
	if (kName != "")
		m_kName = kName;
}
//----------------------------------------------------------------
inline const string& Scene::getName () const
{
	return m_kName;
}
//----------------------------------------------------------------