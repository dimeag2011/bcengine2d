#ifndef SOUND_H
#define SOUND_H
//---------------------------------------------------------------- 
// irrKlang specific instructions
#include <irrKlang/include/irrKlang.h>
#pragma comment(lib, "../../ext/irrKlang/lib/irrKlang.lib") // link with irrKlang.dll
using namespace irrklang;
typedef ISoundEngine* SoundEngine;
//---------------------------------------------------------------- 
#include "Defines.h"
//---------------------------------------------------------------- 
class ENGINE_API Sound
{
public:
	Sound();
	~Sound();

	bool startSoundEngine();
	bool stopSoundEngine();

	bool playSoundFile(string kFileName, bool bLoop=false);
	void stopAllSounds();

	void pauseAllSounds(bool bPause);

	void setMasterVolume(float fVolume);
	float getMasterVolume();

protected:
	SoundEngine m_pkSoundEngine;
};
//---------------------------------------------------------------- 
#endif //SOUND_H
//---------------------------------------------------------------- 

