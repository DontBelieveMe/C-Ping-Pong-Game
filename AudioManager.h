#pragma once
#include<SFML\Audio.hpp>
#include<stdexcept>
#include<iostream>

namespace blesbok
{
	class AudioManager
	{
	private:
		sf::SoundBuffer b_hit_wall;
		sf::Sound sfx_hit_wall;

		sf::SoundBuffer b_hit_player;
		sf::Sound sfx_hit_player;

	public:
		AudioManager();
		~AudioManager();

		void load_sound(const std::string& path);

		void play_hit_wall() { sfx_hit_wall.play(); }
		void play_hit_player() { sfx_hit_player.play(); }
	};
};

