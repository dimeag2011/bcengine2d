//--------------------------------------------------------------------------------
#include "includes\Timer.h"
//--------------------------------------------------------------------------------
Timer::Timer()
{
	m_dDT = 0;
	m_dMeasureFpsSample = 0;
	m_uiFrameCounter = 0;
	m_uiFPS = 0;
}
Timer::~Timer()
{

}
unsigned int Timer::GetFPS()
{
	return m_uiFPS;
}
float Timer::GetDT()
{
	return ((float)(m_dDT));
}
void Timer::FirstMeasure()
{
	QueryPerformanceFrequency(&m_kFrequency);
	QueryPerformanceCounter(&m_kLastTime);
}
void Timer::Measure()
{
	// realizo la medicion del frame actual
	QueryPerformanceCounter(&m_kActualTime);

	// calculo el tiempo actual en milisegundos
	m_dDT = static_cast<double>
			((m_kActualTime.QuadPart - m_kLastTime.QuadPart)
			* 1000.0f / m_kFrequency.QuadPart);

	// tomo el estado del tiempo actual
	m_kLastTime = m_kActualTime;

	// actualizo el estado de los frames por segundo
	m_uiFrameCounter++;
	m_dMeasureFpsSample += m_dDT;

	if(m_dMeasureFpsSample >= 1000)
	{
		m_dMeasureFpsSample -= 1000;
		m_uiFPS = m_uiFrameCounter;
		m_uiFrameCounter = 0;
	}

	// Comentario para probar SVN
}
