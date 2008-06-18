//----------------------------------------------------------------
#include "Sprite.h"
#include "Renderer.h"
#include "Texture.h"
//----------------------------------------------------------------
Sprite::Sprite ()
:
Entity2D(),
m_pkCurrentAnim(NULL)
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
void Sprite::update (float fTimeBetweenFrames)
{
	Entity2D::update(fTimeBetweenFrames);

	// update the animations
	if(m_pkCurrentAnim)
	{
		m_pkCurrentAnim->update(fTimeBetweenFrames);

		unsigned int uiCurrentFrame = m_pkCurrentAnim->getCurrentFrame();
		const FrameInfo& kInfo = m_pkCurrentAnim->getInfo()->getFrameInfo(uiCurrentFrame);

		// update sprite
		setTextureArea(kInfo.uiOffsetX, kInfo.uiOffsetY,
						kInfo.uiWidth, kInfo.uiHeight);
	}

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
bool Sprite::addAnimationInfo (std::string kName, AnimationInfo::Ptr pkInfo)
{
	// get the animation
	AnimationInfo::Ptr pkAnimInfo = m_kAnimationMap[kName];

	// if the animation with that name already exists, return
	if( pkAnimInfo.get() )
		return false;

	// add it to the entity
	m_kAnimationMap[kName] = pkInfo;

	return true;
}
//----------------------------------------------------------------
bool Sprite::removeAnimationInfo (std::string kName)
{
	// get the animation
	AnimationInfo::Ptr pkAnimInfo = m_kAnimationMap[kName];

	// if the animation with that name does not exist, return
	if( !pkAnimInfo.get() )
		return false;

 	// delete the animation
	m_kAnimationMap.erase(kName);

	return false;
}
//----------------------------------------------------------------
void Sprite::clone (Sprite* rkSprite)
{
	// check for clone to self
	if(rkSprite == this)
		return;

	// increment smart pointers references
	rkSprite->m_pkTexture = m_pkTexture;
	rkSprite->m_kAnimationMap = m_kAnimationMap;

	// copy vertices
	for(unsigned int i=0; i<4; i++)
		rkSprite->m_akVertices[i] = m_akVertices[i];
}
//----------------------------------------------------------------
void Sprite::onCollision (Entity2D* pkEntity)
{

}

