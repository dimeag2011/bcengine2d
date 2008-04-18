/*
//	Dani Modificaciones
#ifndef SHAPE_H
#define SHAPE_H

#include "Structs.h"

class Shape
{
public:
	Shape();
	~Shape();

	enum SHAPE_TYPE
	{
		TRIANGLE,
		BOX,
		CIRCLE
	};


};
#endif //SHAPE_H
*/
//----------------------------------------------------------------
#ifndef SHAPE_H
#define SHAPE_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Entity2D.h"
#include "Structs.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Shape : public Entity2D
{
// constructor / destructor
public:
	Shape ();
	~Shape () { /***/ }

// inherited from Entity2D
public:
	void draw (Renderer * rkRenderer);

// topology
private:
	ColorVertex m_akVertices[4];
};
//----------------------------------------------------------------
#endif //SHAPE_H
//----------------------------------------------------------------