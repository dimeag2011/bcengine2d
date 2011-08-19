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
// seteo y devuelvo si es visible la entidad y su BB
public:
	void setVisible (bool bVisible);
	bool getVisible ();
	void setVisibleBB (bool bVisibleBB);
	bool getVisibleBB ();
//----------------------------------------------------------------
// seteo y devuelvo posicion, rotacion, flipeo y dimension
	void setPos (float fX, float fY, float fZ = 1.0f);
	float getPosX () const;
	float getPosY () const;
	float getPosZ () const;
	void setBBPos (float fBBX, float fBBY);
	float getBBPosX () const;
	float getBBPosY () const;
	void setRotation (float fRotation);
	float getRotation () const;
	void setHFlip(bool bHFlip);
	bool getHFlip();
	void setVFlip(bool bVFlip);
	bool getVFlip();
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
	float getPrevPosZ () const;
	// movement

private:
	float m_fPrevX, m_fPrevY, m_fPrevZ;
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
	const string& getCollisionGroup () const;
	void setCollisionGroup (string kColGroup);

private:
	ColorVertex m_akAABBVertices[5];
	string m_kColGroup;
	bool m_bVisibleBB;
//----------------------------------------------------------------
// interface
public:
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
// posicion, rotacion, flipeo y dimension
	float m_fX, m_fY, m_fZ;
	float m_fW, m_fH;
	float m_fBBX, m_fBBY;
	float m_fBBW, m_fBBH;
	float m_fRotation;
	bool m_bHFlip, m_bVFlip;
	bool m_bAtachedBB;
	bool m_bVisible;
};
//----------------------------------------------------------------
#include "Entity2D.inl"
//----------------------------------------------------------------
#endif //ENTITY2D_H