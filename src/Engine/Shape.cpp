//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
Shape::Shape (SHAPE_TYPE eShapeType)
:
Entity2D()
{
	m_eShapeType = eShapeType;

	ColorVertex* pkV;

	switch(m_eShapeType)
	{
		case TRIANGLE:
			m_pkVertices = new ColorVertex[3];
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

			break;

		case BOX:
			m_pkVertices = new ColorVertex[4];
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

			break;

	};
}
//----------------------------------------------------------------
void Shape::draw (Renderer * rkRenderer)
{
	Entity2D::draw(rkRenderer);
	//rkRenderer.unbindTexture();
	switch(m_eShapeType)
	{
		case TRIANGLE:
			rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_STRIP, 3);
			break;
		case BOX:
			rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_STRIP, 4);
			break;
	}
}
//----------------------------------------------------------------