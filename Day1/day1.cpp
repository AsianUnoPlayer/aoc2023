#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int final_number = 0, final_output = 0;
string vocab[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void PartOne(string text)
{
	int number;
	string lineNumber;

	for (int x = 0; x < text.length(); x++) {
		if (isdigit(text[x])) {
			lineNumber += text[x];
		}
	}
		
	if (lineNumber.length() > 2) {
		lineNumber.erase(lineNumber.begin()+1, lineNumber.end()-1);
	}
	else if (lineNumber.length() == 1) {
		lineNumber += lineNumber[0];
	}
	number = stoi(lineNumber);

	final_number += number;

}

void PartTwo(string text)
{
	int number;
	string lineOutput;

	map<int, string> numberValues;

	for (int x = 0; x < sizeof(vocab)/sizeof(vocab[0]); x++) {
		int currentPos = text.find(vocab[x]);

		if (currentPos != -1) {
			int newPos = text.rfind(vocab[x]);

			if (newPos != -1 && newPos > currentPos) {
				currentPos = newPos;
			}

			if (x <= 8) {
				numberValues.insert({currentPos, vocab[x+9]});
			}
			else {
				numberValues.insert({currentPos, vocab[x]});
			}
		}
	}

	lineOutput += numberValues.begin()->second;
	auto it = numberValues.end(); it--;
	lineOutput += it->second;

	number = stoi(lineOutput);
	final_output += number;
	numberValues.clear();
}

int main()
{
	ifstream input_file;
	string text;
	input_file.open("input.txt");

	while (getline(input_file, text)) {
		PartOne(text);
		PartTwo(text);
	}

	cout << "PartOne is: " << final_number << endl;
	cout << "PartTwo is: " << final_output << endl;

	return 0;
}
