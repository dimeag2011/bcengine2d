//----------------------------------------------------------------
#ifndef CIRCLE_H
#define CIRCLE_H
//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Circle : public Shape
{
// constructor / destructor
public:

	Circle (int iNumCaras);
	~Circle () { /***/ }


// inherited from Shape
public:
	void draw (Renderer * rkRenderer);

// topology
private:
	int m_iNumCaras; //MAXIMO PERMITIDO 145!!!
};
//----------------------------------------------------------------
#endif //CIRCLE_H
//----------------------------------------------------------------