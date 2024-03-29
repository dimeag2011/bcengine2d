//----------------------------------------------------------------
#include "includes\Circle.h"
//----------------------------------------------------------------
Circle::Circle (int iNumCaras)
:
Shape()
{
	setNumeroCaras(iNumCaras);
}
//----------------------------------------------------------------
void Circle::draw (Renderer * rkRenderer)
{
	Shape::draw(rkRenderer);
	rkRenderer->Draw(m_pkVertices, Renderer::TRIANGLE_FAN, m_iCantVertices);
}
//----------------------------------------------------------------
int Circle::getNumeroCaras()
{
	return m_iNumCaras;
}
//----------------------------------------------------------------
void Circle::setNumeroCaras(int iNumCaras)
{
	int iRed = 255;
	int iGreen = 0;
	int iBlue = 0;

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
	if (m_pkVertices)
	{
		getColor(iRed, iGreen, iBlue);
		delete [] m_pkVertices;
	}
	m_pkVertices = new ColorVertex[m_iNumCaras + 2];
	m_iCantVertices = m_iNumCaras + 2;
	//seteo el centro
	pkV = &(m_pkVertices[0]);
	pkV->x = 0.0f;	pkV->y = 0.0f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(iRed, iGreen, iBlue);

	for(int i=1; i<=m_iNumCaras+1; i++)
	{
		double dAngle = (360.0 / m_iNumCaras) * i;

		double dPiOver180 = 3.141592654f / 180.0;
		double dAngSin = sin(dAngle * dPiOver180);
		double dAngCos = cos(dAngle * dPiOver180);

		//* 3.14159f / 180.0f
		pkV = &(m_pkVertices[i]);
		pkV->x = (float)(dAngSin) * 0.5f;
		pkV->y = (float)(dAngCos) * 0.5f;
		pkV->z = 1.0f;
		pkV->color = D3DCOLOR_XRGB(iRed, iGreen, iBlue);
	}
	
	Entity2D::setDim(getDimW(), getDimH(), false);
}
//----------------------------------------------------------------

void Circle::setDim (float fW, float fH)
{
	Entity2D::setDim(fW , fH , false);
	setBBDim(fW, fH);
}

