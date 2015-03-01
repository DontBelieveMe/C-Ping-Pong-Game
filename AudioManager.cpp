#include "AudioManager.h"

/*
Loads in all the sounds and sets them to their appropriate buffers
*/
blesbok::AudioManager::AudioManager()
{
	if (!b_hit_wall.loadFromFile("hitWall.wav"))
	{
		std::cerr << "Error loading hitWall.wav" << std::endl;
		throw std::runtime_error("Error loading hitWall.wav");
	}
	sfx_hit_wall.setBuffer(b_hit_wall);

	if (!b_hit_player.loadFromFile("hitPlayer.wav"))
	{
		std::cerr << "Error loading hitPlayer.wav" << std::endl;
		throw std::runtime_error("Error loading hitPlayer.wav");
	}
	sfx_hit_player.setBuffer(b_hit_player);

	if (!b_won_point.loadFromFile("point_gain.wav"))
	{
		std::cerr << "Error loading point_gain.wav" << std::endl;
		throw std::runtime_error("Error loading point_gain.wav");
	}
	sfx_won_point.setBuffer(b_won_point);
}


blesbok::AudioManager::~AudioManager()
{
}

