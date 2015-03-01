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

		sf::SoundBuffer b_won_point;
		sf::Sound sfx_won_point;

	public:
		AudioManager();
		~AudioManager();

		void load_sound(const std::string& path);

		void play_hit_wall() { sfx_hit_wall.play(); }
		void play_hit_player() { sfx_hit_player.play(); }
		void play_gain_point() { sfx_won_point.play(); }
	};
};

