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
class Sound
{
public:
	Sound();
	~Sound();

	bool startSoundEngine();
	bool stopSoundEngine();

	bool playSound(string kFileName, bool bLoop=false);

protected:
	SoundEngine m_pkSoundEngine;
};
//---------------------------------------------------------------- 
#endif //SOUND_H
//---------------------------------------------------------------- 

