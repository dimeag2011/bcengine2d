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
	enum SHAPE_TYPE
	{
		TRIANGLE,
		BOX,
		CIRCLE
	};

	Shape (SHAPE_TYPE eShapeType);
	~Shape () { /***/ }


// inherited from Entity2D
public:
	void draw (Renderer * rkRenderer);

// topology
private:
	SHAPE_TYPE m_eShapeType;
	ColorVertex * m_pkVertices;
	int m_iNumCaras;
	float m_fRadio;
};
//----------------------------------------------------------------
#endif //SHAPE_H
//----------------------------------------------------------------