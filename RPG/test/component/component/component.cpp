//-----------------------------------------------------------------------------------------
#include "component.h"
//-----------------------------------------------------------------------------------------
Component::Component()
:
m_pkParent(NULL),
m_kName(""),
m_kType(""),
m_itCurrentChild(m_kChilds.end())
{

}
//-----------------------------------------------------------------------------------------
Component::Component(const string &rkName,const string &rkType)
:
m_pkParent(NULL),
m_kName(rkName),
m_kType(rkType),
m_itCurrentChild(m_kChilds.end())
{

}
//-----------------------------------------------------------------------------------------
Component::~Component()
{

}
//-----------------------------------------------------------------------------------------
bool Component::setNewParent(Component* pkNewParent)
{
	Component* pkOldParent = m_pkParent;

	pkOldParent->notifyChildRemoved(this);

	m_pkParent = pkNewParent;

	if (!m_pkParent->notifyNewChild(this))
	{
		m_pkParent = pkOldParent;
		return false;
	}

	m_pkParent->OnChildAdded(this);
	OnNewParentSet(m_pkParent);

	return true;
}
//-----------------------------------------------------------------------------------------
bool Component::addNewChild(Component* pkNewChild)
{
	ChildListIterator itAux = m_kChilds.begin();

	if (m_kChilds.empty())
	{
		pkNewChild->notifyNewParent(this);

		m_kChilds.push_back(pkNewChild);

		OnChildAdded(pkNewChild);
		pkNewChild->OnNewParentSet(this);
		return true;
	}

	while(itAux != m_kChilds.end() && (*itAux) != pkNewChild )
	{
		itAux++;
	}
	if (itAux != m_kChilds.end())
	{
		return false;
	}
	else
	{
		pkNewChild->notifyNewParent(this);

		m_kChilds.push_back(pkNewChild);

		OnChildAdded(pkNewChild);
		pkNewChild->OnNewParentSet(this);
		return true;
	}
}
//-----------------------------------------------------------------------------------------
bool Component::notifyNewChild(Component* pkNewChild)
{
	ChildListIterator itAux = m_kChilds.begin();

	if (m_kChilds.empty())
	{
		m_kChilds.push_back(pkNewChild);
		return true;
	}

	while(itAux != m_kChilds.end() && (*itAux) != pkNewChild )
	{
		itAux++;
	}
	if (itAux != m_kChilds.end())
	{
		return false;
	}
	else
	{
		m_kChilds.push_back(pkNewChild);
		return true;
	}
}
//-----------------------------------------------------------------------------------------
bool Component::notifyNewParent(Component* pkNewParent)
{
	if (m_pkParent)
	{
		m_pkParent->notifyChildRemoved(this);
	}
	m_pkParent = pkNewParent;

	return true;
}
//-----------------------------------------------------------------------------------------
bool Component::removeParent()
{
	m_pkParent->notifyChildRemoved(this);
	m_pkParent->OnChildRemoved(this);
	OnParentRemoved(m_pkParent);
	m_pkParent = NULL;
	return true;
}
//-----------------------------------------------------------------------------------------
bool Component::notifyChildRemoved(Component* pkExChild)
{
	ChildListIterator itAux = m_kChilds.begin();
	while(itAux != m_kChilds.end() && (*itAux) != pkExChild)
	{
		itAux++;
	}
	if (itAux == m_kChilds.end())
	{
		return false;
	}
	else
	{
		m_kChilds.erase(itAux);
		return true;
	}
}
//-----------------------------------------------------------------------------------------
bool Component::removeCurrentChild()
{
	(*m_itCurrentChild)->notifyParentRemoved(this);
	m_kChilds.erase(m_itCurrentChild);
	OnChildRemoved(*m_itCurrentChild);
	(*m_itCurrentChild)->OnParentRemoved(this);
	return true;
}
//-----------------------------------------------------------------------------------------
bool Component::removeChild(Component* pkChild)
{
	ChildListIterator itAux = m_kChilds.begin();
	while(itAux != m_kChilds.end() && (*itAux) != pkChild)
	{
		itAux++;
	}
	if (itAux == m_kChilds.end())
	{
		return false;
	}
	else
	{
		(*itAux)->notifyParentRemoved(this);
		OnChildRemoved(*itAux);
		(*itAux)->OnParentRemoved(this);
		m_kChilds.erase(itAux);
		return true;
	}
}
//-----------------------------------------------------------------------------------------
bool Component::notifyParentRemoved(Component* pkExParent)
{
	m_pkParent = NULL;
	return true;
}
//-----------------------------------------------------------------------------------------
void Component::OnChildAdded(Component* pkNewChild)
{

}
//-----------------------------------------------------------------------------------------
void Component::OnNewParentSet(Component* pkNewParent)
{

}
//-----------------------------------------------------------------------------------------
void Component::OnChildRemoved(Component* pkExChild)
{

}
//-----------------------------------------------------------------------------------------
void Component::OnParentRemoved(Component* pkExParent)
{

}
//-----------------------------------------------------------------------------------------
