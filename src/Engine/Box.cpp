//----------------------------------------------------------------
#include "Box.h"
//----------------------------------------------------------------
Box::Box ()
:
Shape()
{
	ColorVertex* pkV;
	// set the vertex values
	m_pkVertices = new ColorVertex[4];
	m_iCantVertices = 4;
	// set the vertex values
	pkV = &(m_pkVertices[0]);
	pkV->x = -0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);
	
	pkV = &(m_pkVertices[1]);
	pkV->x = -0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_pkVertices[2]);
	pkV->x = 0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_pkVertices[3]);
	pkV->x = 0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);
}
//----------------------------------------------------------------
void Box::draw (Renderer * rkRenderer)
{
	Shape::draw(rkRenderer);
	rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_STRIP, m_iCantVertices);
}
//----------------------------------------------------------------