//---------------------------------------------------------------------------------------
#include "CollisionMgr.h"
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
CollisionMgr::CollisionMgr(){
}
//---------------------------------------------------------------------------------------
CollisionMgr::~CollisionMgr(){
}
//---------------------------------------------------------------------------------------
void CollisionMgr::OnAddedToParent(Component *pkParent){
	/***/
	// AddListener.
	pkParent->onAddedListener("OnChildAdded",this);
}
//---------------------------------------------------------------------------------------
void CollisionMgr::onEvent(Event *event, Component* dispatcher){
	/***/
	if (dispatcher){
		ChildListIterator iter = m_kChilds.begin();
		// Mientras el iterador no llegue al final
		while (iter != m_kChilds.end()){
			// Chekeamos si el Tipo del component es un CollisionObject	
			if ((*iter)->m_iType == TYPE_COLLISIONOBJ ) {
				// Hacer
				if (((CollisionObject*)(*iter))->m_Type == COLLISIONOBJ_TYPE_VIEWRANGE){
				//	((CollisionObject*)(*iter))->setCollisionGroup("UNO");
//					Entity2D::CollisionResult eResult = (((CollisionObject*)(*iter))->checkCollision(Posion);
				}
				if (((CollisionObject*)(*iter))->m_Type == COLLISIONOBJ_TYPE_ATTKRANGE){
				//	((CollisionObject*)(*iter))->setCollisionGroup("DOS");
///				Entity2D::CollisionResult eResult = ((CollisionObject*)(*iter))->checkCollision(Posion);
				}
			}
			// Incrementamos el iterador
			iter++;
		}
	}
}
//---------------------------------------------------------------------------------------
void CollisionMgr::OnChildRemoved(Component *pkChild){
	/***/
	// Chekarlo y sacarlo de la lista de colicion
}
//---------------------------------------------------------------------------------------
void CollisionMgr::OnRemovedParent(Component *pkParent){
	/***/
	// Vaciar las listas de colicion.
}
//---------------------------------------------------------------------------------------
