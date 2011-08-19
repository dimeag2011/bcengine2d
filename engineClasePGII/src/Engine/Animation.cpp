/*****************************************************************
 Naicigam Engine v0.1

 File: Animation.cpp
 Created: 23/04/08
*****************************************************************/

//----------------------------------------------------------------
#include "includes\Animation.h"
#include "includes\Sprite.h"
//----------------------------------------------------------------
Animation::Animation (AnimationInfo::Ptr pkInfo)
:
m_eCurrentState(STOP),
m_pkInfo(pkInfo),
m_uiCurrentFrame(0),
m_fCurrentFrameTime(0)
{
	/***/
}
//----------------------------------------------------------------
Animation::~Animation ()
{
	/***/
}
//----------------------------------------------------------------
void Animation::update (float fTimeBetweenFrames)
{
	assert( m_pkInfo.get() );

	// check if it is playing
	if(m_eCurrentState != PLAY)
		return;

	m_fCurrentFrameTime += fTimeBetweenFrames;

	// update frame time
	while(m_fCurrentFrameTime > m_pkInfo->getTimePerFrame() )
	{
		m_fCurrentFrameTime -= m_pkInfo->getTimePerFrame() * m_pkInfo->getSpeed();
		m_uiCurrentFrame++;

		if(m_uiCurrentFrame >= m_pkInfo->getFrameCount() )
		{
			m_uiCurrentFrame = 0;

			// if its not loopable, stop the animation
			if( !m_pkInfo->getLoopable() )
				stop();
		}
	}
}
//----------------------------------------------------------------
void Animation::stop ()
{
	m_eCurrentState = STOP;
}
//----------------------------------------------------------------
void Animation::play ()
{
	m_eCurrentState = PLAY;

	// reset the animation state if the animation was stopped
	if(m_eCurrentState == STOP)
	{
		m_uiCurrentFrame = 0;
		m_fCurrentFrameTime = 0.0f;
	}
}
//----------------------------------------------------------------