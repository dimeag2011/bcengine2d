//----------------------------------------------------------------
#include "Triangle.h"
//----------------------------------------------------------------
Triangle::Triangle ()
:
Shape()
{
	ColorVertex* pkV;
	// set the vertex values
	m_pkVertices = new ColorVertex[3];
	m_iCantVertices = 3;
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

}
//----------------------------------------------------------------
Triangle::~Triangle ()
{
	delete m_pkVertices;
	m_pkVertices = NULL;
}
//----------------------------------------------------------------
void Triangle::draw (Renderer * rkRenderer)
{
	Shape::draw(rkRenderer);
	rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_STRIP, m_iCantVertices);
}
//----------------------------------------------------------------