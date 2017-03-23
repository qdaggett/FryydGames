#ifndef AUDIO_H
#define AUDIO_H

#include "FMOD\fmod.hpp"
#include "FMOD\fmod_errors.h"
#include <string>
#include <stddef.h>
#include <iostream>

class Sound {
private:

	FMOD::System *system;
	FMOD_RESULT result;
	FMOD_SYSTEM *fmodsystem;
	FMOD_SOUND *sound;
	FMOD_CHANNEL **channel;

	FMOD_SPEAKERMODE speaker_mode;
	unsigned int version;

public:
	Sound();
	void releaseSound(FMOD::Sound *pSound);
	void createSound(FMOD::Sound** _audio, std::string fileName);
	void createStream(FMOD::Sound **_stream, std::string fileName);
	void playSound(FMOD::Sound* _audio, FMOD::Channel* _channel, bool pause, bool loop);
};
#endif