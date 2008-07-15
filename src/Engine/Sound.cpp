#include "Sound.h"
//---------------------------------------------------------------- 
Sound::Sound():
m_pkSoundEngine(NULL)
{

}
//---------------------------------------------------------------- 
Sound::~Sound()
{

}
//---------------------------------------------------------------- 
bool Sound::startSoundEngine()
{
	m_pkSoundEngine = irrklang::createIrrKlangDevice();

	if (!m_pkSoundEngine)
		return false;

	return true;
}
//---------------------------------------------------------------- 
bool Sound::stopSoundEngine()
{
	m_pkSoundEngine->drop();

	return true;
}
//---------------------------------------------------------------- 
bool Sound::playSoundFile(string kFileName, bool bLoop)
{
	if (kFileName=="")
		return false;

	m_pkSoundEngine->play2D(kFileName.c_str(), bLoop);

	return true;
}
//---------------------------------------------------------------- 
void Sound::stopAllSounds()
{
	m_pkSoundEngine->stopAllSounds();
}
//---------------------------------------------------------------- 
void Sound::setMasterVolume(float fVolume)
{
	if (fVolume >= 0.0f && fVolume <=1.0f)
		m_pkSoundEngine->setSoundVolume(fVolume);
}
//---------------------------------------------------------------- 
float Sound::getMasterVolume()
{
	return m_pkSoundEngine->getSoundVolume();
}
//---------------------------------------------------------------- 
void Sound::pauseAllSounds(bool bPause)
{
	m_pkSoundEngine->setAllSoundsPaused(bPause);	
}
//----------------------------------------------------------------