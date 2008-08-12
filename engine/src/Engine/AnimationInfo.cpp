#include "AnimationInfo.h"
#include "Sprite.h"
//----------------------------------------------------------------
void AnimationInfo::addFrame (unsigned int uiOffsetX, 
							unsigned int uiOffsetY, 
							unsigned int uiWidth, 
							unsigned int uiHeight)
{
	// build the info
	FrameInfo kInfo;
	kInfo.uiOffsetX = uiOffsetX;
	kInfo.uiOffsetY = uiOffsetY;
	kInfo.uiWidth = uiWidth;
	kInfo.uiHeight = uiHeight;

	// add it to the array
	m_akFramesInfo.push_back(kInfo);

	// update properties
	m_fTimePerFrame = m_fLength / getFrameCount();
}
//----------------------------------------------------------------