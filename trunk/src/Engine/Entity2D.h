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
	void setPos (float fX, float fY);
	float getPosX () const;
	float getPosY () const;
	void setRotation (float fRotation);
	float getRotation () const;
	void setDim (float fW, float fH);
	float getDimW ();
	float getDimH ();
//----------------------------------------------------------------
// interface
	virtual void draw (Renderer * rkRenderer);
//----------------------------------------------------------------
// functions to override
public:
	virtual void update (float fTimeBetweenFrames) = 0;

private:
//----------------------------------------------------------------
// nombre
	string m_kName;
//----------------------------------------------------------------
// posicion, rotacion y dimension
	float m_fX, m_fY;
	float m_fW, m_fH;
	float m_fRotation;
};
//----------------------------------------------------------------
#include "Entity2D.inl"
//----------------------------------------------------------------
#endif //ENTITY2D_H