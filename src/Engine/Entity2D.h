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
public:
//----------------------------------------------------------------
// constructor y destructor
	Entity2D ();
	virtual ~Entity2D () { /***/ }
//----------------------------------------------------------------
// seteo y devuelvo el nombre
	void setName (std::string kName);
	const std::string& getName () const;
//----------------------------------------------------------------
// seteo y devuelvo posicion, rotacion y dimension
	void setPos (float fX, float fY);
	float getPosX () const;
	float getPosY () const;
	void setRotation (float fRotation);
	float getRotation () const;
	void setDim (float fW, float fH);
//----------------------------------------------------------------
// interface
	virtual void draw (Renderer * rkRenderer);
//----------------------------------------------------------------
private:
//----------------------------------------------------------------
// nombre
	std::string m_kName;
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