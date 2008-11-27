#include "CheckCollisionObj.h"
#include "math.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
CheckCollisionObj::CollisionResult CheckCollisionObj::checkCollision(CollisionObject *_CollObj,CollisionObject *_CollObj2){

	
	//TODO: -- Ver la manera de tener X e Y en los CollisionObject para poder 
	// Realizar el chekeo de colisiones.



	float fAuxPosX = fabs(_CollObj->GetPosX() - _CollObj2->GetPosX());
	float fAuxPosY = fabs(_CollObj->GetPosY() - _CollObj2->GetPosY());

	float fAuxW = _CollObj2->GetDimW() / 2.0f + _CollObj->GetDimW() / 2.0f;
	float fAuxH = _CollObj2->GetDimH() / 2.0f + _CollObj->GetDimH() / 2.0f;

	if(fAuxPosX <= fAuxW && fAuxPosY <= fAuxH)
	{
		if(fAuxPosX + fAuxW < fAuxPosY + fAuxH)
			return Horizontal;
		else
			return Vertical;
	}
	return None; 
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------