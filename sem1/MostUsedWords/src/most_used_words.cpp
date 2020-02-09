#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>


struct word_stat
{
	int count;
	std::string word;
};

void prepare(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	while (std::ispunct(s.back()))
		s.pop_back();

	// Remove 's (e.g. translator's)
	int len = s.size();
	if (s.size() > 2)
	{
		if (s[len-2] == '\'')
		{
			s.pop_back();
			s.pop_back();
		}
	}
}

int compare_words(const word_stat& w1, const word_stat& w2)
{
	return (w1.count > w2.count);
}


int main()
{
	int n = 0;
	std::cin >> n;

	std::ifstream file("/home/michael/developing/code/4sem/test-project/src/input.txt");
	std::map<std::string, int> words;

	if (file.is_open())
	{
		std::string word;
		while (!file.eof())
		{
			file >> word;
			prepare(word);

			if (words.find(word) != words.end())
				words[word] += 1;
			else
			{
				if (!word.empty())
					words.insert(std::pair<std::string, int>(word, 1));
			}
		}

		file.close();

		int i = 0;
		std::vector<word_stat> data(words.size());
		for (auto& [word, count]: words)
		{
			data[i].count = count;
			data[i].word = word;
			i++;
		}

		std::sort(data.begin(), data.end(), compare_words);

		int size = data.size();
		for (int i = 0; i < std::min(n, size); i++)
			std::cout << data[i].word << " " << data[i].count << std::endl;
	}
	else
		std::cout << "Error opening file.." << std::endl;

	return 0;
}
