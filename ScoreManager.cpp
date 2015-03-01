#include "ScoreManager.h"
#include<iostream>
#include<stdexcept>

/*
WIP Class
*/

blesbok::ScoreManager::ScoreManager()
{
}


blesbok::ScoreManager::~ScoreManager()
{
	high_scores_file.close();
}

void blesbok::ScoreManager::append(const std::string& content)
{
	high_scores_file.open("high_scores.txt", ofstream::app);
	if (high_scores_file.is_open())
	{
		high_scores_file << content.c_str() << '\n';
	}
	else
	{
		std::cerr << "Error loading/opening high_scores file" << std::endl;
		throw std::runtime_error("Error loading/opening high scores file!");
	}
	high_scores_file.close();
}

void blesbok::ScoreManager::sort_scores()
{
}

