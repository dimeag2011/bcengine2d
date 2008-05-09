//----------------------------------------------------------------
#include "Sprite.h"
#include "Renderer.h"
#include "Texture.h"
//----------------------------------------------------------------
Sprite::Sprite ()
:
Entity2D(),
m_pkTexture(NULL)
{
	// set the vertex values
	TextureVertex* pkV = &(m_akVertices[0]);
	pkV->X = -0.5f;	pkV->Y = -0.5f;	pkV->Z = 1.0f;
	pkV->U = 0.0f;	pkV->V = 1.0f;
	
	pkV = &(m_akVertices[1]);
	pkV->X = -0.5f;	pkV->Y = 0.5f;	pkV->Z = 1.0f;
	pkV->U = 0.0f;	pkV->V = 0.0f;

	pkV = &(m_akVertices[2]);
	pkV->X = 0.5f;	pkV->Y = -0.5f;	pkV->Z = 1.0f;
	pkV->U = 1.0f;	pkV->V = 1.0f;

	pkV = &(m_akVertices[3]);
	pkV->X = 0.5f;	pkV->Y = 0.5f;	pkV->Z = 1.0f;
	pkV->U = 1.0f;	pkV->V = 0.0f;
}
//----------------------------------------------------------------
void Sprite::draw (Renderer* rkRenderer)
{
	assert(m_pkTexture);

	Entity2D::draw(rkRenderer);
	
	if(rkRenderer->bindTexture(m_pkTexture))
		rkRenderer->Draw(m_akVertices, Renderer::TRIANGLE_STRIP , 4);
	else
		assert(0);
}
//----------------------------------------------------------------
void Sprite::setTextureArea (unsigned int uiOffsetX, 
							unsigned int uiOffsetY, 
							unsigned int uiWidth, 
							unsigned int uiHeight)
{
	assert(m_pkTexture);

	float fTexWidth = static_cast<float>(m_pkTexture->getWidth());
	float fTexHeight = static_cast<float>(m_pkTexture->getHeight());
	
	// calculate the texture coordinates
	float fU1 = uiOffsetX / fTexWidth;
	float fU2 = (uiOffsetX + uiWidth) / fTexWidth;

	float fV1 = uiOffsetY / fTexHeight;
	float fV2 = (uiOffsetY + uiHeight) / fTexHeight;

	// update the vertices
	
	TextureVertex* pkV = &(m_akVertices[0]);
	pkV->U = fU1;	pkV->V = fV2;
	
	pkV = &(m_akVertices[1]);
	pkV->U = fU1;	pkV->V = fV1;

	pkV = &(m_akVertices[2]);
	pkV->U = fU2;	pkV->V = fV2;

	pkV = &(m_akVertices[3]);
	pkV->U = fU2;	pkV->V = fV1;
}
//----------------------------------------------------------------

//----------------------------------------------------------------