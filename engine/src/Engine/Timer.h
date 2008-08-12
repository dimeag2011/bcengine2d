#ifndef TIMER_H
#define TIMER_H
//--------------------------------------------------------------------------------
#include "Defines.h"
//--------------------------------------------------------------------------------
class Timer
{
friend class Game;

public:
	Timer();
	~Timer();

	unsigned int GetFPS();
	float GetDT();

private:
	void FirstMeasure();
	void Measure();

	LARGE_INTEGER m_kFrequency;
	LARGE_INTEGER m_kActualTime;
	LARGE_INTEGER m_kLastTime;

	double m_dDT;
	double m_dMeasureFpsSample;
	unsigned int m_uiFrameCounter;
	unsigned int m_uiFPS;
};
//--------------------------------------------------------------------------------
#endif //TIMER_H 