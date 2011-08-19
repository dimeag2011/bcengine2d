//----------------------------------------------------------------
#include "includes\Shape.h"
#include "includes\Renderer.h"
//----------------------------------------------------------------
Shape::Shape ()
:
Entity2D(),
m_pkVertices(NULL)
{

}
//----------------------------------------------------------------
void Shape::draw (Renderer * rkRenderer)
{
	Entity2D::draw(rkRenderer);
	rkRenderer->unbindTexture();
}
//----------------------------------------------------------------
void Shape::update (float fTimeBetweenFrames)
{
	Entity2D::update(fTimeBetweenFrames);
}
//----------------------------------------------------------------
void Shape::getColor (int &iRed, int &iGreen, int &iBlue) const
{
	iRed = getR(m_pkVertices[0].color);
	iGreen = getG(m_pkVertices[0].color);
	iBlue = getB(m_pkVertices[0].color);
}
//----------------------------------------------------------------
void Shape::setColor (int iRed, int iGreen, int iBlue)
{
	for (int i=0; i < m_iCantVertices; i++)
	{
		m_pkVertices[i].color = D3DCOLOR_XRGB(iRed, iGreen, iBlue);
	}
}
//----------------------------------------------------------------
bool Shape::getVertexColor (int iVertex, int &iRed, int &iGreen, int &iBlue)
{
	if (iVertex >= m_iCantVertices)
	{
		return false;
	}

	iRed = getR(m_pkVertices[iVertex].color);
	iGreen = getG(m_pkVertices[iVertex].color);
	iBlue = getB(m_pkVertices[iVertex].color);

	return true;

}
//----------------------------------------------------------------
bool Shape::setVertexColor (int iVertex, int iRed, int iGreen, int iBlue)
{
	if (iVertex >= m_iCantVertices)
	{
		return false;
	}

	m_pkVertices[iVertex].color = D3DCOLOR_XRGB(iRed, iGreen, iBlue);

	return true;

}
//----------------------------------------------------------------
void Shape::onCollision (Entity2D* pkEntity)
{

}

