//----------------------------------------------------------------
#include "Circle.h"
//----------------------------------------------------------------
Circle::Circle (int iNumCaras)
:
Shape()
{
	if (iNumCaras > 145)
	{
		m_iNumCaras = 145;
	}
	else
	{
		m_iNumCaras = iNumCaras;
	}
	ColorVertex* pkV;
	// set the vertex values
	m_pkVertices = new ColorVertex[m_iNumCaras + 2];
	m_iCantVertices = m_iNumCaras + 2;
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
		pkV->x = (float)(dAngSin);
		pkV->y = (float)(dAngCos);
		pkV->z = 1.0f;
		pkV->color = D3DCOLOR_XRGB(255,0,0);
	}
}
//----------------------------------------------------------------
void Circle::draw (Renderer * rkRenderer)
{
	Shape::draw(rkRenderer);
	rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_FAN, m_iCantVertices);
}
//----------------------------------------------------------------