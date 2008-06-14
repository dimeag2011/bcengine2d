//----------------------------------------------------------------
#include "Entity2D.h"
#include "Renderer.h"
//----------------------------------------------------------------
Entity2D::Entity2D ()
:
m_kName(""),
m_fX(0), 
m_fY(0), 
m_fW(0),
m_fH(0),
m_fBBX(0), 
m_fBBY(0), 
m_fBBW(0),
m_fBBH(0),
m_fRotation(0),
m_bisMoving(false),
m_fSpeed(0),
m_fAngle(0),
m_fAngleRad(0),
m_fPrevX(0), 
m_fPrevY(0),
m_bAtachedBB(true)
{
	/***/
	// initialize AABB vertices
	ColorVertex* pkV = &(m_akAABBVertices[0]);
	pkV->x = -0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(0,0,0);
	
	pkV = &(m_akAABBVertices[1]);
	pkV->x = -0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(0,0,0);

	pkV = &(m_akAABBVertices[2]);
	pkV->x = 0.5f;	pkV->y = 0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(0,0,0);	
	
	pkV = &(m_akAABBVertices[3]);
	pkV->x = 0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(0,0,0);

	pkV = &(m_akAABBVertices[4]);
	pkV->x = -0.5f;	pkV->y = -0.5f;	pkV->z = 1.0f;
	pkV->color = D3DCOLOR_XRGB(0,0,0);
}
//----------------------------------------------------------------
void Entity2D::draw (Renderer * rkRenderer)
{
	// set the world matrix
	rkRenderer->setMatrixMode(WORLD);
 
	// reset the matrix
	rkRenderer->loadIdentity();

	

	// apply transformation
	rkRenderer->translate(m_fX, m_fY);
	rkRenderer->rotateZ(m_fRotation * 3.14159f / 180.0f);
	rkRenderer->scale(m_fW, m_fH);
	// AABB
	rkRenderer->loadIdentity();
	rkRenderer->translate(m_fBBX, m_fBBY);
	rkRenderer->scale(m_fW, m_fH);
	rkRenderer->unbindTexture();
	rkRenderer->Draw(m_akAABBVertices, Renderer::LINE_STRIP, 5);
}
//----------------------------------------------------------------
//----------------------------------------------------------------
Entity2D::CollisionResult Entity2D::checkCollision(Entity2D* pkEntity) const
{
	float fAuxPosX = fabs(pkEntity->getPosX() - m_fX);
	float fAuxPosY = fabs(pkEntity->getPosY() - m_fY);

	float fAuxW = m_fW / 2.0f + pkEntity->getDimW() / 2.0f;
	float fAuxH = m_fH / 2.0f + pkEntity->getDimH() / 2.0f;

	if(fAuxPosX <= fAuxW && fAuxPosY <= fAuxH)
	{
		if(fAuxPosX + fAuxW < fAuxPosY + fAuxH)
			return Horizontal;
		else
			return Vertical;
	}

	return None;
}
//----------------------------------------------------------------