#include "AudioManager.h"


blesbok::AudioManager::AudioManager()
{
	if (!b_hit_wall.loadFromFile("hitWall.wav")) throw std::runtime_error("Error loading hitWall.wav");
	sfx_hit_wall.setBuffer(b_hit_wall);

	if (!b_hit_player.loadFromFile("hitPlayer.wav")) throw std::runtime_error("Error loading hitPlayer.wav");
	sfx_hit_player.setBuffer(b_hit_player);
}


blesbok::AudioManager::~AudioManager()
{
}

