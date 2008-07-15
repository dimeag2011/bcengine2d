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
bool Sound::playSound(string kFileName, bool bLoop)
{
	if (kFileName=="")
		return false;

	m_pkSoundEngine->play2D(kFileName.c_str(), bLoop);

	return true;
}
//---------------------------------------------------------------- 
