//////////////////////////////////
/*
*		- Code Commentor -
*		 by Kyle Grenier
*		    8/30/2021
*
* ABOUT:
*		 Adds comments before keywords to scripts. 
*		 Created to automatically comment out Debug.Log() and
*		 print() statements in my Unity C# scripts.
*/
/////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void populateKeywords(ifstream & keywordsFile, vector<string> & keywordsVector);
void addComments(ifstream & inputFile, ofstream & outputFile, const vector<string> & keywords);
int main()
{
	const string INFILE_NAME{ "Attacker.txt" };
	const string OUTFILE_NAME{ "Output.txt" };
	const string KEYWORDS_NAME{ "keywords.txt" };

	// Vector of keywords
	vector<string> keywords;

	// Opening files
	ifstream inputFile;
	inputFile.open(INFILE_NAME);
	if (!inputFile)
	{
		cerr << "Could not open file '" << INFILE_NAME << "." << endl;
		system("pause");
		return 1;
	}
	ofstream outputFile;
	outputFile.open(OUTFILE_NAME);

	ifstream keywordsFile;
	keywordsFile.open(KEYWORDS_NAME);

	// Populating our keywords vector
	populateKeywords(keywordsFile, keywords);

	// Finding keywords
	addComments(inputFile, outputFile, keywords);

	// Closing files
	outputFile.close();
	inputFile.close();

	system("pause");
	return 0;
}

// Populates a vector of keywords from a .txt file of keywords.
void populateKeywords(ifstream & keywordsFile, vector<string> & keywordsVector)
{
	keywordsFile.seekg(0);
	while (!keywordsFile.eof())
	{
		string keyword;
		getline(keywordsFile, keyword);

		keywordsVector.push_back(keyword);
	}
}

// Adds comments ("//") to the inputFile right before a keyword is found.
void addComments(ifstream & inputFile, ofstream & outputFile, const vector<string> & keywords)
{
	inputFile.seekg(0);
	outputFile.seekp(0);
	int lineNum{};
	while (!inputFile.eof())
	{
		++lineNum;

		string line;
		getline(inputFile, line);

		// If we find our keyword, add "//" to the line before
		// we print it to our outputFile.
		for (size_t i{}; i < keywords.size(); ++i)
		{
			size_t charPos{ line.find(keywords[i]) };
			if (charPos != string::npos)
			{
				cout << "Found keyword '" << keywords[i] << "' on line " << lineNum << ", char position " << charPos << endl;

				string commentedLine;
				for (size_t j{}; j < line.length(); ++j)
				{
					// Insert the comment once we're at the correct position.
					if (j == charPos)
						commentedLine += "//";

					commentedLine += line[j];
				}

				outputFile << commentedLine << endl;
				break; // Break out once we found a keyword, since we don't want to mess things up by
					   // adding mulitple comments per line.
			}
			else if (i == keywords.size() - 1)
				outputFile << line << endl;
		}
	}
}