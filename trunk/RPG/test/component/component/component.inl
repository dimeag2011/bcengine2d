//-----------------------------------------------------------------------------------------
inline void Component::setName(const string &rkName)
{
	m_kName = rkName;
}
//-----------------------------------------------------------------------------------------
inline string Component::getName() const
{
	return m_kName;
}
//-----------------------------------------------------------------------------------------
inline void Component::setType(const string &rkType)
{
	m_kType = rkType;
}
//-----------------------------------------------------------------------------------------
inline string Component::getType() const
{
	return m_kType;
}
//-----------------------------------------------------------------------------------------
inline Component* Component::getCurrentChild()
{
	if (m_itCurrentChild != m_kChilds.end())
	{
		return *m_itCurrentChild;
	}
	else
	{
		return NULL;
	}
}
//-----------------------------------------------------------------------------------------
inline bool Component::goFirstChild()
{
	if (!m_kChilds.empty())
	{
		m_itCurrentChild = m_kChilds.begin();
		return true;
	}
	else
	{
		return false;
	}
}
//-----------------------------------------------------------------------------------------
inline bool Component::goNextChild()
{
	if (m_itCurrentChild != m_kChilds.end() && !m_kChilds.empty())
	{
		m_itCurrentChild++;
		return true;
	}
	else
	{
		return false;
	}
}
//-----------------------------------------------------------------------------------------
inline bool Component::goPrevChild()
{
	if (m_itCurrentChild != m_kChilds.begin() && !m_kChilds.empty())
	{
		m_itCurrentChild--;
		return false;
	}
	else
	{
		return false;
	}
}
//-----------------------------------------------------------------------------------------
inline int Component::getNumChilds()
{
	return (int)m_kChilds.size();
}
//-----------------------------------------------------------------------------------------
inline Component* Component::getParent()
{
	if (m_pkParent)
	{
		return m_pkParent;
	}
	else
	{
		return NULL;
	}
}
//-----------------------------------------------------------------------------------------
