//----------------------------------------------------------------
#include "Entity2D.h"
#include "Renderer.h"
//----------------------------------------------------------------
Entity2D::Entity2D ()
:
m_kName(""),
m_fX(0), 
m_fY(0), 
m_fW(0),
m_fH(0),
m_fRotation(0)
{
	/***/
}
//----------------------------------------------------------------
void Entity2D::draw (Renderer * rkRenderer)
{
	// set the world matrix
	rkRenderer->setMatrixMode(WORLD);

	// reset the matrix
	rkRenderer->loadIdentity();

	// apply transformation
	rkRenderer->translate(m_fX, m_fY);
	rkRenderer->rotateZ(m_fRotation * 3.14159f / 180.0f);
}
//----------------------------------------------------------------