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
	pkV->x = -0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);
	
	pkV = &(m_akVertices[1]);
	pkV->x = -0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_akVertices[2]);
	pkV->x = 0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);

	pkV = &(m_akVertices[3]);
	pkV->x = 0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(255,0,0);

	setDim(100,100);
}
//----------------------------------------------------------------
void Shape::draw (Renderer * rkRenderer)
{
	Entity2D::draw(rkRenderer);
	//rkRenderer.unbindTexture();
	rkRenderer->Draw(m_akVertices, Renderer::TRIANGLE_STRIP, 4);
}
//----------------------------------------------------------------