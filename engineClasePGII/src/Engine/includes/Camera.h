//----------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H
//----------------------------------------------------------------
#include "Defines.h"
//#include "D3DX9.h"
//#include "D3DTypesAndFuncs.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Camera
{
//----------------------------------------------------------------
public:
	Camera(Renderer* pkRenderer);
	~Camera();
protected:
	Renderer* m_pkRenderer;
	//Stores the position and three vectors
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_LookAt;
	D3DXVECTOR3 m_Right;
	D3DXVECTOR3 m_Up;
	//Stores whether the camera has changed since last update.
	//By change, we mean whether the camera has moved
	//or rotated. If so, we’ll recompute the matrix.
	bool m_bChanged;
	//Stores the rotation to apply to a given axis
	float m_RotateAroundUp;
	float m_RotateAroundRight;
	float m_RotateAroundLookAt;
	//Final view transformation matrix
	D3DXMATRIX m_MatView;
public:
	void SetPosition(float fX, float fY, float fZ);
	void MoveForward(float Dist);
	void MoveRight(float Dist);
	void MoveUp(float Dist);
	void MoveInDirection(float Dist, float fDirectionX, float fDirectionY, float fDirectionZ);
	void RotateDown(float Angle);
	void RotateRight(float Angle);
	void Roll(float Angle);
protected:
	//Called each frame to update the total view matrix
	void Update();

//----------------------------------------------------------------
friend class Game;
//----------------------------------------------------------------
};
//----------------------------------------------------------------
#endif //CAMERA_H
//----------------------------------------------------------------
