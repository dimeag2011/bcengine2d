#include "ChildRemoveEvent.h"

//----------------------------------------------------------------------------
ChildRemoveEvent::ChildRemoveEvent(Component *kChild)
:
Evento(CHILD_REMOVE_Evento)
{
		this->kChild = kChild;
}
//----------------------------------------------------------------------------
const string ChildRemoveEvent::CHILD_REMOVE_Evento = "ChildRemoved";
//----------------------------------------------------------------------------