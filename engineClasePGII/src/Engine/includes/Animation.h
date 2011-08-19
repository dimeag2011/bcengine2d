#ifndef ANIMATION_H
#define ANIMATION_H
//----------------------------------------------------------------
#include "Defines.h"
#include "AnimationInfo.h"
//----------------------------------------------------------------
class ENGINE_API Animation
{
// constructor / destructor
public:
	Animation (AnimationInfo::Ptr pkInfo);
	~Animation ();

// playback
public:
	void play ();
	void stop ();

// accessors
public:
	enum PlayState
	{
		STOP,
		PLAY,
		PAUSE
	};

	PlayState getState () const;
	const AnimationInfo::Ptr getInfo () const;
	unsigned int getCurrentFrame () const;

// update functions
public:
	void update (float fTimeBetweenFrames);

// properties
private:
	AnimationInfo::Ptr m_pkInfo;

	PlayState m_eCurrentState;

	unsigned int m_uiCurrentFrame;
	float m_fCurrentFrameTime;
};
//----------------------------------------------------------------
#include "Animation.inl"
//----------------------------------------------------------------
#endif // ANIMATION_H
//----------------------------------------------------------------