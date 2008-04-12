//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
Shape::Shape ()
:
Entity2D()
{
	// set the vertex values
	ColorVertex* pkV = &(m_akVertices[0]);
	pkV->X = -0.5f;	pkV->Y = -0.5f;	pkV->Z = 1.0f;
	pkV->Color = D3DCOLOR_XRGB(255,0,0);
	
	pkV = &(m_akVertices[1]);
	pkV->X = -0.5f;	pkV->Y = 0.5f;	pkV->Z = 1.0f;
	pkV->Color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_akVertices[2]);
	pkV->X = 0.5f;	pkV->Y = -0.5f;	pkV->Z = 1.0f;
	pkV->Color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_akVertices[3]);
	pkV->X = 0.5f;	pkV->Y = 0.5f;	pkV->Z = 1.0f;
	pkV->Color = D3DCOLOR_XRGB(255,0,0);
}
//----------------------------------------------------------------
void Shape::draw (Renderer& rkRenderer) const
{
	Entity2D::draw(rkRenderer);
	rkRenderer.unbindTexture();
	rkRenderer.draw(m_akVertices, Renderer::TRIANGLE_STRIP, 4);
}
//----------------------------------------------------------------