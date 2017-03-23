#include "audio.h"

Sound::Sound()
{
	if (FMOD::System_Create(&system) != FMOD_OK)
	{
		printf("Error!\n");
	}
	else
	{
		int driverCount = 0;
		result = system->getNumDrivers(&driverCount);
		result = system->init(36, FMOD_INIT_NORMAL, NULL);
	}
}

void Sound::releaseSound(FMOD::Sound *pSound)
{
	pSound->release();
}

void Sound::createSound(FMOD::Sound** _audio, std::string fileName)
{
	const char* sFile = fileName.c_str();
	result = system->createSound(sFile, FMOD_DEFAULT, 0, _audio);
}

void Sound::createStream(FMOD::Sound **_stream, std::string fileName)
{
	std::string pPath = "..//assets//music//";
	pPath.append(fileName);
	const char* sFile = pPath.c_str();
	result = system->createStream(sFile, FMOD_LOOP_NORMAL, 0, _stream);
}


void Sound::playSound(FMOD::Sound* _audio, FMOD::Channel* _channel, bool pause, bool loop) // set pause bool to true in order to pause, all you need is this function
{
	result = system->playSound(_audio, NULL, pause, &_channel);

	if (result != FMOD_OK)
	{
		printf("Error within playSound func.");
	}
	
	if (pause == true)
	{
		result = _channel->setPaused(pause);
	}

	if (loop == false)
	{
		result = _audio->setMode(FMOD_LOOP_OFF);
	}

	else if (loop == true)
	{
		result = _audio->setMode(FMOD_LOOP_NORMAL);
		result = _audio->setLoopCount(-1);
	}
}