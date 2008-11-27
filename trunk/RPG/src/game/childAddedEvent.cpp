#include "ChildAddedEvent.h"


ChildAddedEvent::ChildAddedEvent(Component *kChild)
:
Evento(CHILD_ADDED_Evento)
{
		this->kChild = kChild;
}
const string ChildAddedEvent::CHILD_ADDED_Evento = "ChildAdded";