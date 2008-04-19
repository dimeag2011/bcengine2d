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

	m_iNumCaras = 149;
	m_fRadio = 1;

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

		case CIRCLE:
			m_pkVertices = new ColorVertex[m_iNumCaras + 2];
			//seteo el centro
			pkV = &(m_pkVertices[0]);
			pkV->x = 0.0f;	pkV->y = 0.0f;	pkV->z = 1.0f;
			pkV->color = D3DCOLOR_XRGB(255,0,0);

			for(int i=1; i<=m_iNumCaras+1; i++)
			{
				double dAngle = (360.0 / m_iNumCaras) * i;

				double dPiOver180 = 3.141592654f / 180.0;
				double dAngSin = sin(dAngle * dPiOver180);
				double dAngCos = cos(dAngle * dPiOver180);

				//* 3.14159f / 180.0f
				pkV = &(m_pkVertices[i]);
				pkV->x = (float)(dAngSin * m_fRadio);
				pkV->y = (float)(dAngCos * m_fRadio);
				pkV->z = 1.0f;
				pkV->color = D3DCOLOR_XRGB(255,0,0);
			}
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
		case CIRCLE:
			rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_FAN, m_iNumCaras+2);
			break;
	}
}
//----------------------------------------------------------------