#ifndef ENTITY2D_H
#define ENTITY2D_H
//----------------------------------------------------------------
#include "Structs.h"
#include "Defines.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Entity2D
{
//----------------------------------------------------------------
// constructor y destructor
protected:
	Entity2D ();
public:
	virtual ~Entity2D () { /***/ }
//----------------------------------------------------------------
// seteo y devuelvo el nombre
	void setName (string kName);
	const string& getName () const;
//----------------------------------------------------------------
// seteo y devuelvo posicion, rotacion y dimension
	void setPos (float fX, float fY, float fZ = 1.0f);
	float getPosX () const;
	float getPosY () const;
	float getPosZ () const;
	void setBBPos (float fBBX, float fBBY);
	float getBBPosX () const;
	float getBBPosY () const;
	void setRotation (float fRotation);
	float getRotation () const;
	virtual void setDim (float fW, float fH, bool setBBDim = true);
	float getDimW () const;
	float getDimH () const;
	void setBBDim (float fBBW, float fBBH);
	float getBBDimW () const;
	float getBBDimH () const;

//----------------------------------------------------------------
// Moviemeito de la entidad
public:
	void setMoveAngle (float fAngle);
	float getMoveAngle () const;

	void setMoveSpeed (float fSpeed);
	float getMoveSpeed () const;

	void setMoving (bool bisMoving);
	bool getMoving () const;

	float getPrevPosX () const;
	float getPrevPosY () const;
	// movement

	float m_fPrevX, m_fPrevY;
	float m_fMoveAngle, m_fMoveAngleRad;
	float m_fMoveSpeed;
	bool m_bIsMoving;
//----------------------------------------------------------------
// Colisiones
public:
	
	enum CollisionResult
	{
		None,
		Vertical,
		Horizontal
	};

	CollisionResult checkCollision(Entity2D* pkEntity) const;
	virtual void onCollision (Entity2D* pkEntity) = 0;

	ColorVertex m_akAABBVertices[5];
//----------------------------------------------------------------
// interface
	virtual void draw (Renderer * rkRenderer);
//----------------------------------------------------------------
// functions to override
public:
	virtual void update (float fTimeBetweenFrames);

private:
//----------------------------------------------------------------
// nombre
	string m_kName;
//----------------------------------------------------------------
// posicion, rotacion y dimension
	float m_fX, m_fY, m_fZ;
	float m_fW, m_fH;
	float m_fBBX, m_fBBY;
	float m_fBBW, m_fBBH;
	float m_fRotation;
	bool m_bAtachedBB;
};
//----------------------------------------------------------------
#include "Entity2D.inl"
//----------------------------------------------------------------
#endif //ENTITY2D_H