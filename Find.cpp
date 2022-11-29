#include "Find.h"
#include <fstream>
#include <string.h>
#include <cctype>
#include <sstream>
#include <iostream>

using namespace std;

void Find()
{
	const int Max = 1000;
	char Comment[Max] = "";
	char Word[Max];
	
	ifstream fin;

	fin.open("Data.txt");

	while (!fin.eof())
	{
		fin.getline(Comment, Max);
	}

	fin.close();

	double CountOfWords = 0;
	double CountOfBadWords = 0;
	double PercentOfBadWords;

	for (int i = 0; i < strlen(Comment); i++)
		if (Comment[i] == ' ') CountOfWords++;

	CountOfWords++;

	ifstream DataWithBadWords;

	DataWithBadWords.open("BadWordsBase.txt");

	char *num;
	int place;
	int wordsize;

	while (!DataWithBadWords.eof())
	{
		DataWithBadWords.getline(Word, Max);

		num = strstr(Comment, Word);

		if (num != nullptr)
		{
			place = strlen(Comment) - strlen(num);
			wordsize = strlen(Word);
			  
				for (int i = place; i < wordsize+place; i++)
					Comment[i] = '*';

				CountOfBadWords++;
		}
		
		Word[0] = '\0';

	}

	PercentOfBadWords = CountOfBadWords / CountOfWords * 100;;

	ofstream fout;

	fout.open("Answer.txt");

	

	fout << "Text after checking: " << Comment << endl
		<< "Total count of words in your text: " << CountOfWords << endl
		<< "Count of Bad words in your text: " << CountOfBadWords << endl
		<< "Percent of Bad words in your text: " << PercentOfBadWords << "%";

	fout.close();
  
}
