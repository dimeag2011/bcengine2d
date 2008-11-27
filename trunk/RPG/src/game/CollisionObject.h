//--------------------------------------------------------------------------
#pragma once
//--------------------------------------------------------------------------
#define COLLISIONOBJ_TYPE_VIEWRANGE	0
#define COLLISIONOBJ_TYPE_ATTKRANGE	1
//--------------------------------------------------------------------------
#include "Component.h"
#include "Defines.h"
//#include "Defines.h"
//--------------------------------------------------------------------------
class CollisionObject : public Component{
//--------------------------------------------------------------------------
	CollisionObject(int type,int width,int heigth);
	~CollisionObject();

public:
	
	//int GetPosX(){ return ((WorldObject*)parent)->GetPosX(); }
	float GetPosX() {return PosX;}
	float GetPosY() {return PosY;}
	int GetDimH() { return m_width; }
	int GetDimW() { return m_heigth; }
	void SetPosX(float x) { PosX = x;}
	void SetPosY(float y) { PosY = y;}

	std::string m_sName;
	int m_CollisionGroup;
	
	int m_width;
	int m_heigth;

	int m_Type;
private:
	float PosX;
	float PosY;


//--------------------------------------------------------------------------
	
};
//--------------------------------------------------------------------------