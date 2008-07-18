#ifndef ANIMATIONINFO_H
#define ANIMATIONINFO_H
//----------------------------------------------------------------
#include "Defines.h"
//----------------------------------------------------------------
class Sprite;
//----------------------------------------------------------------
struct FrameInfo
{
	unsigned int uiOffsetX;
	unsigned int uiOffsetY;
	unsigned int uiWidth;
	unsigned int uiHeight;
};
//----------------------------------------------------------------
class ENGINE_API AnimationInfo
{
	DECLARE_SMART_POINTER(AnimationInfo);

public:
	void addFrame (unsigned int uiOffsetX, 
						unsigned int uiOffsetY, 
						unsigned int uiWidth, 
						unsigned int uiHeight); 

// accesors

	void setLength (float fLenght);
	float getLength () const;

	void setSpeed (float fSpeed);
	float getSpeed () const;

	float getTimePerFrame () const;
	size_t getFrameCount () const;
	const FrameInfo& getFrameInfo (unsigned int uiIndex) const;

	void setLoopable (bool bIsLoopable);
	bool getLoopable () const;

// properties
private:
	float m_fLength;
	bool m_bIsLoopable;
	float m_fSpeed;
	vector<FrameInfo> m_akFramesInfo;
	float m_fTimePerFrame;
};
//----------------------------------------------------------------
#include "AnimationInfo.inl"
//----------------------------------------------------------------
#endif // ANIMATIONINFO_H
//----------------------------------------------------------------