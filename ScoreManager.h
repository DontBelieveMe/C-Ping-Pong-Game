#pragma once
#include<fstream>
#include<vector>

using namespace std;

namespace blesbok
{
	class ScoreManager
	{
	private:
		ofstream high_scores_file;

	public:
		ScoreManager();
		~ScoreManager();

		void free() { high_scores_file.close(); }
		void append(const string& content);
		void sort_scores();
	};
};

