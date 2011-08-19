//----------------------------------------------------------------
#ifndef TRIANGLE_H
#define TRIANGLE_H
//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
class Renderer;
//----------------------------------------------------------------
class ENGINE_API Triangle : public Shape
{
// constructor / destructor
public:

	Triangle ();
	~Triangle ();


// inherited from Shape
public:
	void draw (Renderer * rkRenderer);

// topology
private:
};
//----------------------------------------------------------------
#endif //TRIANGLE_H
//----------------------------------------------------------------