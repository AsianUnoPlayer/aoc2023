#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int final_output = 0;
string vocab[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

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

	final_output += number;
	//cout << "Line is: " << number << endl;

}

int main()
{
	ifstream input_file;
	string text;
	input_file.open("input.txt");

	while (getline(input_file, text)) {
		int number;
		string lineOutput;

		for (int x = 0; x < sizeof(vocab)/sizeof(vocab[0]); x++) {
			//text.find(vocab[x])
			//text.find(vocab[x], 0)
			if (text.find(vocab[x], 0) != -1) {
				cout << vocab[x] << " ";
			}
		}
		cout << endl;
	}

	cout << "Final Output is: " << final_output << endl;

	return 0;
}
