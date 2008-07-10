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
protected:
	Shape ();
public:
	virtual ~Shape () { /***/ }


// inherited from Entity2D
public:
	void draw (Renderer * rkRenderer);
	void update (float fTimeBetweenFrames);
	void getColor (int &iRed, int &iGreen, int &iBlue) const;
	void setColor (int iRed, int iGreen, int iBlue);
	bool getVertexColor (int iVertex, int &iRed, int &iGreen, int &iBlue);
	bool setVertexColor (int iVertex, int iRed, int iGreen, int iBlue);
	void onCollision (Entity2D* pkEntity);


// topology
protected:
	ColorVertex* m_pkVertices;
	int m_iCantVertices;
};
//----------------------------------------------------------------
#endif //SHAPE_H
//----------------------------------------------------------------
