//-----------------------------------------------------------------------------------------
#ifndef COMPONENT_H
#define COMPONENT_H
//-----------------------------------------------------------------------------------------
#include <string>
#include <list>

//-----------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------
class Component
{
//-----------------------------------------------------------------------------------------
public:	
//-----------------------------------------------------------------------------------------
	Component();
	Component(const string &rkName,const string &rkType);
	~Component();
//-----------------------------------------------------------------------------------------
	void setName(const string &rkName);
	string getName() const;
	void setType(const string &rkType);
	string getType() const;
//-----------------------------------------------------------------------------------------
	bool setNewParent(Component* pkNewParent);
	bool addNewChild(Component* pkNewChild);
	bool notifyNewChild(Component* pkNewChild);
	bool notifyNewParent(Component* pkNewParent);
	bool removeParent();
	bool notifyChildRemoved(Component* pkExChild);
	bool removeCurrentChild();
	bool removeChild(Component* pkChild);
	bool notifyParentRemoved(Component* pkExParent);
	virtual void OnChildAdded(Component* pkNewChild);
	virtual void OnNewParentSet(Component* pkNewParent);
	virtual void OnChildRemoved(Component* pkExChild);
	virtual void OnParentRemoved(Component* pkExParent);
	Component* getCurrentChild();
	bool goFirstChild();
	bool goNextChild();
	bool goPrevChild();
//-----------------------------------------------------------------------------------------
	Component* findChild(Component* pkChild);
//-----------------------------------------------------------------------------------------
	Component* getParent();
//-----------------------------------------------------------------------------------------
	int getNumChilds();
//-----------------------------------------------------------------------------------------
private:
//-----------------------------------------------------------------------------------------
	typedef list<Component*> ChildList;
	typedef list<Component*>::iterator ChildListIterator;
	ChildList m_kChilds;
	ChildListIterator m_itCurrentChild;
//-----------------------------------------------------------------------------------------
	Component* m_pkParent;
//-----------------------------------------------------------------------------------------
	string m_kName;
	string m_kType;
//-----------------------------------------------------------------------------------------
};
//-----------------------------------------------------------------------------------------
#include "component.inl"
//-----------------------------------------------------------------------------------------
#endif //COMPONENT_H
//-----------------------------------------------------------------------------------------
