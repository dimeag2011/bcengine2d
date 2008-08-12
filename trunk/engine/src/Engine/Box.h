//----------------------------------------------------------------
#ifndef BOX_H
#define BOX_H
//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Box : public Shape
{
// constructor / destructor
public:

	Box ();
	~Box ();


// inherited from Shape
public:
	void draw (Renderer * rkRenderer);

// topology
private:
};
//----------------------------------------------------------------
#endif //BOX_H
//----------------------------------------------------------------