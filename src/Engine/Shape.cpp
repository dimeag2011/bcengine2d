//----------------------------------------------------------------
#include "Shape.h"
#include "Renderer.h"
//----------------------------------------------------------------
Shape::Shape ()
:
Entity2D()
{

}
//----------------------------------------------------------------
void Shape::draw (Renderer * rkRenderer)
{
	Entity2D::draw(rkRenderer);
	//rkRenderer.unbindTexture();
}
//----------------------------------------------------------------
void Shape::getColor (int &iRed, int &iGreen, int &iBlue)
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
