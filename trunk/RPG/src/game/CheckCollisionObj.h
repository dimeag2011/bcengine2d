#pragma once

//---------------------------------------------------------------------------
#include "CollisionObject.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class CheckCollisionObj{
	
	
	enum CollisionResult
	{
		None,
		Vertical,
		Horizontal
	};

	CollisionResult checkCollision(CollisionObject* _CollObj);
	
	
};
//---------------------------------------------------------------------------
